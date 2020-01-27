#ifndef BASEFUNCTIONSYSTEM_H
#define BASEFUNCTIONSYSTEM_H

#include "matrix3.h"
#include "treeskeleton.h"

class BaseFunctionSystem
{
public:
    BaseFunctionSystem() = default;
    virtual ~BaseFunctionSystem() = default;
    virtual segment_arr_t transform(std::shared_ptr<TreeSegment> segment) const = 0;
};

class HondaFunctionSystem : public BaseFunctionSystem
{
public:
    HondaFunctionSystem(double kw, double kh);
    ~HondaFunctionSystem() = default;

    segment_arr_t transform(std::shared_ptr<TreeSegment> segment) const override;
private:

    float get_alpha() const;
    double _kw;
    double _kh;
};

class TernaryFunctionSystem : public BaseFunctionSystem
{
public:
    TernaryFunctionSystem(double kw, double kh);
    ~TernaryFunctionSystem() = default;

    segment_arr_t transform(std::shared_ptr<TreeSegment> segment) const override;
private:

    float get_alpha() const;
    double _kw;
    double _kh;
};

#endif // BASEFUNCTIONSYSTEM_H
