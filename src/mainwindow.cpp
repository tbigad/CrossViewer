#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenuBar();
    m_scene = new Scene(this);
    ui->graphicsView->setScene(m_scene);
    m_scene->clearScene();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete menuFile;
    delete m_scene;
}

void MainWindow::dropEvent(QDropEvent *e)
{
    const QMimeData* mimeData = e->mimeData();
    QList<QUrl> urls = mimeData->urls();
    QUrl url = urls.at(0);

    QString filename = url.toLocalFile();
    load( filename );
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{

    const QMimeData* mimeData = event->mimeData();

    if ( !mimeData->hasUrls() )
    {
        event->ignore();
        return;
    }

    QList<QUrl> urls = mimeData->urls();

    if(urls.count() != 1)
    {
        event->ignore();
        return;
    }

    QUrl url = urls.at(0);
    QString filename = url.toLocalFile();

    // We don't test extension
    if ( !QFileInfo(filename).exists() )
    {
        event->ignore();
        return;
    }

    if ( !QFileInfo(filename).isFile() )
    {
        event->ignore();
        return;
    }

    event->acceptProposedAction();
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
        on_btn_fitToWindow_pressed();
    }
}


void MainWindow::on_btn_forward_pressed()
{
    if(m_currentIndex <= -1){
        m_scene->clearScene();
        return;
    }
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
    if(m_currentIndex <= -1){
        m_scene->clearScene();
        return;
    }
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
    if(isFullScreen()){
        emit normalMode();
    }
}

void MainWindow::showEvent(QShowEvent *)
{
    raise();
}

void MainWindow::on_btn_slideShow_pressed()
{
    showFullScreen();
    ui->buttonArea->hide();
    ui->menuBar->hide();

    slshow = new SlideShow();
    slshow->moveToThread(slshow);
    connect(slshow,SIGNAL(nextImage()),this, SLOT(on_btn_forward_pressed()));
    connect(slshow,SIGNAL(finished()),slshow,SLOT(quit()));

    connect(this,&MainWindow::normalMode,[=](){
        slshow->stoped();
        showNormal();
        ui->buttonArea->show();
        ui->menuBar->show();
    });
    slshow->start();
}



void MainWindow::on_actionDelete_triggered()
{
    ViewerHelper::removeFile(m_imagesInDir.at(m_currentIndex));
    on_btn_forward_pressed();
}

void MainWindow::on_btn_delete_pressed()
{
    on_actionDelete_triggered();
}

void MainWindow::on_btn_fitToWindow_pressed()
{
    ui->graphicsView->resetScale();
    double kw = (double)ui->graphicsView->width()/m_currentPixmap.width();
    double kh = (double)ui->graphicsView->height()/m_currentPixmap.height();
    if (qMin(kw,kh)<1)
        ui->graphicsView->scale(qMin(kw,kh),qMin(kw,kh));
}
