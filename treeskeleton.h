#ifndef TREESKELETON_H
#define TREESKELETON_H

#include <vector>
#include <list>
#include <memory>

#include "treesegment.h"

typedef std::vector<std::shared_ptr<TreeSegment>> segment_arr_t;

class TreeSkeleton
{
public:
    TreeSkeleton(std::shared_ptr<TreeSegment> seg);
    ~TreeSkeleton() = default;

    std::list<segment_arr_t>::iterator begin();
    std::list<segment_arr_t>::iterator end();
    std::list<segment_arr_t>::iterator last();

    void add_segments(const segment_arr_t &segs);

private:
    std::list<segment_arr_t> _seg_list;
};

#endif // TREESKELETON_H
