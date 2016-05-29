#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenuBar();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete menuFile;
}

void MainWindow::initMenuBar()
{
    menuFile = new QMenu("File");

    menuFile->addAction(ui->actionOpen);
    menuFile->addAction(ui->actionDelete);
    menuFile->addAction(ui->actionSave_as);
    menuFile->addSeparator();
    menuFile->addAction(ui->actionExit);
    ui->menuBar->addMenu(menuFile);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
