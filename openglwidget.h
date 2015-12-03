#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include "gameplay.h"
#include "style.h"

#include <QOpenGLWidget>
#include <QPainter>
#include <QFontDatabase>
#include <QMouseEvent>

#include <QDebug>

class OpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

private:
    QTimer paintTimer;
    QPainter painter;
    Gameplay *gameplay;

    QPoint stretchCoords(QPointF point) const;
    /* zamienia współrzędne z zakresu [0..1] na
     * proporcjonalne współrzędne z ekranu */

    QPointF squeezeCoords(QPoint point) const;
    /* i odwrotnie */

    void paintNumber(Number n);

private slots:
    void paintGL();

public:
    OpenGLWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);
    ~OpenGLWidget();

    void mousePressEvent(QMouseEvent *event);
};

#endif // OPENGLWIDGET_H
