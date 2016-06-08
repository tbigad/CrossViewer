#include "EditorPanel.h"

EditorPanel::EditorPanel(QWidget *parent) :
    QWidget(parent,Qt::FramelessWindowHint),
    ui(new Ui::EditorPanelUI)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    show();
}

EditorPanel::~EditorPanel()
{
    delete ui;
}
