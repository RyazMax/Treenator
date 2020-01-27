#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include <memory>

#include "basedrawerimp.h"

class BaseDrawer
{
public:
    BaseDrawer(std::shared_ptr<BaseDrawerImp> imp);
    virtual ~BaseDrawer() = default;

    virtual void flush() = 0;
    virtual void clean() = 0;
protected:
    std::shared_ptr<BaseDrawerImp> _imp;
};

#endif // BASEDRAWER_H
