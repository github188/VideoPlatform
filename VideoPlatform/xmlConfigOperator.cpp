#include "xmlConfigOperator.h"

CXmlConfigOperator::CXmlConfigOperator(QWidget *parent) : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
}

CXmlConfigOperator::~CXmlConfigOperator()
{

}
void CXmlConfigOperator::doxml(const QString opt, QString filename)
{
//     QFile file(filename);
//     if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//     {
//         qDebug() << "open for do erro";
//         file.close();
//     }

    return;
}

void CXmlConfigOperator::readxml(QString filename, QList<DEVICEINFO> &listConfigInfo)
{
    QString filename1 = "C:\/Users\/paper~news\/Desktop\/VideoPlafrom_git\/VideoPlatform\/VideoPlatform\/config.txt";
    QFile file(filename1);
    DEVICEINFO stDeviceInfo;
    QString errorStr;
    int errorLine;
    int errorColumn;

    if(!file.open(QIODevice::ReadOnly| QFile::Text))
    {
        qDebug() << file.error();
        qDebug() << file.errorString();
        return;
    }

    QDomDocument doc;
    if(!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        qDebug() << "setcontent error...";
        file.close();
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomNodeList nodelist = root.elementsByTagName("Device");
    for(int i = 0; i < nodelist.count(); i++)
    {
        QDomNode node = nodelist.at(i);
        QDomNodeList itemlist = node.childNodes();
        for(int j = 0; j < itemlist.count(); j++)
        {
            QDomNode mynode = itemlist.at(j);
            if(mynode.toElement().attribute("key") == "DeviceName")
            {
                QString result2 = mynode.toElement().attribute("value");
                stDeviceInfo.strDeviceName = result2;
                //qDebug("DeviceName = %s,", qPrintable(result2));
            }
            else if(mynode.toElement().attribute("key") == "DeviceIP")
            {
                QString result2 = mynode.toElement().attribute("value");
                //qDebug("DeviceIP = %s,", qPrintable(result2));
                stDeviceInfo.strDeviceIP = result2;
            }
            else if(mynode.toElement().attribute("key") == "DevicePort")
            {
                QString result2 = mynode.toElement().attribute("value");
                //qDebug("DevicePort = %s,", qPrintable(result2));
                stDeviceInfo.nDevicePort = result2.toInt();
            }
            else if(mynode.toElement().attribute("key") == "DeviceChlNum")
            {
                QString result2 = mynode.toElement().attribute("value");
                //qDebug("DeviceChlNum = %s,", qPrintable(result2));
                stDeviceInfo.nDeviceChlNum = result2.toInt();
            }
            else if(mynode.toElement().attribute("key") == "DeviceType")
            {
                QString result2 = mynode.toElement().attribute("value");
                //qDebug("DeviceType = %s,", qPrintable(result2));
                stDeviceInfo.enDeviceType = (ENUMDEVICETYPE)result2.toInt();
            }
        }
        listConfigInfo.append(stDeviceInfo);
    }

    return;
}