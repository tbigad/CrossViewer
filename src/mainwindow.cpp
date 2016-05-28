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
    menuFile->addAction(ui->actionDelete);
    ui->menuBar->addMenu(menuFile);
}
