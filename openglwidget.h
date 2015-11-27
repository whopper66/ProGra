#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QDebug>
#include <QOpenGLWidget>
#include <QPainter>
#include <QTimer>

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

private:
    QTimer timer;
    QPainter painter;

private slots:
    void paintGL();

public:
    OpenGLWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);

};

#endif // OPENGLWIDGET_H
