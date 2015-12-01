#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget * parent, Qt::WindowFlags f) :
    QOpenGLWidget(parent) {

    /* ustawia rysowanie co 1 milisekundę
     * (doda się jakiegoś VSynca, nie?) */
    paintTimer.start(17);
    connect(&paintTimer, SIGNAL(timeout()), this, SLOT(paintGL()));
    connect(&paintTimer, SIGNAL(timeout()), this, SLOT(update()));

    gameplay = new Gameplay();
}

QPoint OpenGLWidget::stretchCoords(QVector2D point) const {
    return QPoint(point.x() * this->width(),
                  point.y() * this->height());
}

void OpenGLWidget::paintNumber(Number n) {
    QPoint position = stretchCoords(n.getPosition());
    QString text = QString(std::to_string(n.getValue()).c_str());
    painter.drawText(position, text);
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

    painter.end();
}

OpenGLWidget::~OpenGLWidget() {
    delete gameplay;
}
