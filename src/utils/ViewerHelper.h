#ifndef VIEWERHELPER_H
#define VIEWERHELPER_H
#include <QStringList>
#include <QList>
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QFile>

class ViewerHelper
{
public:
    ViewerHelper();
    static QString getSupportPixmapRWFormatsList();
    static QString getDirPath(QString &filePath);
    static QString getFileName(QString &filePath);
    static const QList<QString> parseDir(QString &filePath);
    static bool isFileExist(const QString &filePath);
    static bool removeFile(const QString &filePath);
private:
    static QStringList suportedFilesInExistingDirectory;
};

#endif // VIEWERHELPER_H
