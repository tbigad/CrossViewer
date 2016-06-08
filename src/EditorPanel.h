#ifndef EDITORPANEL_H
#define EDITORPANEL_H

#include <QWidget>
#include "ui_editpanel.h"

namespace Ui {
class EditorPanelUI;
}

class EditorPanel : public QWidget
{
    Q_OBJECT

public:
    explicit EditorPanel(QWidget *parent = 0);
    ~EditorPanel();

private:
    Ui::EditorPanelUI *ui;
};

#endif // EDITORPANEL_H
