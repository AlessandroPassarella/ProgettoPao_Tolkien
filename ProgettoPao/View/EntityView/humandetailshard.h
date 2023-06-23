#ifndef HUMANDETAILSHARD_H
#define HUMANDETAILSHARD_H

#include "humanoiddetailshard.h"
#include <QObject>
#include <QWidget>

class HumanDetailShard : public HumanoidDetailShard
{
public:
    HumanDetailShard(Human* h, QWidget *parent);
};

#endif // HUMANDETAILSHARD_H
