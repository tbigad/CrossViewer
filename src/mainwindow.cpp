#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenuBar();
    m_scene = new Scene(this);
    ui->graphicsView->setScene(m_scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete menuFile;
    delete m_scene;
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

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(
                this,tr("Select one file to open"), lastExitDir,
                ViewerHelper::getSupportPixmapRWFormatsList());
    if(!file.isEmpty()){
        lastExitDir = ViewerHelper::getDirPath(file);
        openFile(file);
        m_scene->clear();    m_currentPixmap.load(file);
        m_scene->setPixmap(m_currentPixmap);
        setWindowTitle("CrossViewer - "+ ViewerHelper::getFileName(file));
    }

}

void MainWindow::openFile(QString &f)
{
    qDebug()<< f;
}
