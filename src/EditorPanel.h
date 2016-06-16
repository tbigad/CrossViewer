#ifndef EDITORPANEL_H
#define EDITORPANEL_H

#include <QWidget>
#include "ui_editpanel.h"
#include "mainwindow.h"

namespace Ui {
class EditorPanelUI;
}

class EditorPanel : public QDialog
{
    Q_OBJECT

public:
    explicit EditorPanel(QPixmap pix, QWidget *parent = 0);
    ~EditorPanel();

private slots:
    void on_pushCancel_pressed();
    void edit();
signals:
    void toSave(QPixmap,int);
private:
    Ui::EditorPanelUI *ui;
    QPixmap currentPix;
};

#endif // EDITORPANEL_H
