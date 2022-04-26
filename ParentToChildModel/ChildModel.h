#ifndef CHILDMODEL_H
#define CHILDMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<QList>
#include<QDebug>
#include"Child.h"

class ChildModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ChildModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const;
    void init();
     Q_INVOKABLE Child* getchild(int index);

    const QString &fathername() const;
    void setFathername(const QString &newFathername);

private:
    QList<Child*> m_child;
    QString m_fathername;
};

#endif // CHILDMODEL_H
