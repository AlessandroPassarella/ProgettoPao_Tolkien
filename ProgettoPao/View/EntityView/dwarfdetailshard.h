#ifndef DWARFDETAILSHARD_H
#define DWARFDETAILSHARD_H

#include "humanoiddetailshard.h"
#include <QObject>
#include <QWidget>

class DwarfDetailShard : public HumanoidDetailShard
{
public:
    DwarfDetailShard(Dwarf* d, QWidget *parent);
};

#endif // DWARFDETAILSHARD_H
