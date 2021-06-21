class Point {
    public:
    Point(float x, float y, float z = 0.0f): x(x), y(y), z(z) {};
    Point(): x(0), y(0), z(0) {};
    float x, y, z;
};