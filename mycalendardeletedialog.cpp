#include "mycalendardeletedialog.h"
#include "ui_mycalendardeletedialog.h"
#include <QPixmap>

MyCalendarDeleteDialog::MyCalendarDeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCalendarDeleteDialog)
{
    ui->setupUi(this);

}

MyCalendarDeleteDialog::~MyCalendarDeleteDialog()
{
    delete ui;
}