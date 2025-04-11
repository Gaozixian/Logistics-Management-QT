#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_searchButton_clicked();
    void on_addOrderButton_clicked();
    void on_deleteOrderButton_clicked();
    void on_updateStatusButton_clicked();
    void on_ordersTableView_clicked(const QModelIndex &index);
    void on_actionOpen_triggered();


private:
    Ui::MainWindow *ui;
    QStandardItemModel *ordersModel;
    void refreshOrderTable();
    void clearDetailLabels();
    QString currentDbPath;
};
#endif // MAINWINDOW_H
