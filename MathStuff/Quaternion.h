//
// Created by Collin on 1/7/2022.
//

#ifndef MATHSTUFF_QUATERNION_H
#define MATHSTUFF_QUATERNION_H

#include "Vector3.h"
#include <vector>

class Quaternion {
private:
    double _r = 0, _x = 0, _y = 0, _z = 0;

public:
    const double &r = _r, &x = _x, &y = _y, &z = _z;

    Quaternion() = delete;
    Quaternion(double r, double x, double y, double z);
    Quaternion(const Quaternion& other);

    Quaternion& operator=(const Quaternion& other);

    Quaternion operator+(const Quaternion& other) const;
    Quaternion operator-(const Quaternion& other) const;
    Quaternion operator*(const Quaternion& other) const;
    Quaternion operator*(const double& value) const;
    Quaternion operator/(const double& value) const;

    Quaternion& operator+=(const Quaternion& other);
    Quaternion& operator-=(const Quaternion& other);
    Quaternion& operator*=(const Quaternion& other);
    Quaternion& operator*=(const double& value);
    Quaternion& operator/=(const double& value);

    Quaternion conjugate() const;
    double magnitude() const;


    static Quaternion makeFromAxisAngle(const Vector3& axis, const double& angle);//angle in radians
    static Quaternion makeFromAxisAngle(const double& x, const double& y, const double& z, const double& angle);//angle in radians
    static Quaternion angleBetweenVectors(const Vector3& v1, const Vector3& v2);
    static Quaternion chainRotations(const std::vector<Quaternion>& list);//rotations occur in the same order as the list

    static const Quaternion Identity;
    static const Quaternion Zero;

    void print() const;
    void printAngleAxis() const;

    Vector3 applyRotation(const Vector3& vector) const;
};


#endif //MATHSTUFF_QUATERNION_H
