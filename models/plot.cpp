#include "plot.h"

<<<<<<< HEAD
Plot::Plot(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant Plot::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex Plot::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex Plot::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int Plot::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int Plot::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant Plot::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
=======
Plot::Plot()
{

>>>>>>> 62ffced7a03b4bcf911f1b212369ade8808337d3
}
