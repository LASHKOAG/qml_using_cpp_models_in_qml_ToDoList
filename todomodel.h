#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractListModel>

//43
class ToDoList;

class ToDoModel : public QAbstractListModel
{
    Q_OBJECT
    //44
    //Q_PROPERTY(ToDoList *list READ list WRITE setList NOTIFY listChanged)
    //45
    Q_PROPERTY(ToDoList *list READ list WRITE setList)

public:
    explicit ToDoModel(QObject *parent = nullptr);

    //9
    enum {
        DoneRole = Qt::UserRole,
        DescriptionRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    //10
    virtual QHash<int, QByteArray> roleNames() const override;

    ToDoList *list() const;
    void setList(ToDoList *list);

private:
    //46
    ToDoList *mList; //47 make refactor -> setter and getter
};

#endif // TODOMODEL_H
