#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QColorDialog>
#include <QTimer>
#include <QDebug>
#include <QMainWindow>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (ui->GLwidget->reading_settings()) {
        ui->GLwidget->info = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 5, 1 };
    }
    frame_count = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::gif_creator);
        if (ui->GLwidget->info.projection_type == 1) {
          ui->type_projection->activated(1);
        } else if (ui->GLwidget->info.projection_type == 0) {
            ui->type_projection->activated(0);
        }
        double r = ui->GLwidget->info.red;
        double g = ui->GLwidget->info.green;
           double b = ui->GLwidget->info.blue;
                ui->label_color->setStyleSheet(
                        "border: 1px solid rgb(0, 84, 147); border-width: 2px; border-radius: 5px; background-color: RGB(" + QString::number(r) +"," + QString::number(g) +","+ QString::number(b) +");");
                ui->label_color_2->setStyleSheet(
                        "border: 1px solid rgb(0, 84, 147); border-width: 2px; border-radius: 5px; background-color: RGB(1, 1, 1)");
                ui->label_color_3->setStyleSheet(
                        "border: 1px solid rgb(0, 84, 147); border-width: 2px; border-radius: 5px; background-color: RGB(1, 1, 1)");
}

MainWindow::~MainWindow()
{
    if (gif) {
    delete gif;
    }
    if (timer) {
    delete timer;
    }
    ui->GLwidget->fin();
    delete ui;
}

void MainWindow::on_zoom_plus_clicked()
{
    QString s_zoom = ui->doubleSpinBox->text();
    QByteArray ba_zoom = s_zoom.toLocal8Bit();
    char *str_zoom = ba_zoom.data();
    double value_zoom = s_zoom.toDouble();
    if(s_zoom == "" || value_zoom == 0) {
        QMessageBox::information(this, "Error", "Input value zoom");
    } else {
        ui->GLwidget->zoom(value_zoom);
    }
}

void MainWindow::on_zoom_minus_clicked()
{
    QString s_zoom = ui->doubleSpinBox->text();
    QByteArray ba_zoom = s_zoom.toLocal8Bit();
    char *str_zoom = ba_zoom.data();
    double value_zoom = s_zoom.toDouble();
    if(s_zoom == "" || value_zoom == 0) {
        QMessageBox::information(this, "Error", "Input value zoom");
    } else {
        ui->GLwidget->zoom_min(value_zoom);
    }
}


void MainWindow::on_move_x_plus_clicked()
{
    QString s_move_x = ui->move_x->text();
    QByteArray ba_move_x = s_move_x.toLocal8Bit();
    char *str_move_x = ba_move_x.data();
    double value_move_x = s_move_x.toDouble();
    if(value_move_x == 0) {
        QMessageBox::information(this, "Error", "Input value move X");
    } else {
        ui->GLwidget->move_x_plus(value_move_x);
    }
}


void MainWindow::on_move_x_minus_clicked()
{
    QString s_move_x = ui->move_x->text();
    QByteArray ba_move_x = s_move_x.toLocal8Bit();
    char *str_move_x = ba_move_x.data();
    double value_move_x = s_move_x.toDouble();
    if(value_move_x == 0) {
        QMessageBox::information(this, "Error", "Input value move X");
    } else {
        ui->GLwidget->move_x_minus(value_move_x);
    }
}


void MainWindow::on_move_y_plus_clicked()
{
    QString s_move_y = ui->move_y->text();
    QByteArray ba_move_y = s_move_y.toLocal8Bit();
    char *str_move_y = ba_move_y.data();
    double value_move_y = s_move_y.toDouble();
    if(value_move_y == 0) {
        QMessageBox::information(this, "Error", "Input value move Y");
    } else {
        ui->GLwidget->move_y_plus(value_move_y);
    }
}


void MainWindow::on_move_y_minus_clicked()
{
    QString s_move_y = ui->move_y->text();
    QByteArray ba_move_y = s_move_y.toLocal8Bit();
    char *str_move_y = ba_move_y.data();
    double value_move_y = s_move_y.toDouble();
    if(value_move_y == 0) {
        QMessageBox::information(this, "Error", "Input value move Y");
    } else {
        ui->GLwidget->move_y_minus(value_move_y);
    }
}


void MainWindow::on_move_z_plus_clicked()
{
    QString s_move_z = ui->move_z->text();
    QByteArray ba_move_z = s_move_z.toLocal8Bit();
    char *str_move_z = ba_move_z.data();
    double value_move_z = s_move_z.toDouble();
    if(value_move_z == 0) {
        QMessageBox::information(this, "Error", "Input value move Z");
    } else {
        ui->GLwidget->move_z_plus(value_move_z);
    }
}


void MainWindow::on_move_z_minus_clicked()
{
    QString s_move_z = ui->move_z->text();
    QByteArray ba_move_z = s_move_z.toLocal8Bit();
    char *str_move_z = ba_move_z.data();
    double value_move_z = s_move_z.toDouble();
    if(value_move_z == 0) {
        QMessageBox::information(this, "Error", "Input value move Z");
    } else {
        ui->GLwidget->move_z_minus(value_move_z);
    }
}


void MainWindow::on_rotate_x_plus_clicked()
{
    QString s_rotate_x = ui->rotate_x->text();
    QByteArray ba_rotate_x = s_rotate_x.toLocal8Bit();
    char *str_rotate_x = ba_rotate_x.data();
    double value_rotate_x = s_rotate_x.toDouble();
    ui->GLwidget->rotate_x_plus(value_rotate_x);
}


void MainWindow::on_rotate_x_minus_clicked()
{
    QString s_rotate_x = ui->rotate_x->text();
    QByteArray ba_rotate_x = s_rotate_x.toLocal8Bit();
    char *str_rotate_x = ba_rotate_x.data();
    double value_rotate_x = s_rotate_x.toDouble();
    ui->GLwidget->rotate_x_minus(value_rotate_x);
}


void MainWindow::on_rotate_y_plus_clicked()
{
    QString s_rotate_y = ui->rotate_y->text();
    QByteArray ba_rotate_y = s_rotate_y.toLocal8Bit();
    char *str_rotate_y = ba_rotate_y.data();
    double value_rotate_y = s_rotate_y.toDouble();
    ui->GLwidget->rotate_y_plus(value_rotate_y);
}

void MainWindow::on_rotat_y_minus_clicked()
{
    QString s_rotate_y = ui->rotate_y->text();
    QByteArray ba_rotate_y = s_rotate_y.toLocal8Bit();
    char *str_rotate_y = ba_rotate_y.data();
    double value_rotate_y = s_rotate_y.toDouble();
    ui->GLwidget->rotate_y_minus(value_rotate_y);
}


void MainWindow::on_rotate_z_plus_clicked()
{
    QString s_rotate_z = ui->rotate_z->text();
    QByteArray ba_rotate_z = s_rotate_z.toLocal8Bit();
    char *str_rotate_z = ba_rotate_z.data();
    double value_rotate_z = s_rotate_z.toDouble();
    ui->GLwidget->rotate_z_plus(value_rotate_z);
}


void MainWindow::on_rotate_z_minus_clicked()
{
    QString s_rotate_z = ui->rotate_z->text();
    QByteArray ba_rotate_z = s_rotate_z.toLocal8Bit();
    char *str_rotate_z = ba_rotate_z.data();
    double value_rotate_z = s_rotate_z.toDouble();
    ui->GLwidget->rotate_z_minus(value_rotate_z);
}


void MainWindow::on_buttonPath_clicked()
{
    ui->GLwidget->fin();
//    ui->GLwidget->update();
    setlocale(LC_ALL, "C");   // setting local
       QString filter = "file(*.obj)"; // tr()
       QString path = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), filter);
       if (path == "") {
           QMessageBox::information(this, "title", "Вы не выбрали файл");
       }
       ui->linePath->setText(path);
       QByteArray bytes = path.toLocal8Bit();
       char *cstr = bytes.data();

       ui->GLwidget->start_coordination(cstr);

       number_of_vertices = ui->GLwidget->coordination.count_veretex;
       number_of_edges = ui->GLwidget->coordination.count_index / 2;

       QString new_label;
       new_label = QString::number(number_of_vertices, 'g', 15);
       ui->number_vert->setText(new_label);
       QString new_label1;
       new_label1 = QString::number(number_of_edges, 'g', 15);
       ui->number_edge->setText(new_label1);
}


void MainWindow::on_screen_clicked()
{
    QFileDialog file_dialog_img(this);
        QString f_name = file_dialog_img.getSaveFileName(this, tr("Save a screenshot"), "", tr("image (*.bmp *.jpeg)"));
        QImage img = ui->GLwidget->grabFramebuffer();  // Отображает и возвращает 32-битное RGB изображение фреймбуфера.
        img.save(f_name);
}


void MainWindow::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose a color");
        redB = color.redF();
        greenB = color.greenF();
        blueB = color.blueF();
        if (color.isValid()) {
            ui->label_color->setStyleSheet(
                    "border: 1px solid rgb(0, 84, 147); border-width: 2px; border-radius: 5px; background-color: #" +
                    QString::number(color.rgb(), 16));
            ui->GLwidget->colors_RGB(redB, greenB, blueB, 0);
        }
}


void MainWindow::on_pushButton_clicked()
{
    gif = new QGifImage;
    timer->start(100);
}

void MainWindow::gif_creator()
{
    if (frame_count < 30) {
        image = ui->GLwidget->grabFramebuffer();
        gif->addFrame(image);
        frame_count++;
    } else {
        frame_count = 0;
        timer->stop();

        QFileDialog file_dialog_gif(this);
        QString f_name_gif = file_dialog_gif.getSaveFileName(this, tr("Save a gif"), "", tr("gif (*.gif)"));
        gif->save(f_name_gif);
    }
}

void MainWindow::on_buttonColor_lines_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose a color");
        redB = color.redF();
        greenB = color.greenF();
        blueB = color.blueF();
        if (color.isValid()) {
            ui->label_color_2->setStyleSheet(
                    "border: 1px solid #20232A; border-width: 2px; border-radius: 5px; background-color: #" +
                    QString::number(color.rgb(), 16));

            ui->GLwidget->colors_RGB(redB, greenB, blueB, 1);
        }
}

void MainWindow::on_type_projection_activated(int index)
{
    if (index == 0) {
        ui->GLwidget->info.projection_type = 0;
    } else {
        ui->GLwidget->info.projection_type = 1;
    }
    ui->GLwidget->writing_settings();
    ui->GLwidget->update();
}

void MainWindow::on_type_projection_2_activated(int index)
{
    if (index == 0) {
        ui->GLwidget->info.line_type = 0;
    } else {
        ui->GLwidget->info.line_type = 1;
    }
    ui->GLwidget->writing_settings();
    ui->GLwidget->update();
}


void MainWindow::on_thickness_lines_valueChanged(double arg1)
{
    ui->GLwidget->info.thickness = arg1;
    ui->GLwidget->writing_settings();
    ui->GLwidget->update();
}

void MainWindow::on_type_projection_3_activated(int index)
{
    if (index == 0) {
        ui->GLwidget->info.vert_type = 0;
    } else if (index == 1) {
        ui->GLwidget->info.vert_type = 1;
    } else {
        ui->GLwidget->info.vert_type = 2;
    }
    ui->GLwidget->writing_settings();
    ui->GLwidget->update();
}

void MainWindow::on_pushButton_3_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose a color");
        redB = color.redF();
        greenB = color.greenF();
        blueB = color.blueF();
        if (color.isValid()) {
            ui->label_color_3->setStyleSheet(
                    "border: 1px solid #20232A; border-width: 2px; border-radius: 5px; background-color: #" +
                    QString::number(color.rgb(), 16));

            ui->GLwidget->colors_RGB(redB, greenB, blueB, 2);
        }
}

void MainWindow::on_size_vert_valueChanged(int arg1)
{
    ui->GLwidget->info.vert_size = arg1;
    ui->GLwidget->writing_settings();
    ui->GLwidget->update();
}

void MainWindow::on_buttonRest_clicked()
{
    ui->label_color->setStyleSheet(
            "border: 1px solid rgb(0, 84, 147); border-width: 2px; border-radius: 5px; background-color: RGB(1, 1, 1)");

        ui->label_color_2->setStyleSheet(
                "border: 1px solid rgb(0, 84, 147); border-width: 2px; border-radius: 5px; background-color: RGB(1, 1, 1)");
        ui->label_color_3->setStyleSheet(
                "border: 1px solid rgb(0, 84, 147); border-width: 2px; border-radius: 5px; background-color: RGB(1, 1, 1)");

      ui->GLwidget->info = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 5, 1 };
      ui->GLwidget->writing_settings();
       ui->GLwidget->update();

}


void MainWindow::on_Exit_clicked()
{
//    if (gif) {
//    delete gif;
//    }
//    if (timer) {
//    delete timer;
//    }
    ui->GLwidget->fin();
//    QApplication::exit();
}

