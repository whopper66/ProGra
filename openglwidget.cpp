#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget * parent, Qt::WindowFlags) :
	QOpenGLWidget(parent) {

	/* ustawia rysowanie co 17 milisekund
	* (doda się jakiegoś VSynca, nie?) */
	static const int FPS = 60;
	static const int MSECONDS_FOR_FRAME = ceil(1000.0 / FPS);

	paintTimer.start(MSECONDS_FOR_FRAME);

	connect(&paintTimer, SIGNAL(timeout()), this, SLOT(paintGL()));
	connect(&paintTimer, SIGNAL(timeout()), this, SLOT(update()));

	gameplay = new Gameplay();
}

QPoint OpenGLWidget::stretchCoords(const QPointF &point) const {
	return QPoint(point.x() * this->width(),
				  point.y() * this->height());
}

QPointF OpenGLWidget::squeezeCoords(const QPoint &point) const {
	return QPointF(qreal(point.x()) / qreal(this->width()),
				   qreal(point.y()) / qreal(this->height()));
}

void OpenGLWidget::paintNumber(const Number &n) {
	painter.setPen(n.isSelected() ? Style::selectedNumberColor : Style::numberColor);

	QPoint position = stretchCoords(n.getPosition());
	QString text = QString::number(n.getValue());
	painter.drawText(position, text);
}

void OpenGLWidget::paintGL() {
	if (!painter.isActive()) {
		painter.begin(this);
	}

	for (int i = 0; i < gameplay->getNumbersCount(); i++) {
		paintNumber(gameplay->getNthNumber(i));
	}

	painter.end();
}

OpenGLWidget::~OpenGLWidget() {
	delete gameplay;
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event) {
	QPointF coords = squeezeCoords(event->pos());
	gameplay->handleUserClick(coords);
}
