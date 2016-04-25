#include "videoplatform.h"
#include <QtWidgets/QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("VM"); /* 设置应用程序名称 */
    a.setApplicationVersion("V2015.12.17");
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    VideoPlatform w;
    w.show();
    return a.exec();
}
