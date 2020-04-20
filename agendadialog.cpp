#include <QHBoxLayout>
#include <QLabel>
#include <QRect>
#include "agendadialog.h"
#include "ui_agendadialog.h"

AgendaDialog::AgendaDialog(DataAggregator *dman, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgendaDialog)
{
    ui->setupUi(this);
    this->datamanager = dman;
    this->geometry();

    ui->listWidget->resize(1000,1000);
}

AgendaDialog::~AgendaDialog()
{
    delete ui;
}
