#include "ViewerHelper.h"
#include <QDebug>

ViewerHelper::ViewerHelper()
{

}

QString ViewerHelper::getSupportPixmapRWFormatsList()
{
    QStringList list;
    list<<"*.bmp "<<"*.jpg "<<"*.jpeg "<<"*.png "<<"*.ppm "<<"*.xbm "<<"*.xpm ";
    QString ret;
    foreach (QString i, list) {
        ret += i;
    }
    return ret;
}

QString ViewerHelper::getDirPath(QString &filePath)
{
    return QFileInfo(filePath).absolutePath();
}

QString ViewerHelper::getFileName(QString &filePath)
{
    return QFileInfo(filePath).baseName();
}

const QList<QString> ViewerHelper::parseDir(QString &filePath)
{
    QStringList filters;
    filters<<"*.bmp"<<"*.jpg"<<"*.jpeg"<<"*.png"<<"*.ppm"<<"*.xbm"<<"*.xpm";
    QDir dir(getDirPath(filePath));
    dir.setNameFilters(filters);
    QList<QString> fileInExistDerectory;
    foreach (QString str, dir.entryList()) {
        fileInExistDerectory<<dir.absoluteFilePath(str);
    }
    return fileInExistDerectory;
}

bool ViewerHelper::isFileExist(const QString &filePath)
{
    QFileInfo fi(filePath);
    return fi.exists();
}

bool ViewerHelper::removeFile(const QString &filePath)
{
    if(isFileExist(filePath))
        return QFile(filePath).remove();
    else
        return false;
}
