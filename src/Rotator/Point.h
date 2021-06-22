class Point {
    public:
    Point(float x, float y, float z = 0.0f): x(x), y(y), z(z) {};
    Point(): x(0), y(0), z(0) {};
    Point operator-(const Point &other);
    Point operator+(const Point &other);
    void norm();
    float x, y, z;
};

Point cross(const Point &a, const Point &b);
Point operator*(const Point &p, float num);
float operator*(const Point &a, const Point &b);