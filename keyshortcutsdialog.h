#ifndef KEYSHORTCUTSDIALOG_H
#define KEYSHORTCUTSDIALOG_H

#include <QDialog>

namespace Ui {
class KeyShortcutsDialog;
}

class KeyShortcutsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KeyShortcutsDialog(QWidget *parent = nullptr);
    ~KeyShortcutsDialog();

private:
    Ui::KeyShortcutsDialog *ui;
};

#endif // KEYSHORTCUTSDIALOG_H
