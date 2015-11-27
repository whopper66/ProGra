#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget * parent, Qt::WindowFlags f) :
    QOpenGLWidget(parent) {

    //ustawia rysowanie co 1 milisekundę (doda się jakiegoś VSynca, nie?)
    timer.start(1);
    connect(&timer, SIGNAL(timeout()), this, SLOT(paintGL()));

}

void OpenGLWidget::paintGL() {

    if (!painter.isActive()) {
        painter.begin(this);
    }

    painter.setBrush(Qt::red);
    painter.drawRect(0,0,10,200);
}
