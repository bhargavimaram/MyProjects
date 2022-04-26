#ifndef MOVIE_H
#define MOVIE_H
#include <QObject>
#include<QString>
#include<QList>
#include<QDebug>
#include<QTimer>
struct MyStruct
{
    QString m_moviename;
    QString m_movieActor;
    float m_movierating;
    float m_movieCollection;
    Q_GADGET
    Q_PROPERTY(QString moviename MEMBER m_moviename);
    Q_PROPERTY(QString movieactor MEMBER m_movieActor);
    Q_PROPERTY(float movierating MEMBER m_movierating);
    Q_PROPERTY(float movieCollection MEMBER m_movieCollection);
};
Q_DECLARE_METATYPE(MyStruct)

class Movie : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MyStruct mystr READ getMyStruct WRITE setMyStruct NOTIFY myStructChanged);
     MyStruct mystr;
     MyStruct getMyStruct() const;
     void setMyStruct(MyStruct val);
     void init();
     MyStruct callMe(int indx);
public:
    explicit Movie(QObject *parent = nullptr);
signals:
     void myStructChanged(MyStruct str);
public slots:
     void updateData();
private:
     QList<MyStruct> m_movielist;
     QTimer *t=nullptr;
     QList<MyStruct>::iterator it;
     int count;
       int c=0;

};

#endif // MOVIE_H
