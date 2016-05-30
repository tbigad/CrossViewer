#ifndef VIEWERHELPER_H
#define VIEWERHELPER_H
#include <QStringList>
#include <QString>
#include <QDir>
#include <QFileInfo>

class ViewerHelper
{
public:
    ViewerHelper();
    static QString getSupportPixmapRWFormatsList();
    static QString getDirPath(QString filePath);
};

#endif // VIEWERHELPER_H
