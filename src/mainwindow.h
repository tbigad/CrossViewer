#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QMainWindow>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include "ui_mainwindow.h"
#include "Scene.h"
#include "utils/ViewerHelper.h"
#include <QFileDialog>
#include <QDir>
#include <QTimer>

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
    void on_btn_forward_pressed();
    void on_btn_back_pressed();
    void on_btn_slideShow_pressed();

protected:
    void mousePressEvent(QMouseEvent *e);

private:
    void load(QString filePath);
    void load(QPixmap &pix);
    void initMenuBar();
    void writeText(QString&);

    QString lastExitDir;
    QMenu *menuFile;
    Scene *m_scene;
    QPixmap m_currentPixmap;
    Ui::MainWindow *ui;
    QList<QString> m_imagesInDir;
    int m_currentIndex;
};

#endif // MAINWINDOW_H
