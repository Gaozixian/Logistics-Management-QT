
QT += core gui widgets sql  # 必须包含这三个模块
CONFIG += c++11
TARGET = LogisticsSystem
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp \
           order.cpp

HEADERS += mainwindow.h \
           order.h

FORMS += mainwindow.ui
