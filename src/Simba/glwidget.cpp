#include "glwidget.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QDebug>
GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void GLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL()
{
    glClearColor (info.red, info.green, info.blue, 0);
    glLineStipple(1, 0x1C47);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    if (info.projection_type) {
        glOrtho(-2, 2, -2, 2, -100, 100);
    } else {
        glFrustum(-1, 1, -1, 1, -100, 100);
    }
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    glScalef(0.7, 0.7, 0.7);
    draw();
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}


void GLWidget::draw() {
    glLineWidth (info.thickness);
    if (info.line_type) {
         glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00F0);
    }
    if (info.vert_type) {
        glPointSize(info.vert_size);
        if (info.vert_type == 2) {
            glEnable(GL_POINT_SMOOTH);
        }
    }
    glVertexPointer(3, GL_DOUBLE, 0, coordination.veretex);

    glEnableClientState(GL_VERTEX_ARRAY);
    if (info.vert_type) {
        glColor3d(info.redv, info.greenv, info.bluev);
        glDrawArrays(GL_POINTS, 0, coordination.count_veretex);
    }
    glColor3d(info.redl, info.greenl, info.bluel);

    glDrawElements(GL_LINES, coordination.count_index, GL_UNSIGNED_INT, coordination.index);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_POINT_SMOOTH);
    glDisable(GL_LINE_STIPPLE);
}

void GLWidget::zoom(double value_zoom)
{
    zoom_plus(value_zoom, &coordination);
    update();
}

void GLWidget::zoom_min(double value_zoom)
{
  zoom_minus(value_zoom, &coordination);
  update();
}

void GLWidget::move_x_plus(double value_move_x)
{
    s21_move_x(value_move_x, &coordination, 1);
    update();
}

void GLWidget::move_x_minus(double value_move_x)
{
    s21_move_x(value_move_x, &coordination, 0);
    update();
}

void GLWidget::move_y_plus(double value_move_y)
{
    s21_move_y(value_move_y, &coordination, 1);
    update();
}

void GLWidget::move_y_minus(double value_move_y)
{
    s21_move_y(value_move_y, &coordination, 0);
    update();
}

void GLWidget::move_z_plus(double value_move_z)
{
    s21_move_z(value_move_z, &coordination, 1);
    update();
}

void GLWidget::move_z_minus(double value_move_z)
{
    s21_move_z(value_move_z, &coordination, 0);
    update();
}

void GLWidget::rotate_x_plus(double value_rotate_x)
{

    value_rotate_x = value_rotate_x * M_PI / 180;
    s21_rotate_x(value_rotate_x, &coordination);
    update();
}

void GLWidget::rotate_x_minus(double value_rotate_x)
{
    value_rotate_x = 360 - value_rotate_x;
    value_rotate_x = value_rotate_x * M_PI / 180;
    s21_rotate_x(value_rotate_x, &coordination);
    update();
}

void GLWidget::rotate_y_plus(double value_rotate_y)
{
    value_rotate_y = value_rotate_y * M_PI / 180;
    s21_rotate_y(value_rotate_y, &coordination);
    update();
}

void GLWidget::rotate_y_minus(double value_rotate_y)
{
    value_rotate_y = 360 - value_rotate_y;
    value_rotate_y = value_rotate_y * M_PI / 180;
    s21_rotate_y(value_rotate_y, &coordination);
    update();
}

void GLWidget::rotate_z_plus(double value_rotate_z)
{
    value_rotate_z = value_rotate_z * M_PI / 180;
    s21_rotate_z(value_rotate_z, &coordination);
    update();
}

void GLWidget::rotate_z_minus(double value_rotate_z)
{
    value_rotate_z = 360 - value_rotate_z;
    value_rotate_z = value_rotate_z * M_PI / 180;
    s21_rotate_z(value_rotate_z, &coordination);
    update();
}

void GLWidget::start_coordination(char *str)
{
    start(&coordination, str);
    update();
}

void GLWidget::writing_settings()
{
    writing_to_file(&info);
}

int GLWidget::reading_settings()
{
    int mar = 1;
    if (read_file(&info)) {
          mar = 0;
        update();
    }
    return mar;
}

void GLWidget::fin()
{
    finish(&coordination);
    coordination ={0};
}

void GLWidget::colors_RGB(float red, float green, float blue, int flag)
{
    if (flag == 0) {
        this->info.red = red;
        this->info.green = green;
        this->info.blue = blue;
        writing_to_file(&info);
    } else if (flag == 1) {
        this->info.redl = red;
        this->info.greenl = green;
        this->info.bluel = blue;
        writing_to_file(&info);
    } else {
        this->info.redv = red;
        this->info.greenv = green;
        this->info.bluev = blue;
        writing_to_file(&info);
    }
    update();
}

void GLWidget::mousePressEvent(QMouseEvent* mo)
{
    mPos = mo->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *mo)
{
    xRot = 1/M_PI * (mo->pos().y() - mPos.y());
    yRot = 1/M_PI * (mo->pos().x() - mPos.x());
    update();
}








