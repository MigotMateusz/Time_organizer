#ifndef AGENDADIALOG_H
#define AGENDADIALOG_H

#include <QDialog>

namespace Ui {
class AgendaDialog;
}

class AgendaDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::AgendaDialog *ui;

public:
    explicit AgendaDialog(QWidget *parent = nullptr);
    ~AgendaDialog();
};

#endif // AGENDADIALOG_H
