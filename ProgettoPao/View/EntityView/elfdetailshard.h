#ifndef ELFDETAILSHARD_H
#define ELFDETAILSHARD_H

#include "humanoiddetailshard.h"
#include <QObject>
#include <QWidget>

class ElfDetailShard : public HumanoidDetailShard
{
public:
    ElfDetailShard(Elf* e, QWidget *parent);
};

#endif // ELFDETAILSHARD_H
