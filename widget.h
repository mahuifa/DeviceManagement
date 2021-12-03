#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

    void on_comStatus(QString name, bool flag);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
