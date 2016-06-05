#ifndef VIEWERHELPER_H
#define VIEWERHELPER_H
#include <QStringList>
#include <QList>
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QSize>

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
    static QString getFormat(const QString &filePath);
    static QString getImageFormats();
    static QString getCurrentLongImageFormat(QString s);
    static QStringList getSupportImageFormatsList();
    static QString getAvailablesImageFormats();
    static QString getAvailablesImageFormatsForWriting();
    static QMap<QString, QString> getLongImageFormats();
    static QString QSizeToQString(QSize);
private:
    static QStringList suportedFilesInExistingDirectory;
};

#endif // VIEWERHELPER_H
