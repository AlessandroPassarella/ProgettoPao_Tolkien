#ifndef MAIADETAILSHARD_H
#define MAIADETAILSHARD_H

#include "ainudetailshard.h"
#include <QObject>
#include <QWidget>

class MaiaDetailShard : public AinuDetailShard
{
public:
    MaiaDetailShard(Maia* v, QWidget *parent);
};

#endif // MAIADETAILSHARD_H
