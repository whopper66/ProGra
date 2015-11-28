#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include "gameplay.h"

#include <QOpenGLWidget>
#include <QPainter>

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

private:
    QTimer paintTimer;
    QPainter painter;
    Gameplay * gameplay;

private slots:
    void paintGL();

public:
    OpenGLWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);

};

#endif // OPENGLWIDGET_H
