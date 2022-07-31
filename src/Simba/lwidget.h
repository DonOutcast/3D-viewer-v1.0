#ifndef LWIDGET_H
#define LWIDGET_H

#include <QDialog>

namespace Ui {
class LWidget;
}

class LWidget : public QDialog
{
    Q_OBJECT

public:
    explicit LWidget(QWidget *parent = nullptr);
    ~LWidget();

private:
    Ui::LWidget *ui;
};

#endif // LWIDGET_H
