#ifndef TODOLIST_H
#define TODOLIST_H

#include <QObject>

//18

class ToDoList : public QObject
{
    Q_OBJECT
public:
    explicit ToDoList(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TODOLIST_H
