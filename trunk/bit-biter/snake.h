#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QPoint>
#include <QList>

class Snake : public QObject
{
    Q_OBJECT
public:
    explicit Snake(QObject *parent = 0);
    QList<QPoint> *getBodySegments();

private:
    QList<QPoint> *bodySegments;
    bool isDead;

signals:

public slots:

};

#endif // SNAKE_H
