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

    QFontDatabase::addApplicationFont(":/Fonts/ARCADECLASSIC.TTF");
	numberFont = QFont("ArcadeClassic", 20);
	gameplay = new Gameplay();
}

int OpenGLWidget::stretchRadius(const qreal r) const {
    return r * std::min(this->width(), this->height());
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
    painter.setPen(n.isSelected() ?
                       Style::selectedNumberColor : Style::numberColor);

    int radius = stretchRadius(CLICK_RADIUS);
	QPoint position = stretchCoords(n.getPosition());

    painter.setBrush(Style::circleColor);
	painter.drawEllipse(position, radius, radius);

    QString text = QString::number(n.getValue());
	QFontMetrics numberFontMetrics(numberFont);
	position.setX(position.x()-numberFontMetrics.width(text)/2);
	position.setY(position.y()+(numberFontMetrics.ascent()-numberFontMetrics.descent())/2);
	painter.drawText(position, text);
}

void OpenGLWidget::paintTimeBar() {
    if (!gameplay->isTimed()) {
        return;
    }

    painter.setPen(Style::timeBarColor);
    painter.setBrush(Style::timeBarBgColor);
    painter.drawRect(100, 10, 100, 10);

    painter.setBrush(Style::timeBarFillColor);
    painter.drawRect(100, 10, (100 * gameplay->getTimeLeft()) / gameplay->getStartTime(), 10);
}

void OpenGLWidget::clearBg() {
    painter.setBrush(Style::bgColor);
    painter.drawRect(0., 0, this->width(), this->height());
}

void OpenGLWidget::paintGL() {
	if (!painter.isActive()) {
		painter.begin(this);
	}
	painter.setFont(numberFont);

    clearBg();
	for (int i = 0; i < gameplay->getNumbersCount(); i++) {
		paintNumber(gameplay->getNthNumber(i));
	}
    paintTimeBar();

    cloudsImage = QImage(":/Graphics/clouds.gif");
    painter.drawImage(0, 0, cloudsImage);


	painter.end();
}

OpenGLWidget::~OpenGLWidget() {
	delete gameplay;
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event) {
	QPointF coords = squeezeCoords(event->pos());
    gameplay->handleUserClick(coords, CLICK_RADIUS);
}

Gameplay* OpenGLWidget::getGameplay() const {
	return gameplay;
}
