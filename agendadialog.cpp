#include "agendadialog.h"
#include "ui_agendadialog.h"

AgendaDialog::AgendaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgendaDialog)
{
    ui->setupUi(this);
}

AgendaDialog::~AgendaDialog()
{
    delete ui;
}
