#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include "ui_mainwindow.h"
#include "Scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

private:
    void initMenuBar();

    QMenu *menuFile;
    Scene *m_scene;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
