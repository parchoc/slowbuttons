#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    foreach (QObject *object, ui->centralWidget->children()) {
        if(object->metaObject()->className() == QString("SlowButton"))
            object->setProperty("speed", arg1);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    foreach (QObject *object, ui->centralWidget->children()) {
        if(object->metaObject()->className() == QString("SlowButton"))
            object->setProperty("direction", index);
    }
}
