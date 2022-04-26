#ifndef GRANDMODEL_H
#define GRANDMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<QDebug>
#include"FatherModel.h"

class GrandModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit GrandModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const;
    Q_INVOKABLE FatherModel* getgrandf(int index);
    void init();
private:
    QList<FatherModel*> m_gfather;

};

#endif // GRANDMODEL_H
