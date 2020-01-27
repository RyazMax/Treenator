#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

#include "Exceptions/matrixexception.h"

class Matrix
{
public:
    Matrix(size_t n, size_t m);
    Matrix(std::initializer_list<std::initializer_list<float>> list);
    Matrix(const Matrix &other);
    Matrix(Matrix &&other);

    ~Matrix() = default;

    Matrix& operator=(const Matrix &right);
    Matrix& operator=(Matrix &&right);

    Matrix operator*(const Matrix &right) const;
    Matrix operator+(const Matrix &right) const;

    Matrix& operator+=(const Matrix &right);
    Matrix& operator*=(const Matrix &right);

    std::vector<float> &operator[](size_t i);
    const std::vector<float> &operator[](size_t i) const;
private:
    std::vector<std::vector<float>> _rows;

    size_t _n;
    size_t _m;
};

#endif // MATRIX_H
