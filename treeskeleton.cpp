#include "treeskeleton.h"


TreeSkeleton::TreeSkeleton(std::shared_ptr<TreeSegment> seg)
{
    _seg_list.push_back(segment_arr_t{seg});
}

std::list<segment_arr_t>::iterator TreeSkeleton::begin()
{
    return _seg_list.begin();
}

std::list<segment_arr_t>::iterator TreeSkeleton::end()
{
    return _seg_list.end();
}

std::list<segment_arr_t>::iterator TreeSkeleton::last()
{
    return --_seg_list.end();
}

void TreeSkeleton::add_segments(const segment_arr_t &segs)
{
    _seg_list.push_back(segs);
}
