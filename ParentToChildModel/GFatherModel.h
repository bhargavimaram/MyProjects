#ifndef GFATHERMODEL_H
#define GFATHERMODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include<QDebug>
#include<FatherModel.h>

class GFatherModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit GFatherModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    virtual QHash<int,QByteArray> roleNames() const;

    Q_INVOKABLE FatherModel* getfather(int index);
    void init();
private:
    QList<FatherModel*> m_gfather;

};

#endif // GFATHERMODEL_H
