#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget * parent, Qt::WindowFlags f) :
    QOpenGLWidget(parent) {

    /* ustawia rysowanie co 1 milisekundę (doda się jakiegoś VSynca, nie?) */
    paintTimer.start(1);
    connect(&paintTimer, SIGNAL(timeout()), this, SLOT(paintGL()));

}

void OpenGLWidget::paintGL() {

    if (!painter.isActive()) {
        painter.begin(this);
    }

    /* nie ma czego rysować */
    painter.setBrush(Qt::red);
    painter.drawRect(0,0,10,200);
}
