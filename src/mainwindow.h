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
#include <QThread>
#include <thread>

namespace Ui {
class MainWindow;
}
class SlideShow;

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

    void on_actionDelete_triggered();

    void on_btn_delete_pressed();

protected:
    void mousePressEvent(QMouseEvent *e);
    void showEvent(QShowEvent *);
signals:
    void normalMode();

private:
    void load(QString filePath);
    void load(QPixmap &pix);
    void initMenuBar();
    void slideShow();
    void writeText(QString&);

    SlideShow *slshow;

    QString lastExitDir;
    QMenu *menuFile;
    Scene *m_scene;
    QPixmap m_currentPixmap;
    Ui::MainWindow *ui;
    QList<QString> m_imagesInDir;
    int m_currentIndex;
};

class SlideShow:public QThread
{
    Q_OBJECT

    volatile bool again;
public:
    SlideShow(){
        again = true;
    }
    virtual ~SlideShow(){}
public slots:
    void run(){
       std::thread t([=](){
           std::this_thread::sleep_for
                   (std::chrono::milliseconds(1500));
                forever{
                    if(again){
                        emit nextImage();
                        std::this_thread::sleep_for
                                (std::chrono::milliseconds(1500));
                    }else
                        break;
                }
            });
        t.join();
     }
    void stoped(){
        again = false;
    }
 signals:
     void nextImage();
 };

#endif // MAINWINDOW_H
