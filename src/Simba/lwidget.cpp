#include "lwidget.h"
#include "ui_lwidget.h"

LWidget::LWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LWidget)
{
    ui->setupUi(this);
}

LWidget::~LWidget()
{
    delete ui;
}
