#ifndef AGENDADIALOG_H
#define AGENDADIALOG_H

#include <QDialog>

namespace Ui {
class AgendaDialog;
}

class AgendaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AgendaDialog(QWidget *parent = nullptr);
    ~AgendaDialog();

private:
    Ui::AgendaDialog *ui;
};

#endif // AGENDADIALOG_H
