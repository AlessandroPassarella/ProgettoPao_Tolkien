#ifndef HUMANOIDDETAILSHARD_H
#define HUMANOIDDETAILSHARD_H

#include "entitydetailshard.h"
#include <QObject>
#include <QWidget>

class HumanoidDetailShard : public EntityDetailShard
{
public:
    HumanoidDetailShard(Humanoid* h, QWidget *parent);
};

#endif // HUMANOIDDETAILSHARD_H
