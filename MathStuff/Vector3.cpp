//
// Created by Collin on 1/7/2022.
//

#include "Vector3.h"
#include <stdexcept>
#include <cmath>
#include <iostream>

Vector3::Vector3() {
    _x = _y = _z = 0;
}

Vector3::Vector3(const Vector3 &vector) {
    _x = vector.x;
    _y = vector.y;
    _z = vector.z;
}

Vector3::Vector3(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

Vector3::Vector3(const Matrix &matrix) {
    if(!(matrix.rows == 3 && matrix.columns == 1 || matrix.rows == 1 && matrix.columns == 3)){
        throw std::runtime_error("Cannot make a 3D vector using a matrix with more than three elements.");
    }

    if(matrix.rows == 3){
        _x = matrix.get(0, 0);
        _y = matrix.get(1, 0);
        _z = matrix.get(2, 0);
    }

    if(matrix.columns == 3){
        _x = matrix.get(0, 0);
        _y = matrix.get(0, 1);
        _z = matrix.get(0, 2);
    }
}

Vector3 &Vector3::operator=(const Vector3 &other) {
    _x = other.x;
    _y = other.y;
    _z = other.z;

    return *this;
}

Vector3 Vector3::operator+(const Vector3 &other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

double Vector3::operator*(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3 &other) const {
    return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

Vector3 Vector3::operator*(const double &value) const {
    return Vector3(value * x, value * y, value * z);
}

Vector3 Vector3::operator/(const double &value) const {
    return Vector3(x / value, y / value, z / value);
}

Vector3 &Vector3::operator+=(const Vector3 &other) {
    _x += other.x;
    _y += other.y;
    _z += other.z;

    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &other) {
    _x -= other.x;
    _y -= other.y;
    _z -= other.z;

    return *this;
}

Vector3 &Vector3::operator*=(const double &value) {
    _x *= value;
    _y *= value;
    _z *= value;

    return *this;
}

Vector3 &Vector3::operator/=(const double &value) {
    _x /= value;
    _y /= value;
    _z /= value;

    return *this;
}

Matrix Vector3::operator*(const Matrix &matrix) const {
    if(matrix.rows != 3){
        throw std::runtime_error("When multiplying a vector by a matrix the matrix must have 3 rows.");
    }
    std::vector<double> values;
    for(int column = 0; column < matrix.columns; column++){
        values.push_back(x * matrix.get(0, column) + y * matrix.get(1, column) + z * matrix.get(2, column));
    }

    return Matrix({values});
}

double Vector3::magnitude() const {
    return std::sqrt(x*x + y*y + z*z);
}

void Vector3::print() const {
    std::cout << x << ", " << y << ", " << z << std::endl;
}

