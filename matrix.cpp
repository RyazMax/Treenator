#include "matrix.h"

Matrix::Matrix(size_t n, size_t m) : _n(n), _m(m)
{
    _rows = std::vector<std::vector<float>>(_n);
    for (unsigned int i = 0; i < _n; ++i) {
        _rows[i] = std::vector<float>(m, 0);
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<float>> list) :
    _rows(list.begin(),list.end())
{
    _n = _rows.size();
    _m = _rows[0].size();
}

Matrix::Matrix(const Matrix &other) : _n(other._n), _m(other._m), _rows(other._rows)
{

}

Matrix::Matrix(Matrix &&other) : _n(other._n), _m(other._m), _rows(other._rows)
{

}

Matrix& Matrix::operator=(const Matrix &right)
{
    this->_n = right._n;
    this->_m = right._m;
    this->_rows = right._rows;
    return *this;
}

Matrix& Matrix::operator=(Matrix &&right)
{
    this->_n = right._n;
    this->_m = right._m;
    this->_rows = right._rows;
    return *this;
}

Matrix Matrix::operator*(const Matrix &right) const
{
    Matrix res(this->_n, right._m);

    // TODO: переписать на Алгоритм Винограда
    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < right._m; ++j) {
            for (int k = 0; k < _m; ++k) {
                res._rows[i][j] += this->_rows[i][k] * right._rows[k][j];
            }
        }
    }
    return res;
}

Matrix Matrix::operator+(const Matrix &right) const
{
    if (this->_n != right._n || this->_m != right._m) {
        throw MatrixException("Sizes of matrix are not equal");
    }

    Matrix res(this->_n, this->_m);

    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < _m; ++j) {
            res._rows[i][j] = this->_rows[i][j] + right._rows[i][j];
        }
    }
    return res;
}

Matrix &Matrix::operator+=(const Matrix &right)
{
    if (this->_n != right._n || this->_m != right._m) {
        throw MatrixException("Sizes of matrix are not equal");
    }

    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < _m; ++j) {
            this->_rows[i][j] = this->_rows[i][j] + right._rows[i][j];
        }
    }
    return *this;
}

std::vector<float> &Matrix::operator[](size_t i)
{
    if (i >= _n) {
        throw MatrixException("Reading besides the border");
    }
    return _rows[i];
}

const std::vector<float> &Matrix::operator[](size_t i) const
{
    if (i >= _n) {
        throw MatrixException("Reading besides the border");
    }
    return _rows[i];
}


