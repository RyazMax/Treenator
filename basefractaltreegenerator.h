#ifndef BASEFRACTALTREEGENERATOR_H
#define BASEFRACTALTREEGENERATOR_H

#include <memory>

#include "treeskeleton.h"

class BaseFractalTreeGenerator
{
public:
    BaseFractalTreeGenerator() = default;
    virtual ~BaseFractalTreeGenerator() = default;

    virtual void set_base(const TreeSegment &seg) = 0;
    virtual void generate(int seed) = 0;
    virtual std::shared_ptr<TreeSkeleton> get() = 0;
};

#endif // BASEFRACTALTREEGENERATOR_H
