#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget * parent, Qt::WindowFlags f) :
    QOpenGLWidget(parent) {

    /* ustawia rysowanie co 1 milisekundę (doda się jakiegoś VSynca, nie?) */
    paintTimer.start(1);
    connect(&paintTimer, SIGNAL(timeout()), this, SLOT(paintGL()));

    gameplay = new Gameplay();
}

QPoint OpenGLWidget::stretchCoords(QVector2D point) const {
    return QPoint(point.x() * this->width(),
                  point.y() * this->height());
}

void OpenGLWidget::paintNumber(Number n) {
    painter.drawText(stretchCoords(n.getPosition()), "DUPA");
}

void OpenGLWidget::paintGL() {

    if (!painter.isActive()) {
        painter.begin(this);
    }

    /* nie ma czego rysować */
    painter.setBrush(Qt::red);
    painter.drawRect(0,0,10,200);


}
