#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenuBar();
    m_scene = new Scene(this);
    ui->graphicsView->setScene(m_scene);
    QString str(tr(" Open file(press F3)or drop files here"));
    writeText(str);
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

void MainWindow::writeText(QString &t)
{
    QFont font;
    font.setFamily("Arial");
    font.setPixelSize(16);
    m_scene->addText(t,font);
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
        load(file);
}

void MainWindow::load(QString filePath)
{
        lastExitDir = ViewerHelper::getDirPath(filePath);
        m_imagesInDir = ViewerHelper::parseDir(filePath);
        m_currentIndex = m_imagesInDir.indexOf(filePath);
        setWindowTitle("CrossViewer - "+ ViewerHelper::getFileName(filePath));
        m_currentPixmap.load(filePath);
        load(m_currentPixmap);
}

void MainWindow::load(QPixmap &pix)
{
    if(pix.rect().isValid()){
        m_scene->clear();
        m_scene->setPixmap(pix);
    }
}


void MainWindow::on_btn_forward_pressed()
{
    if(m_currentIndex == -1)
        return;
    m_currentIndex++;
    if(m_currentIndex < m_imagesInDir.count())
    {
        if(QFileInfo(m_imagesInDir.at(m_currentIndex)).exists())
            load(m_imagesInDir.at(m_currentIndex));
        else
            on_btn_forward_pressed();
    }else{
        m_currentIndex = 0;
        load(m_imagesInDir.at(m_currentIndex));
    }
}

void MainWindow::on_btn_back_pressed()
{
    if(m_currentIndex <= -1)
        return;
    m_currentIndex--;
    if(m_currentIndex >= 0)
    {
        if(QFileInfo(m_imagesInDir.at(m_currentIndex)).exists())
            load(m_imagesInDir.at(m_currentIndex));
        else
            on_btn_forward_pressed();
    }else{
        m_currentIndex = m_imagesInDir.count()-1;
        load(m_imagesInDir.at(m_currentIndex));
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(this->isFullScreen())
        if(e->button() == Qt::RightButton){
            showNormal();
            ui->buttonArea->show();
            ui->menuBar->show();
        }
}

void MainWindow::openFile(QString &f)
{
    qDebug()<< f;
}
