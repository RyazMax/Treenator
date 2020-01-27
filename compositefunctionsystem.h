#ifndef COMPOSITEFUNCTIONSYSTEM_H
#define COMPOSITEFUNCTIONSYSTEM_H

#include "basefunctionsystem.h"

class CompositeFunctionSystem : public BaseFunctionSystem
{
public:
    CompositeFunctionSystem();

    virtual segment_arr_t transform(std::shared_ptr<TreeSegment> segment) const override;

    void add(std::shared_ptr<BaseFunctionSystem> func);
private:
    std::vector<std::shared_ptr<BaseFunctionSystem>> _funcs;
};

#endif // COMPOSITEFUNCTIONSYSTEM_H
