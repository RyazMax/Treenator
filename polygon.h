#ifndef POLYGON_H
#define POLYGON_H

#include <QColor>

#include "Model/modelvertsiterator.h"
#include "vec3i.h"

class Polygon
{
public:
    Polygon(const ModelVertsIterator &a, const ModelVertsIterator &b, const ModelVertsIterator &c, QColor color = Qt::gray, bool n_flag = true);
    Polygon(const Polygon &other);

    Verticle first();
    Verticle second();
    Verticle third();

    size_t fnum() const;
    size_t snum() const;
    size_t tnum() const;
    bool n_flag() const;

    QColor color() const;

    Vec3i<float> normal() const;

    ~Polygon() = default;
private:
    ModelVertsIterator _a;
    ModelVertsIterator _b;
    ModelVertsIterator _c;

    QColor _color;

    bool _n_flag; // Порядок обхода при вычислении нормали, если true то 1-е ребро * на 2-е
};

#endif // POLYGON_H
