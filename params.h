#ifndef PARAMS_H
#define PARAMS_H

#include <QColor>

#include "vec3i.h"

struct TreeParams {
    QColor color;
    float height;
    float width;
    int branch_type;
    int iter_count;
    double cap;
};

struct LeafParams {
    QColor color;
    int size;
    int leaf_type;
};

struct AreaParams {
    Vec3i<float> center;
    int rad;
    int count;
};


#endif // PARAMS_H
