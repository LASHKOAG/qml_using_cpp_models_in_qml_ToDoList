#include "todomodel.h"

//48
#include "todolist.h"

//49
//mList(nullptr) in Constructor

ToDoModel::ToDoModel(QObject *parent)
    : QAbstractListModel(parent), mList(nullptr)
{
}

int ToDoModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    //51
    //if (parent.isValid())
    if (parent.isValid() || !mList)
        return 0;

    //52
    // FIXME: Implement me!
    //12
    //return 100;  //это даст нам 100 строк в модели
    return mList->items().size();
}

QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    //53
    //if (!index.isValid())
    if (!index.isValid() || !mList)
        return QVariant();

    // FIXME: Implement me!
    //54
    const ToDoItem item = mList->items().at(index.row());

    //13
//    switch (role) {
//    case DoneRole:
//        return QVariant(false);
//    case DescriptionRole:
//        return QVariant(QStringLiteral("Test description"));
//    }
//    return QVariant();

    //55
    switch (role) {
    case DoneRole:
        return QVariant(item.done);
    case DescriptionRole:
        return QVariant(item.description);
    }
    return QVariant();
}

bool ToDoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //56
    if(!mList){
        return false;
    }

    //57
    ToDoItem item = mList->items().at(index.row());

    //58
    switch (role) {
    case DoneRole:
        item.done = value.toBool();
        break;
    case DescriptionRole:
        item.description = value.toString();
        break;
    }

    //59
    //if (data(index, role) != value) {
    if(mList->setItemAt(index.row(), item)){
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ToDoModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

//11
QHash<int, QByteArray> ToDoModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DoneRole] = "done";
    names[DescriptionRole] = "description";

    return names;
}

ToDoList *ToDoModel::list() const
{
    return mList;
}


//50
void ToDoModel::setList(ToDoList *list)
{
    beginResetModel();

    if(mList){
        mList->disconnect(this);
    }

    mList = list;

    if(mList){
        connect(mList, &ToDoList::preItemAppended, this, [=](){
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &ToDoList::postItemAppended, this, [=](){
            endInsertRows();
        });
        connect(mList, &ToDoList::preItemRemoved, this, [=](int index){
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &ToDoList::postItemRemoved, this, [=](){
            endRemoveRows();
        });
    }

    endResetModel();
}
