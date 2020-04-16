#include "mycalendardialog.h"
#include "ui_mycalendardialog.h"

MyCalendarDialog::MyCalendarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCalendarDialog)
{
    ui->setupUi(this);
}

MyCalendarDialog::~MyCalendarDialog()
{
    delete ui;
}
