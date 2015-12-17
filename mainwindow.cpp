#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow) {

	ui->setupUi(this);
	openGLWidget = new OpenGLWidget(this);
	openGLWidget->lower();
	connect(ui->menuButton, SIGNAL(released()), this, SLOT(handleMenuButton()));

	gameplay = openGLWidget->getGameplay();
}

void MainWindow::resizeEvent(QResizeEvent *) {
	openGLWidget->setGeometry(0, 0, this->width(), this->height());
}

MainWindow::~MainWindow() {
	delete ui;
	delete openGLWidget;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
	openGLWidget->mousePressEvent(event);
}

void MainWindow::handleMenuButton() {
	gameplay->iterateLevel();
}
