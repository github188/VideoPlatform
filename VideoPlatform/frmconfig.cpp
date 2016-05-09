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

#include "frmconfig.h"
#include "myapp.h"

frmConfig::frmConfig(QWidget *parent) : QDialog(parent)
{
    ui.setupUi(this);
    this->InitStyle();
    this->InitForm();
}

frmConfig::~frmConfig()
{
}

void frmConfig::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePressed && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - mousePoint);
        event->accept();
    }
}

void frmConfig::mouseReleaseEvent(QMouseEvent *e)
{
    mousePressed = false;
}

void frmConfig::mousePressEvent(QMouseEvent *e)
{
//     if (e->button() == Qt::LeftButton) {
//         mousePressed = true;
//         mousePoint = e->globalPos() - this->pos();
//         e->accept();
//     }
}

void frmConfig::InitStyle()
{
    this->setProperty("Form", true);
    /* 窗体居中显示 */
//    myHelper::FormInCenter(this, myApp::DeskWidth, myApp::DeskHeight);
//    this->mousePressed = false;
    /* 设置窗体标题栏隐藏 */
//     this->setWindowFlags(Qt::FramelessWindowHint |
//                          Qt::WindowSystemMenuHint |
//                          Qt::WindowMinMaxButtonsHint);
    //设置图形字体
//    IconHelper::Instance()->SetIcon(ui->lab_Ico, QChar(0xf03d), 11);
//    IconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d), 10);
    //关联关闭按钮
    connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void frmConfig::InitForm()
{
    ui.txtAppTitle->setText(QString::fromLocal8Bit(myApp::AppTitle));
    ui.txtNVRType->setText(QString::fromLocal8Bit(myApp::NVRType));
    ui.txtIPCType->setText(QString::fromLocal8Bit(myApp::IPCType));
    ui.txtNVRType->setCursorPosition(0);
    ui.txtIPCType->setCursorPosition(0);

    ui.btnUseVideoOffLineCheck->SetCheck(myApp::UseVideoOffLineCheck);
    for (int i = 5; i <= 60; i = i + 5) {
        ui.cboxVideoOffLineCheckInterval->addItem(QString("%1").arg(i));
    }
    ui.cboxVideoOffLineCheckInterval->setCurrentIndex(ui.cboxVideoOffLineCheckInterval->findText(QString("%1").arg(myApp::VideoOffLineCheckInterval)));

    for (int i = 100; i <= 3000; i = i + 100) {
        ui.cboxDelayTime->addItem(QString("%1").arg(i));
    }
    ui.cboxDelayTime->setCurrentIndex(ui.cboxDelayTime->findText(QString("%1").arg(myApp::VideoDelayTime)));

    ui.cboxRtspType->setCurrentIndex(myApp::RtspType);
    ui.btnAutoRun->SetCheck(myApp::AutoRun);
    ui.btnAutoPoll->SetCheck(myApp::AutoPoll);
    ui.cboxPollType->setCurrentIndex(myApp::PollType);

    ui.cboxPollSleep->addItem("0");
    for (int i = 100; i <= 2000; i = i + 100)
    {
        ui.cboxPollSleep->addItem(QString("%1").arg(i));
    }
    ui.cboxPollSleep->setCurrentIndex(ui.cboxPollSleep->findText(QString("%1").arg(myApp::PollSleep)));

    for (int i = 10; i <= 120; i = i + 10)
    {
        ui.cboxPollInterval->addItem(QString("%1").arg(i));
    }
    ui.cboxPollInterval->setCurrentIndex(ui.cboxPollInterval->findText(QString("%1").arg(myApp::PollInterval)));
}

void frmConfig::on_btnOk_clicked()
{
    QString AppTitle = ui.txtAppTitle->text();
    QString NVRType = ui.txtNVRType->text();
    QString IPCType = ui.txtIPCType->text();
    QString UseVideoOffLineCheck = ui.btnUseVideoOffLineCheck->GetCheck();
    myApp::VideoOffLineCheckInterval = ui.cboxVideoOffLineCheckInterval->currentText().toInt();
    myApp::VideoDelayTime = ui.cboxDelayTime->currentText().toInt();
    myApp::RtspType = ui.cboxRtspType->currentIndex();
    myApp::AutoRun = ui.btnAutoRun->GetCheck();
    myApp::AutoPoll = ui.btnAutoPoll->GetCheck();
    myApp::PollType = ui.cboxPollType->currentIndex();
    myApp::PollInterval = ui.cboxPollInterval->currentText().toInt();
    myApp::PollSleep = ui.cboxPollSleep->currentText().toInt();

    //设置开机启动（只有windows系统才是这样设置开机启动）
#ifdef Q_OS_WIN
    QString strPath = QApplication::applicationFilePath();
    strPath = strPath.replace("/", "\\");
    if (myApp::AutoRun) {
        //myHelper::AutoRunWithSystem(true, "VM", strPath);
    } else {
        //myHelper::AutoRunWithSystem(false, "VM", strPath);
    }
#endif

    //调用保存配置文件函数
    myApp::WriteConfig();
    done(1);
    this->close();
}

void frmConfig::on_btnClearNVR_clicked()
{
//     if (myHelper::ShowMessageBoxQuesion("确定要清空NVR数据吗?") == 1) {
//         QSqlQuery query;
//         QString sql = "delete from [NVRInfo] where [NVRID]!='000255'";
//         query.exec(sql);
//         myHelper::ShowMessageBoxInfo("清空NVR数据成功!");
//     }
}

void frmConfig::on_btnClearIPC_clicked()
{
//     if (myHelper::ShowMessageBoxQuesion("确定要清空IPC数据吗?") == 1) {
//         QSqlQuery query;
//         QString sql = "delete from [IPCInfo]";
//         query.exec(sql);
//         myHelper::ShowMessageBoxInfo("清空IPC数据成功!");
//     }
}

void frmConfig::on_btnClearPoll_clicked()
{

}

void frmConfig::on_btnClearAll_clicked()
{

}
