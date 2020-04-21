#include "hoursdialog.h"
#include "ui_hoursdialog.h"

HoursDialog::HoursDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HoursDialog)
{
    ui->setupUi(this);
}

HoursDialog::~HoursDialog()
{
    delete ui;
}
