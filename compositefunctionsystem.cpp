#include "compositefunctionsystem.h"

CompositeFunctionSystem::CompositeFunctionSystem()
{

}

segment_arr_t CompositeFunctionSystem::transform(std::shared_ptr<TreeSegment> segment) const
{
    segment_arr_t result;
    for (auto it = _funcs.begin(); it != _funcs.end(); ++it) {
        segment_arr_t tmp = (*it)->transform(segment);
        for (std::shared_ptr<TreeSegment> seg : tmp) {
            result.push_back(seg);
        }
    }
    return result;
}

void CompositeFunctionSystem::add(std::shared_ptr<BaseFunctionSystem> func)
{
    _funcs.push_back(func);
}
