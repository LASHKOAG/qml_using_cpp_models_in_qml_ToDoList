#include "todolist.h"

ToDoList::ToDoList(QObject *parent) : QObject(parent)
{
    //39 добавим для старта
    mItems.append({true, QStringLiteral("Wash the car")});
    mItems.append({false, QStringLiteral("Fix the sink")});
}

//30
QVector<ToDoItem> ToDoList::items() const
{
    return mItems;
}


//37
void ToDoList::appendItem()
{
    emit preItemAppended();

    ToDoItem item;
    item.done = false;
    mItems.append(item);

    emit postItemAppended();
}


//38
void ToDoList::removeCompletedItems()
{
    for(int i = 0; i < mItems.size();){
        if(mItems.at(i).done){
            emit preItemRemoved(i);
            mItems.removeAt(i);
            emit postItemRemoved();
        }else {
            ++i;
        }
    }
}


//31
//успех в случае удачной попытки изменения или неуспех
bool ToDoList::setItemAt(int index, const ToDoItem &item)
{
    //32 проверим, что index не выходит за рамки
    if(index < 0 || index >= mItems.size()){
        return false;
    }

    //33 берем из вектора объект с ролями
    const ToDoItem &oldItem = mItems.at(index);

    //34 если вносимые данные на самом деле не меняют тех, что были, то ничего и не надо делать
    if(item.done == oldItem.done && item.description == oldItem.description){
        return false;
    }

    //35
    mItems[index] = item;

    //36
    return  true;
}
