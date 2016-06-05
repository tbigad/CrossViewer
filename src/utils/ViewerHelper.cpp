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

QString ViewerHelper::getFormat(const QString &filePath)
{
    QFileInfo fi(filePath);
    return fi.suffix();
}

QMap<QString, QString> ViewerHelper::getLongImageFormats()
{
    QMap<QString, QString> formats;

    formats["bmp"] = "Windows Bitmap";
    formats["gif"] = "Graphic Interchange Format";
    formats["jpg"] = "Joint Photographic Experts Group";
    formats["jpeg"] = "Joint Photographic Experts Group";
    formats["png"] = "Portable Network Graphics";
    formats["svg"] = "Scalable Vector Graphics";
    formats["pdf"] = "Portable Document Format";

    return formats;
}

QString ViewerHelper::QSizeToQString(QSize s)
{
    QString str = QString("("+QString::number(s.width())+"x"+QString::number(s.height())+")");
    return str;
}

QStringList ViewerHelper::getSupportImageFormatsList()
{
    QStringList formats;
    formats << "bmp"<<"jpg"<<"jpeg"<<"png"<<"ppm"<<"xbm"<<"xpm";
    return formats;
}

QString ViewerHelper::getCurrentLongImageFormat(QString s)
{
    QMap<QString, QString> map =  ViewerHelper::getLongImageFormats();
    QString currentFormat = map[s];
    return currentFormat;
}

QString ViewerHelper::getAvailablesImageFormatsForWriting()
{
    QString imglist;
    QStringList formats = getSupportImageFormatsList();
    for (int i = 0; i < formats.size(); ++i)
        imglist += "*." + formats[i] + " ";

    return imglist;
}

QString ViewerHelper::getAvailablesImageFormats()
{
    QString imglist;
    QStringList formats = getSupportImageFormatsList();
    for (int i = 0; i < formats.size(); ++i)
        imglist += "*." + formats[i] + " ";

    return imglist;
}

QString ViewerHelper::getImageFormats()
{
    QMap<QString, QString> map;
    map = ViewerHelper::getLongImageFormats();

    QString imglist;
    QStringList formats = getSupportImageFormatsList();
    for (int i = 0; i < formats.size(); ++i)
    {
        imglist += map[formats[i]];
        imglist += " (*." + formats[i];
        if(i == (formats.size()-1))
             imglist += ")";
        else imglist += ");;";
    }

    return imglist;
}
