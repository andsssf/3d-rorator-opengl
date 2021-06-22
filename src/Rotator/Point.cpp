#include "Point.h"
#include <math.h>

Point Point::operator-(const Point &other) {
    return Point(x - other.x, y - other.y, z - other.z);
}

Point Point::operator+(const Point &other) {
    return Point(x + other.x, y + other.y, z + other.z);
}

void Point::norm() {
    float length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    x /= length;
    y /= length;
    z /= length;
}

Point operator*(const Point &p, float num) {
    return Point(p.x * num, p.y * num, p.z * num);
}

Point cross(const Point &a, const Point &b) {
    Point r(
        a.y * b.z - a.z * b.y, 
        -a.x * b.z + a.z * b.x, 
        a.x * b.y - a.y * b.x
    );
    return r;
}

float operator*(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}