#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>

#include <QFile>
#include <QDateTime>
#include <QTextStream>

QScopedPointer<QFile> logFile;

void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    QTextStream out(logFile.data());
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");

    switch (type)
    {
    case QtInfoMsg: out << "INF "; break;
    case QtDebugMsg: out << "DBG "; break;
    }

    out << context.category << ": "
        << msg << endl;
    out.flush();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    logFile.reset(new QFile("logFile.txt"));
    logFile.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(messageHandler);

    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
}
