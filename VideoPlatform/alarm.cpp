#include <QMenu>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QBitmap>
#include <QStyleOption>
#include <QDir>
#include <qlayout.h>
#include <QResizeEvent>
#include <iconhelper.h>
#include <QMimeData>
#include <QWidget>

#include "alarm.h"
#include "myapp.h"

alarm::alarm(QWidget *parent):QDialog(parent)
{
    ui.setupUi(this);
    this->InitForm();
    this->InitStyle();
}

alarm::~alarm()
{

}

void alarm::mouseMoveEvent(QMouseEvent *event)
{

}

void alarm::mousePressEvent(QMouseEvent *event)
{

}

void alarm::mouseReleaseEvent(QMouseEvent *event)
{

}

void alarm::InitForm()
{

}

void alarm::InitStyle()
{
    this->setProperty("Form", true);
//     this->setWindowFlags(Qt::FramelessWindowHint |
//                           Qt::WindowSystemMenuHint |
//                           Qt::WindowMinMaxButtonsHint);

//    connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}