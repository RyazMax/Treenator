#include "hondatreegenerator.h"

void HondaTreeGenerator::set_base(const TreeSegment &seg)
{
    if (_sk) {
        throw "Model not got";
    } else {
        _sk = std::shared_ptr<TreeSkeleton>(new TreeSkeleton(seg));
    }
}

void HondaTreeGenerator::generate(int seed)
{
    for (auto it = _sk->begin(); it != _sk->end(); ++it) {
        //TODO _sk->back();
    }
}

std::shared_ptr<TreeSkeleton> HondaTreeGenerator::get()
{
    if (!_sk) {
        throw "There is no model";
    } else {
        return _sk;
    }
}
