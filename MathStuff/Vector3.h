//
// Created by Collin on 1/7/2022.
//

#ifndef MATHSTUFF_VECTOR3_H
#define MATHSTUFF_VECTOR3_H

class Vector3;
#include "Matrix.h"

class Vector3 {
private:
    double _x = 0, _y = 0, _z = 0;

public:

    const double &x = _x, &y = _y, &z = _z;

    Vector3();
    Vector3(const Vector3& vector);
    Vector3(double x, double y, double z);
    Vector3(const Matrix& matrix);


    Vector3& operator=(const Vector3& other);

    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    double operator*(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;

    Vector3 operator*(const double& value) const;
    Vector3 operator/(const double& value) const;


    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(const double& value);
    Vector3& operator/=(const double& value);

    Vector3 multiplyElementWise(const Vector3& other) const;
    bool lessThanElementWise(const Vector3& other) const;//true is all elements are less


    Matrix operator*(const Matrix& matrix) const;//row vector by matrix (result is a horizontal matrix)

    double magnitude() const;

    void print() const;
};


#endif //MATHSTUFF_VECTOR3_H
