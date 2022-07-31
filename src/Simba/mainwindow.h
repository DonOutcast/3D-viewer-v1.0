#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qgifimage.h"


#ifdef __cplusplus
extern "C"
{
#endif
#include "../lib.h"
#ifdef __cpluplus
}
#endif


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    float red = 1, green = 1, blue = 1, redB = 0, greenB = 0, blueB = 0;
        float redB = 0, greenB = 0, blueB = 0;
        QTimer *timer;
        QImage image;

//        QSize size(1224, 824);
        QGifImage *gif;
        int frame_count;


private slots:
    void on_zoom_plus_clicked();

    void on_zoom_minus_clicked();

    void on_move_x_plus_clicked();

    void on_move_x_minus_clicked();

    void on_move_y_plus_clicked();

    void on_move_y_minus_clicked();

    void on_move_z_plus_clicked();

    void on_move_z_minus_clicked();

    void on_rotate_x_plus_clicked();

    void on_rotate_x_minus_clicked();

    void on_rotate_y_plus_clicked();

    void on_rotat_y_minus_clicked();

    void on_rotate_z_plus_clicked();

    void on_rotate_z_minus_clicked();

    void on_buttonPath_clicked();

    void on_screen_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void gif_creator();

    void on_buttonColor_lines_clicked();

    void on_type_projection_activated(int index);

    void on_type_projection_2_activated(int index);

    void on_thickness_lines_valueChanged(double arg1);

    void on_type_projection_3_activated(int index);

    void on_pushButton_3_clicked();

    void on_size_vert_valueChanged(int arg1);

    void on_buttonRest_clicked();

    void on_Exit_clicked();

public:
    int number_of_vertices = 0;
    int number_of_edges = 0;
    obj coordination1 = {0};

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
