#include "order.h"

Order::Order(int id, const QString& customer, const QString& destination,
             double weight, double volume, const QString& status)
    : m_id(id), m_customer(customer), m_destination(destination),
    m_weight(weight), m_volume(volume), m_status(status),
    m_createTime(QDateTime::currentDateTime()),
    m_updateTime(QDateTime::currentDateTime())
{
}

int Order::id() const { return m_id; }
QString Order::customer() const { return m_customer; }
QString Order::destination() const { return m_destination; }
double Order::weight() const { return m_weight; }
double Order::volume() const { return m_volume; }
QString Order::status() const { return m_status; }
QDateTime Order::createTime() const { return m_createTime; }
QDateTime Order::updateTime() const { return m_updateTime; }
