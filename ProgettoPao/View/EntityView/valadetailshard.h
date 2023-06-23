#ifndef VALADETAILSHARD_H
#define VALADETAILSHARD_H

#include "ainudetailshard.h"
#include <QObject>
#include <QWidget>

class ValaDetailShard : public AinuDetailShard
{
public:
    ValaDetailShard(Vala* v, QWidget *parent);
};

#endif // VALADETAILSHARD_H
