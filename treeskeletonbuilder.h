#ifndef TREESKELETONBUILDER_H
#define TREESKELETONBUILDER_H

#include "basefunctionsystem.h"

class TreeSkeletonBuilder
{
public:
    TreeSkeletonBuilder(std::shared_ptr<BaseFunctionSystem> func, size_t it_num);
    ~TreeSkeletonBuilder() = default;

    std::shared_ptr<TreeSkeleton> build(std::shared_ptr<TreeSegment> seg) const;
private:
    std::shared_ptr<BaseFunctionSystem> _func;
    size_t _it_num;
};

#endif // TREESKELETONBUILDER_H
