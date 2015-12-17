#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include "gameplay.h"
#include "style.h"

#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QPainter>
#include <QFontDatabase>
#include <QMouseEvent>

#include <QDebug>

const qreal CLICK_RADIUS = 0.03f;

class OpenGLWidget : public QOpenGLWidget {
	Q_OBJECT

private:
	QTimer paintTimer;
	QPainter painter;
    Gameplay *gameplay;

	QPoint stretchCoords(const QPointF &point) const;
	/* zamienia współrzędne z zakresu [0..1] na
     * proporcjonalne współrzędne z ekranu */

	QPointF squeezeCoords(const QPoint &point) const;
	/* i odwrotnie */

    int stretchRadius(const qreal r) const;

    void clearBg();
	void paintNumber(const Number &n);
    void paintTimeBar();

private slots:
	void paintGL();

public:
	OpenGLWidget(QWidget *parent = nullptr, Qt::WindowFlags f = 0);
	~OpenGLWidget();

	void mousePressEvent(QMouseEvent *event);
	Gameplay* getGameplay() const;
};

#endif // OPENGLWIDGET_H
