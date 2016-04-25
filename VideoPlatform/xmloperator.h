#ifndef __XMLOPERATOR__H_
#define __XMLOPERATOR__H_

#include <QWidget>

class CXmlOperator : public QWidget
{
    Q_OBJECT
public:
    CXmlOperator(QWidget *parent = 0);
    ~CXmlOperator();

    void readxml(QString filename);
//     void createxml(QString filename);
//     void addxmlNode(QString filename, QString rmt_name, QString ipa, QString ipb);
//     void doxml(const QString opt, QString filename);

protected:
private:
};

#endif