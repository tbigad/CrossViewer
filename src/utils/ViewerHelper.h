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
    static QString getDirPath(QString &filePath);
    static QString getFileName(QString &filePath);
    static const QStringList& parseDir(QString &filePath);
private:
    static QStringList suportedFilesInExistingDirectory;
};

#endif // VIEWERHELPER_H
