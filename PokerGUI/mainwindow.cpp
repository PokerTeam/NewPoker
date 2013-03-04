#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{    
    ui = new QDeclarativeView;
    ui->setSource(QUrl("qrc:/game.qml"));
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    setCentralWidget(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}
