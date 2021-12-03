#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <windows.h>
#include "dbt.h"
#include "comchange.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 第二种方法
    ComChange::getInstance()->setHWND((HWND)this->winId());
    connect(ComChange::getInstance(), &ComChange::comStatus, this, &Widget::on_comStatus);
    ui->comboBox->addItems(ComChange::getAvailablePort());
}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief               第一种方法
 * @param eventType
 * @param message
 * @param result
 * @return
 */
bool Widget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = reinterpret_cast<MSG*>(message);
    if(msg->message == WM_DEVICECHANGE)                // 通知应用程序设备或计算机的硬件配置发生更改。
    {
        PDEV_BROADCAST_HDR lpdb = (PDEV_BROADCAST_HDR)msg->lParam;
        switch (msg->wParam)
        {
        case DBT_DEVICEARRIVAL:             // 插入
        {
            if (lpdb->dbch_devicetype == DBT_DEVTYP_PORT)           // 设备类型为串口
            {
                PDEV_BROADCAST_PORT lpdbv = (PDEV_BROADCAST_PORT)lpdb;
                QString strName = QString::fromWCharArray(lpdbv->dbcp_name);  //插入的串口名
                qDebug() << strName;
            }
            break;
        }
        case DBT_DEVICEREMOVECOMPLETE:      // 拔出
        {
            if (lpdb->dbch_devicetype == DBT_DEVTYP_PORT)           // 设备类型为串口
            {
                PDEV_BROADCAST_PORT lpdbv = (PDEV_BROADCAST_PORT)lpdb;
                QString strName = QString::fromWCharArray(lpdbv->dbcp_name);  //拔出的串口名
                qDebug() << strName;
            }
            break;
        }
        default:
            break;
        }
    }

    return false;
}

void Widget::on_comStatus(QString name, bool flag)
{
    if(flag)
    {
        ui->comboBox->addItem(name);
    }
    else
    {
        ui->comboBox->removeItem(ui->comboBox->findText(name));
    }
}

