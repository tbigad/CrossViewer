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

QString ViewerHelper::getDirPath(QString filePath)
{
    return QFileInfo(filePath).absolutePath();
}
