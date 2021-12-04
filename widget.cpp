#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "comchange.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_port = new PortTest();
    m_mouseKey = new MouseKeyTest();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_but_port_clicked()
{
    m_port->show();
}

void Widget::on_pushButton_2_clicked()
{
    m_mouseKey->show();
}

