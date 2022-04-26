#ifndef CHILD_H
#define CHILD_H

#include <QObject>
#include<QString>
#include<QDebug>
class Child : public QObject
{
    Q_OBJECT
public:
    explicit Child(QObject *parent = nullptr);

    const QString &name() const;
    void setName(const QString &newName);

signals:
private:
    QString m_name;

};

#endif // CHILD_H
