#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include "gameplay.h"

#include <QOpenGLWidget>
#include <QPainter>

#include <QDebug>

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

private:
    QTimer paintTimer;
    QPainter painter;
    Gameplay *gameplay;

    QPoint stretchCoords(QVector2D point) const;
    /* zamienia współrzędne z zakresu [0..1] na
     * proporcjonalne współrzędne z ekranu */

    void paintNumber(Number n);

private slots:
    void paintGL();

public:
    OpenGLWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);
    ~OpenGLWidget();

};

#endif // OPENGLWIDGET_H
