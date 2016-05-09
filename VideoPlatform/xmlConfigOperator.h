#ifndef __XMLCONFIGOOPERATOR_H__
#define __XMLCONFIGOOPERATOR_H__
#include <QWidget>
#include <qdebug.h>
#include <QStringList>
#include <QTextStream>
#include <QDomDocument>
#include "qtextcodec.h"
#include <QFile>
#include <QFileInfo>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "publicDef.h"

class CXmlConfigOperator : public QWidget
{
    Q_OBJECT
public:
    CXmlConfigOperator(QWidget *parent = 0);
    ~CXmlConfigOperator();

    void readxml(QString filename, QList<DEVICEINFO> &listConfigInfo);
    //     void createxml(QString filename);
    //     void addxmlNode(QString filename, QString rmt_name, QString ipa, QString ipb);
     void doxml(const QString opt, QString filename);
protected:
private:
};
#endif