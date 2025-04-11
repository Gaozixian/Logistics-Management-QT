#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDateTime>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化数据库
    // 替换原来的数据库初始化代码：
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("logistics_default.db");  // 默认数据库
    if (!db.open()) {
        // 如果默认数据库不存在，让用户选择
        on_actionOpen_triggered();
    } else {
        currentDbPath = "logistics.db";
        // 检查表结构
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS orders (...)");
    }
    // 在初始化数据库连接后添加：
    ui->menu->addAction("打开数据库", this, &MainWindow::on_actionOpen_triggered);
    // 创建订单表
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS orders ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "customer TEXT NOT NULL,"
               "destination TEXT NOT NULL,"
               "weight REAL DEFAULT 0,"
               "volume REAL DEFAULT 0,"
               "status TEXT DEFAULT '待发货',"
               "create_time TEXT DEFAULT CURRENT_TIMESTAMP,"
               "update_time TEXT DEFAULT CURRENT_TIMESTAMP)");

    // 初始化表格模型
    ordersModel = new QStandardItemModel(this);
    ordersModel->setHorizontalHeaderLabels({"ID", "客户", "目的地", "重量", "体积", "状态"});
    ui->ordersTableView->setModel(ordersModel);
    refreshOrderTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshOrderTable()
{
    ordersModel->removeRows(0, ordersModel->rowCount());

    QSqlQuery query("SELECT * FROM orders");
    while (query.next()) {
        QList<QStandardItem*> items;
        items << new QStandardItem(query.value("id").toString());
        items << new QStandardItem(query.value("customer").toString());
        items << new QStandardItem(query.value("destination").toString());
        items << new QStandardItem(QString::number(query.value("weight").toDouble()));
        items << new QStandardItem(QString::number(query.value("volume").toDouble()));
        items << new QStandardItem(query.value("status").toString());
        ordersModel->appendRow(items);
    }
}

void MainWindow::clearDetailLabels()
{
    ui->orderIdLabel->clear();
    ui->customerNameLabel->clear();
    ui->destinationLabel->clear();
    ui->weightLabel->clear();
    ui->volumeLabel->clear();
    ui->statusLabel->clear();
    ui->createTimeLabel->clear();
    ui->updateTimeLabel->clear();
}

void MainWindow::on_searchButton_clicked()
{
    QString keyword = ui->searchEdit->text().trimmed();
    if (keyword.isEmpty()) {
        refreshOrderTable();
        return;
    }

    ordersModel->removeRows(0, ordersModel->rowCount());
    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE "
                  "customer LIKE ? OR "
                  "destination LIKE ? OR "
                  "id = ?");
    query.addBindValue("%" + keyword + "%");
    query.addBindValue("%" + keyword + "%");
    query.addBindValue(keyword.toInt());

    if (query.exec()) {
        while (query.next()) {
            QList<QStandardItem*> items;
            items << new QStandardItem(query.value("id").toString());
            items << new QStandardItem(query.value("customer").toString());
            items << new QStandardItem(query.value("destination").toString());
            items << new QStandardItem(QString::number(query.value("weight").toDouble()));
            items << new QStandardItem(QString::number(query.value("volume").toDouble()));
            items << new QStandardItem(query.value("status").toString());
            ordersModel->appendRow(items);
        }
    }
}

void MainWindow::on_addOrderButton_clicked()
{
    QString customer = ui->customerNameEdit->text().trimmed();
    QString dest = ui->destinationEdit->text().trimmed();
    double weight = ui->weightSpinBox->value();
    double volume = ui->volumeSpinBox->value();

    if (customer.isEmpty() || dest.isEmpty()) {
        QMessageBox::warning(this, "警告", "客户名称和目的地不能为空");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO orders (customer, destination, weight, volume) "
                  "VALUES (?, ?, ?, ?)");
    query.addBindValue(customer);
    query.addBindValue(dest);
    query.addBindValue(weight);
    query.addBindValue(volume);

    if (query.exec()) {
        refreshOrderTable();
        ui->customerNameEdit->clear();
        ui->destinationEdit->clear();
        ui->weightSpinBox->setValue(0);
        ui->volumeSpinBox->setValue(0);
    } else {
        QMessageBox::critical(this, "错误", "添加订单失败: " + query.lastError().text());
    }
}

void MainWindow::on_ordersTableView_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;

    int row = index.row();
    QString id = ordersModel->item(row, 0)->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        ui->orderIdLabel->setText(query.value("id").toString());
        ui->customerNameLabel->setText(query.value("customer").toString());
        ui->destinationLabel->setText(query.value("destination").toString());
        ui->weightLabel->setText(QString::number(query.value("weight").toDouble()) + " kg");
        ui->volumeLabel->setText(QString::number(query.value("volume").toDouble()) + " m³");
        ui->statusLabel->setText(query.value("status").toString());
        ui->createTimeLabel->setText(query.value("create_time").toString());
        ui->updateTimeLabel->setText(query.value("update_time").toString());
    }
}

// void MainWindow::on_deleteOrderButton_clicked()
// {
//     QModelIndex index = ui->ordersTableView->currentIndex();
//     if (!index.isValid()) {
//         QMessageBox::warning(this, "警告", "请先选择要删除的订单");
//         return;
//     }

//     int row = index.row();
//     QString id = ordersModel->item(row, 0)->text();

//     QSqlQuery query;
//     query.prepare("DELETE FROM orders WHERE id = ?");
//     query.addBindValue(id);

//     if (query.exec()) {
//         refreshOrderTable();
//         clearDetailLabels();
//     } else {
//         QMessageBox::critical(this, "错误", "删除失败: " + query.lastError().text());
//     }
// }

void MainWindow::on_updateStatusButton_clicked()
{
    QModelIndex index = ui->ordersTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择要更新的订单");
        return;
    }

    int row = index.row();
    QString id = ordersModel->item(row, 0)->text();
    QString currentStatus = ordersModel->item(row, 5)->text();

    QString newStatus;
    if (currentStatus == "待发货") newStatus = "运输中";
    else if (currentStatus == "运输中") newStatus = "已送达";
    else newStatus = "待发货";

    QSqlQuery query;
    query.prepare("UPDATE orders SET status = ?, update_time = CURRENT_TIMESTAMP WHERE id = ?");
    query.addBindValue(newStatus);
    query.addBindValue(id);

    if (query.exec()) {
        refreshOrderTable();
        if (ui->orderIdLabel->text() == id) {
            ui->statusLabel->setText(newStatus);
            ui->updateTimeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        }
    } else {
        QMessageBox::critical(this, "错误", "状态更新失败: " + query.lastError().text());
    }
}

// 数据库处理的功能，打开新的数据库查看信息
void MainWindow::on_actionOpen_triggered()
{
    // 获取用户选择的数据库文件
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "打开数据库文件",
                                                    QDir::currentPath(),
                                                    "SQLite数据库文件 (*.db *.sqlite);;所有文件 (*.*)");

    if (fileName.isEmpty()) {
        return;
    }

    // 关闭现有数据库连接
    QSqlDatabase::database().close();

    // 建立新连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(fileName);

    if (!db.open()) {
        QMessageBox::critical(this, "错误", "无法打开数据库: " + db.lastError().text());
        return;
    }

    currentDbPath = fileName;
    this->setWindowTitle("物流管理系统 - " + QFileInfo(fileName).fileName());

    // 检查表结构
    if (!db.tables().contains("orders")) {
        QMessageBox::warning(this, "警告", "选择的数据库不包含订单表");
        return;
    }

    // 刷新显示
    refreshOrderTable();
    clearDetailLabels();

    QMessageBox::information(this, "成功", "数据库已加载");
}

//添加的删除功能 2024.2.4号
void MainWindow::on_deleteOrderButton_clicked()
{
    // 获取当前选中的行
    QModelIndex index = ui->ordersTableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请先选择要删除的订单");
        return;
    }

    // 获取订单ID和客户名
    int row = index.row();
    QString id = ordersModel->item(row, 0)->text();
    QString customer = ordersModel->item(row, 1)->text();

    // 确认对话框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认删除",
                                  "确定要删除客户 " + customer + " 的订单吗？",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes) {
        return;
    }

    // 执行删除
    QSqlQuery query;
    query.prepare("DELETE FROM orders WHERE id = ?");
    query.addBindValue(id);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            // 删除成功后的处理
            refreshOrderTable();

            // 如果删除的是当前显示的订单，清空详情
            if (ui->orderIdLabel->text() == id) {
                clearDetailLabels();
            }

            QMessageBox::information(this, "成功", "订单已删除");
        } else {
            QMessageBox::warning(this, "警告", "未找到要删除的订单");
        }
    } else {
        QMessageBox::critical(this, "错误", "删除失败: " + query.lastError().text());
    }
}
