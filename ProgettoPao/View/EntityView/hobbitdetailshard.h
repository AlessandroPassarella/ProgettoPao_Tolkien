#ifndef HOBBITDETAILSHARD_H
#define HOBBITDETAILSHARD_H

#include "humanoiddetailshard.h"
#include <QObject>
#include <QWidget>

class HobbitDetailShard : public HumanoidDetailShard
{
public:
    HobbitDetailShard(Hobbit* h, QWidget *parent);
};

#endif // HOBBITDETAILSHARD_H
