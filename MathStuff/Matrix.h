//
// Created by Collin on 1/7/2022.
//

#ifndef MATHSTUFF_MATRIX_H
#define MATHSTUFF_MATRIX_H

#include <vector>

class Matrix;
#include "Vector3.h"

class Matrix {
private:
    std::vector<std::vector<double>> values;
    int _columns = 0, _rows = 0;

public:
    enum VectorType{
        ROW, COLUMN
    };

    const int &columns = _columns, &rows = _rows;


    Matrix() = delete;
    Matrix(const Matrix& other);
    Matrix(std::vector<std::vector<double>> values);
    Matrix(int rows, int columns);
    Matrix(const Vector3& vector, VectorType orientation);

    Matrix& operator=(const Matrix& other);


    Matrix operator*(const Vector3& vector) const;//matrix by column vector (Result is a vertical matrix)

    Matrix operator*(const Matrix& other) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);

    double get(int row, int column) const;

    void print() const;
};


#endif //MATHSTUFF_MATRIX_H
