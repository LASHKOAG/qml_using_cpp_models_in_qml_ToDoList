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
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    //12
    return 100;  //это даст нам 100 строк в модели
}

QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    //13
    switch (role) {
    case DoneRole:
        return QVariant(false);
    case DescriptionRole:
        return QVariant(QStringLiteral("Test description"));
    }
    return QVariant();
}

bool ToDoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
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
