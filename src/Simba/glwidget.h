#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>
#include <QtOpenGLWidgets/qopenglwidget.h>
#include <QOpenGLFunctions>
#include "mainwindow.h"
#include <QMouseEvent>



class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
     obj coordination = {0};
//     int Xrot = 0;
    void draw();
    void zoom(double value_zoom);
    void zoom_min(double value_zoom);
    void move_x_plus(double value_move_x);
    void move_x_minus(double value_move_x);
    void move_y_plus(double value_move_y);
    void move_y_minus(double value_move_y);
    void move_z_plus(double value_move_z);
    void move_z_minus(double value_move_z);
    void rotate_x_plus(double value_rotate_x);
    void rotate_x_minus(double value_rotate_x);
    void rotate_y_plus(double value_rotate_y);
    void rotate_y_minus(double value_rotate_y);
    void rotate_z_plus(double value_rotate_z);
    void rotate_z_minus(double value_rotate_z);
    void start_coordination(char *str);
    void writing_settings();
    int reading_settings();
    void fin();
     double new_arr[1000];
     int count = 0;
//     rgb(219, 207, 184)
//     rgb(255, 126, 121)
     void colors_RGB(float red, float green, float blue, int flag);
     set info = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 5, 1 };
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    float xRot, yRot, zRot;
    QPoint mPos;




};

#endif // GLWIDGET_H
