    #include "treeskeletonbuilder.h"

std::shared_ptr<TreeSkeleton> TreeSkeletonBuilder::build(std::shared_ptr<TreeSegment> seg) const
{
    std::shared_ptr<TreeSkeleton> tree(new TreeSkeleton(seg));

    for (size_t i = 0; i < _it_num; ++i) {
        segment_arr_t new_layer;
        segment_arr_t last_layer = *tree->last();

        for (auto it = last_layer.begin(); it != last_layer.end(); ++it) {
            segment_arr_t tmp = _func->transform(*it);
            for (auto it2 = tmp.begin(); it2 != tmp.end(); ++it2) {
                new_layer.push_back(*it2);
            }
        }
        tree->add_segments(new_layer);
    }
    return tree;
}

TreeSkeletonBuilder::TreeSkeletonBuilder(std::shared_ptr<BaseFunctionSystem> func, size_t it_num) :
    _func(func), _it_num(it_num)
{

}
