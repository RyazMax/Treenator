#ifndef COMPOBJITERATOR_H
#define COMPOBJITERATOR_H

#include <vector>
#include <memory>

#include "object3d.h"
#include "Exceptions/iteratorexception.h"

class CompObjIterator
{
public:
    CompObjIterator(std::vector<std::shared_ptr<Object3D>>& objs, size_t id = 0);
    ~CompObjIterator() = default;

    std::shared_ptr<Object3D> operator*();
    std::shared_ptr<Object3D> operator*() const;

    std::shared_ptr<Object3D> operator->();
    const std::shared_ptr<Object3D> operator->() const;

    CompObjIterator &operator++();
    CompObjIterator operator++(int);

    bool operator==(const CompObjIterator& other) const;
    bool operator!=(const CompObjIterator& other) const;

    CompObjIterator operator+(size_t delta) const;
    CompObjIterator operator-(size_t delta) const;
private:
    std::vector<std::shared_ptr<Object3D>>& _objs;
    size_t _id;
};

#endif // COMPOBJITERATOR_H
