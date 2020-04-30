#ifndef KEYSHORTCUTSDIALOG_H
#define KEYSHORTCUTSDIALOG_H

#include <QDialog>

namespace Ui {
class KeyShortcutsDialog;
}

class KeyShortcutsDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::KeyShortcutsDialog *ui;

public:
    explicit KeyShortcutsDialog(QWidget *parent = nullptr);
    ~KeyShortcutsDialog();

};

#endif // KEYSHORTCUTSDIALOG_H
