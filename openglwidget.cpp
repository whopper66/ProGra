#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget * parent, Qt::WindowFlags f) :
    QOpenGLWidget(parent) {

    /* ustawia rysowanie co 1 milisekundę
     * (doda się jakiegoś VSynca, nie?) */
    paintTimer.start(1);
    connect(&paintTimer, SIGNAL(timeout()), this, SLOT(paintGL()));

    gameplay = new Gameplay();
}

QPoint OpenGLWidget::stretchCoords(QVector2D point) const {
    return QPoint(point.x() * this->width(),
                  point.y() * this->height());
}

void OpenGLWidget::paintNumber(Number n) {
    int x = stretchCoords(n.getPosition()).rx();
    int y = stretchCoords(n.getPosition()).ry();
    int w = n.getValue();
    int h = 10;
    painter.drawRect(x, y, w, h);
}

void OpenGLWidget::paintGL() {
    if (!painter.isActive()) {
        painter.begin(this);
    }

    /* nie ma czego rysować */
    painter.setPen(Qt::white);
    painter.setBrush(Qt::red);
    painter.drawRect(0,0,10,200);

    for (int i = 0; i < gameplay->getNumbersCount(); i++) {
        paintNumber(gameplay->getNthNumber(i));
    }

}

OpenGLWidget::~OpenGLWidget() {
    delete gameplay;
}
