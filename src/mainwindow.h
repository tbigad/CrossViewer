#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include "ui_mainwindow.h"
#include "Scene.h"
#include "utils/ViewerHelper.h"
#include <QFileDialog>
#include <QDir>

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

    void on_actionOpen_triggered();

private:
    void openFile(QString&);
    void initMenuBar();

    QString lastExitDir;
    QMenu *menuFile;
    Scene *m_scene;
    QPixmap m_currentPixmap;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
