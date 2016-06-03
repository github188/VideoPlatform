#include "videoplatform.h"
#include <QtWidgets/QApplication>
#include <QtWidgets>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("VM"); /* ����Ӧ�ó������� */
    a.setApplicationVersion("V2015.12.17");
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(codec);

    VideoPlatform w;
    w.show();
    return a.exec();
}
