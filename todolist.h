#ifndef TODOLIST_H
#define TODOLIST_H

#include <QObject>

//20
#include <QVector>

//18
// этот класс должен уметь:
// изменять
// добавлять элемент
// удалять элемент

//У каждого элемента в списке (в нашем случае) есть два свойства:
// это роли. Элемент это совокупность CheckBox и TextField

//19
struct ToDoItem {
    bool done;
    QString description;
};

class ToDoList : public QObject
{
    Q_OBJECT
public:
    explicit ToDoList(QObject *parent = nullptr);

    //22 позволит изменять данные списка дел
    bool setItemAt(int index, const ToDoItem &item);

signals:
    //25
    void preItemAppended();
    //26
    void postItemAppended();

    //27
    void preItemRemoved(int index);
    //28
    void postItemRemoved();

    //модель будет уведомлена до изменения и после

public slots:
    //23
    void appendItem();
    //24
    void removeCompletedItems();


private:
    //21
    QVector<ToDoItem> mItems;
};

#endif // TODOLIST_H
