#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    openGLWidget = new OpenGLWidget(this);
    openGLWidget->lower();

}

void MainWindow::resizeEvent(QResizeEvent *event) {
    openGLWidget->setGeometry(this->geometry());
}

MainWindow::~MainWindow(){

    delete ui;
    delete openGLWidget;
}
