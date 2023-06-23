#ifndef AINUDETAILSHARD_H
#define AINUDETAILSHARD_H

#include "entitydetailshard.h"
#include <QObject>
#include <QWidget>

class AinuDetailShard : public EntityDetailShard
{
public:
    AinuDetailShard(Ainu* e, QWidget *parent);
};

#endif // AINUDETAILSHARD_H
