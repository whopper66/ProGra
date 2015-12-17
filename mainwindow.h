#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "openglwidget.h"

#include <QMainWindow>
#include <QTimer>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	OpenGLWidget *openGLWidget;
	Gameplay *gameplay;

private slots:
	void handleMenuButton();

protected:
	void resizeEvent(QResizeEvent *);
	void mousePressEvent(QMouseEvent *event);

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

};

#endif // MAINWINDOW_H
