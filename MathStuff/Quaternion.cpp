//
// Created by Collin on 1/7/2022.
//

#include "Quaternion.h"

#include <cmath>
#include <iostream>

const Quaternion Quaternion::Identity{1, 0, 0, 0};
const Quaternion Quaternion::Zero{0, 0, 0, 0};

Quaternion::Quaternion(double r, double x, double y, double z) {
    _r = r;
    _x = x;
    _y = y;
    _z = z;
}

Quaternion::Quaternion(const Quaternion &other) {
    _r = other.r;
    _x = other.x;
    _y = other.y;
    _z = other.z;
}

Quaternion &Quaternion::operator=(const Quaternion &other) {
    _r = other.r;
    _x = other.x;
    _y = other.y;
    _z = other.z;

    return *this;
}

Quaternion Quaternion::operator+(const Quaternion &other) const {
    return Quaternion(r + other.r, x + other.x, y + other.y, z + other.z);
}

Quaternion Quaternion::operator-(const Quaternion &other) const {
    return Quaternion(r - other.r, x - other.x, y - other.y, z - other.z);
}

Quaternion Quaternion::operator*(const Quaternion &other) const {
    const double &a1 = r, &b1 = x, &c1 = y, &d1 = z;
    const double &a2 = other.r, &b2 = other.x, &c2 = other.y, &d2 = other.z;
    return Quaternion(
            a1*a2 - b1*b2 - c1*c2 - d1*d2,
            a1*b2 + b1*a2 + c1*d2 - d1*c2,
            a1*c2 - b1*d2 + c1*a2 + d1*b2,
            a1*d2 + b1*c2 - c1*b2 + d1*a2
            );
}

Quaternion Quaternion::operator*(const double &value) const {
    return Quaternion(r * value, x * value, y * value, z * value);
}

Quaternion Quaternion::operator/(const double &value) const {
    return Quaternion(r / value, x / value, y / value, z / value);
}

Quaternion &Quaternion::operator+=(const Quaternion &other) {
    _r += other.r;
    _x += other.x;
    _y += other.y;
    _z += other.z;

    return *this;
}

Quaternion &Quaternion::operator-=(const Quaternion &other) {
    _r -= other.r;
    _x -= other.x;
    _y -= other.y;
    _z -= other.z;

    return *this;
}

Quaternion &Quaternion::operator*=(const Quaternion &other) {
    const double &a1 = r, &b1 = x, &c1 = y, &d1 = z;
    const double &a2 = other.r, &b2 = other.x, &c2 = other.y, &d2 = other.z;

    double tr = a1*a2 - b1*b2 - c1*c2 - d1*d2;
    double tx = a1*b2 + b1*a2 + c1*d2 - d1*c2;
    double ty = a1*c2 - b1*d2 + c1*a2 + d1*b2;
    double tz = a1*d2 + b1*c2 - c1*b2 + d1*a2;

    _r = tr;
    _x = tx;
    _y = ty;
    _z = tz;

    return *this;
}

Quaternion &Quaternion::operator*=(const double &value) {
    _r *= value;
    _x *= value;
    _y *= value;
    _z *= value;

    return *this;
}

Quaternion &Quaternion::operator/=(const double &value) {
    _r /= value;
    _x /= value;
    _y /= value;
    _z /= value;

    return *this;
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(r, -x, -y, -z);
}

double Quaternion::magnitude() const {
    return std::sqrt(r*r + x*x + y*y + z*z);
}

Quaternion Quaternion::makeFromAxisAngle(const Vector3 &axis, const double &angle) {
    double cos = std::cos(angle / 2);
    double sin = std::sin(angle / 2);
    Vector3 nAxis = axis / axis.magnitude() * sin;

    return Quaternion(cos, nAxis.x, nAxis.y, nAxis.z);
}

Quaternion Quaternion::makeFromAxisAngle(const double &x, const double &y, const double &z, const double &angle) {
    Vector3 axis(x, y, z);
    double cos = std::cos(angle / 2);
    double sin = std::sin(angle / 2);
    Vector3 nAxis = axis / axis.magnitude() * sin;

    return Quaternion(cos, nAxis.x, nAxis.y, nAxis.z);
}

Quaternion Quaternion::angleBetweenVectors(const Vector3 &v1, const Vector3 &v2) {
    Vector3 a = v1.cross(v2);
    Quaternion output(std::sqrt(std::pow(v1.magnitude(), 2) * std::pow(v2.magnitude(), 2)) + v1 * v2, a.x, a.y, a.x);
    return output / output.magnitude();
}

Quaternion Quaternion::chainRotations(const std::vector<Quaternion> &list) {
    Quaternion output{1, 0, 0, 0};

    for(auto iter = list.rbegin(); iter != list.rend(); iter++){
        output *= *iter;
    }

    return output;
}

void Quaternion::print() const {
    std::cout << r << ", " << x << ", " << y << ", " << z << std::endl;
}

void Quaternion::printAngleAxis() const {
    Vector3 axis(x, y, z);
    double mag = axis.magnitude();
    axis /= mag;
    double angle = 2 * std::acos(r);

    std::cout << "Angle: " << angle << ", Axis: ";
    axis.print();
}

Vector3 Quaternion::applyRotation(const Vector3 &vector) const {
    Quaternion temp(0, vector.x, vector.y, vector.z);
    temp = *this * temp * this->conjugate();
    return Vector3(temp.x, temp.y, temp.z);
}

