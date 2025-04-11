#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QDateTime>

class Order
{
public:
    Order(int id = 0,
          const QString& customer = "",
          const QString& destination = "",
          double weight = 0,
          double volume = 0,
          const QString& status = "待发货");

    // Getter方法
    int id() const;
    QString customer() const;
    QString destination() const;
    double weight() const;
    double volume() const;
    QString status() const;
    QDateTime createTime() const;
    QDateTime updateTime() const;

private:
    int m_id;
    QString m_customer;
    QString m_destination;
    double m_weight;
    double m_volume;
    QString m_status;
    QDateTime m_createTime;
    QDateTime m_updateTime;
};

#endif // ORDER_H
