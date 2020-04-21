#ifndef HOURSDIALOG_H
#define HOURSDIALOG_H

#include <QDialog>

namespace Ui {
class HoursDialog;
}

class HoursDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HoursDialog(QWidget *parent = nullptr);
    ~HoursDialog();

private:
    Ui::HoursDialog *ui;
};

#endif // HOURSDIALOG_H
