#ifndef AGENDADIALOG_H
#define AGENDADIALOG_H

#include <QDialog>
#include "dataaggregator.h"

namespace Ui {
class AgendaDialog;
}

class AgendaDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::AgendaDialog *ui;
    DataAggregator *datamanager;
public:
    explicit AgendaDialog(DataAggregator* dman, QWidget *parent = nullptr);
    ~AgendaDialog();
};

#endif // AGENDADIALOG_H
