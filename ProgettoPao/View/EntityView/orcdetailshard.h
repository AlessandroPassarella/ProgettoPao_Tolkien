#ifndef ORCDETAILSHARD_H
#define ORCDETAILSHARD_H

#include "humanoiddetailshard.h"
#include <QObject>
#include <QWidget>

class OrcDetailShard : public HumanoidDetailShard
{
public:
    OrcDetailShard(Orc* o, QWidget *parent);
};

#endif // ORCDETAILSHARD_H
