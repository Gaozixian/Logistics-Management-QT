/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_N;
    QAction *action_O;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabOrders;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QTableView *ordersTableView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *orderIdLabel;
    QLabel *label_3;
    QLabel *customerNameLabel;
    QLabel *label_5;
    QLabel *destinationLabel;
    QLabel *label_7;
    QLabel *weightLabel;
    QLabel *label_9;
    QLabel *volumeLabel;
    QLabel *label_11;
    QLabel *statusLabel;
    QLabel *label_13;
    QLabel *createTimeLabel;
    QLabel *label_15;
    QLabel *updateTimeLabel;
    QWidget *tabNewOrder;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *customerNameEdit;
    QLabel *label_4;
    QLineEdit *destinationEdit;
    QLabel *label_6;
    QDoubleSpinBox *weightSpinBox;
    QLabel *label_8;
    QDoubleSpinBox *volumeSpinBox;
    QPushButton *addOrderButton;
    QWidget *tabActions;
    QVBoxLayout *verticalLayout_5;
    QPushButton *deleteOrderButton;
    QPushButton *updateStatusButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        action_N = new QAction(MainWindow);
        action_N->setObjectName("action_N");
        action_O = new QAction(MainWindow);
        action_O->setObjectName("action_O");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabOrders = new QWidget();
        tabOrders->setObjectName("tabOrders");
        verticalLayout_2 = new QVBoxLayout(tabOrders);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(tabOrders);
        groupBox->setObjectName("groupBox");
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        searchEdit = new QLineEdit(groupBox);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout->addWidget(searchEdit);

        searchButton = new QPushButton(groupBox);
        searchButton->setObjectName("searchButton");

        horizontalLayout->addWidget(searchButton);


        verticalLayout_3->addLayout(horizontalLayout);

        ordersTableView = new QTableView(groupBox);
        ordersTableView->setObjectName("ordersTableView");

        verticalLayout_3->addWidget(ordersTableView);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tabOrders);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox_2);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        orderIdLabel = new QLabel(groupBox_2);
        orderIdLabel->setObjectName("orderIdLabel");

        gridLayout->addWidget(orderIdLabel, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        customerNameLabel = new QLabel(groupBox_2);
        customerNameLabel->setObjectName("customerNameLabel");

        gridLayout->addWidget(customerNameLabel, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        destinationLabel = new QLabel(groupBox_2);
        destinationLabel->setObjectName("destinationLabel");

        gridLayout->addWidget(destinationLabel, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        weightLabel = new QLabel(groupBox_2);
        weightLabel->setObjectName("weightLabel");

        gridLayout->addWidget(weightLabel, 3, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        volumeLabel = new QLabel(groupBox_2);
        volumeLabel->setObjectName("volumeLabel");

        gridLayout->addWidget(volumeLabel, 4, 1, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 5, 0, 1, 1);

        statusLabel = new QLabel(groupBox_2);
        statusLabel->setObjectName("statusLabel");

        gridLayout->addWidget(statusLabel, 5, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");

        gridLayout->addWidget(label_13, 6, 0, 1, 1);

        createTimeLabel = new QLabel(groupBox_2);
        createTimeLabel->setObjectName("createTimeLabel");

        gridLayout->addWidget(createTimeLabel, 6, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName("label_15");

        gridLayout->addWidget(label_15, 7, 0, 1, 1);

        updateTimeLabel = new QLabel(groupBox_2);
        updateTimeLabel->setObjectName("updateTimeLabel");

        gridLayout->addWidget(updateTimeLabel, 7, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        tabWidget->addTab(tabOrders, QString());
        tabNewOrder = new QWidget();
        tabNewOrder->setObjectName("tabNewOrder");
        verticalLayout_4 = new QVBoxLayout(tabNewOrder);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox_3 = new QGroupBox(tabNewOrder);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        customerNameEdit = new QLineEdit(groupBox_3);
        customerNameEdit->setObjectName("customerNameEdit");

        gridLayout_2->addWidget(customerNameEdit, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        destinationEdit = new QLineEdit(groupBox_3);
        destinationEdit->setObjectName("destinationEdit");

        gridLayout_2->addWidget(destinationEdit, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        weightSpinBox = new QDoubleSpinBox(groupBox_3);
        weightSpinBox->setObjectName("weightSpinBox");
        weightSpinBox->setMaximum(10000.000000000000000);

        gridLayout_2->addWidget(weightSpinBox, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        volumeSpinBox = new QDoubleSpinBox(groupBox_3);
        volumeSpinBox->setObjectName("volumeSpinBox");
        volumeSpinBox->setMaximum(100.000000000000000);

        gridLayout_2->addWidget(volumeSpinBox, 3, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_3);

        addOrderButton = new QPushButton(tabNewOrder);
        addOrderButton->setObjectName("addOrderButton");

        verticalLayout_4->addWidget(addOrderButton);

        tabWidget->addTab(tabNewOrder, QString());
        tabActions = new QWidget();
        tabActions->setObjectName("tabActions");
        verticalLayout_5 = new QVBoxLayout(tabActions);
        verticalLayout_5->setObjectName("verticalLayout_5");
        deleteOrderButton = new QPushButton(tabActions);
        deleteOrderButton->setObjectName("deleteOrderButton");

        verticalLayout_5->addWidget(deleteOrderButton);

        updateStatusButton = new QPushButton(tabActions);
        updateStatusButton->setObjectName("updateStatusButton");

        verticalLayout_5->addWidget(updateStatusButton);

        tabWidget->addTab(tabActions, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menuBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_N);
        menu->addAction(action_O);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\211\251\346\265\201\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        action_N->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
        action_O->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\345\210\227\350\241\250", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\345\256\242\346\210\267\345\220\215\343\200\201\347\233\256\347\232\204\345\234\260\346\210\226\350\256\242\345\215\225\345\217\267\346\220\234\347\264\242...", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\350\257\246\346\203\205", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\345\217\267:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\345\220\215\347\247\260:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\351\207\215\351\207\217:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\344\275\223\347\247\257:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\346\227\266\351\227\264:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260\346\227\266\351\227\264:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabOrders), QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\347\256\241\347\220\206", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\345\220\215\347\247\260:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\207\215\351\207\217(kg):", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\275\223\347\247\257(m\302\263):", nullptr));
        addOrderButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\256\242\345\215\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabNewOrder), QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\350\256\242\345\215\225", nullptr));
        deleteOrderButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\242\345\215\225", nullptr));
        updateStatusButton->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260\347\212\266\346\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabActions), QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\346\223\215\344\275\234", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
