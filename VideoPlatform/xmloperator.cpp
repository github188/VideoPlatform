#include <qdebug.h>
#include <QStringList>
#include <QTextStream>
#include <QDomDocument>
#include "qtextcodec.h"
#include <QFile>
#include <qobject.h>
#include "xmloperator.h"

CXmlOperator::CXmlOperator(QWidget *parent) : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

    QFile *file;
    QString filename = "config.xml";
    if(file->exists("config.xml"))
    {
        readxml(filename);
    }
    else
    {
        //createxml(filename);
    }
}

CXmlOperator::~CXmlOperator()
{

}
//void CXmlOperator::doxml(const QString opt, QString filename)
// {
// //     QFile file(filename);
// //     if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
// //     {
// //         qDebug() << "open for do erro";
// //         file.close();
// //     }
// 
//     return;
// }

void CXmlOperator::readxml(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        qDebug() << "open for read error...";
    }

    QString errorStr;
    int errorLine;
    int errorColumn;
     
    QDomDocument doc;
    if(!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        qDebug()<<"setcontent error...";
        file.close();
    }
    file.close();
    QDomElement root = doc.documentElement();
    if(root.tagName() != "ipconfig")
    {
        qDebug()<< "root.tagname != ipconfig...";
    }
    QDomNode node = root.firstChild();
    while(!node.isNull())
    {
        if(node.isElement())
        {
            QDomElement element = node.toElement();
            //qDebug() << qPrintable(element.tagName()) <<¡¡qPrintable(element.attribute("id"));
            QDomNodeList list = element.childNodes();
            for(int i = 0; i < list.count(); i++)
            {
                QDomNode nodechild = list.at(i);
                if(nodechild.isElement())
                {
                    qDebug() << " " << qPrintable(nodechild.toElement().tagName());
                }
            }
        }
        node = node.nextSibling();
    }

    return;
}