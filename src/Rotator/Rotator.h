#include <vector>
#include "Point.h"

#define ROTATOR_COLOR 1, 1, 1

class Rotator {
    
    public:
    Rotator(const std::vector<Point> &line, int count = 36): line(line), count(count) {};
    void draw();
    
    private:
    void drawFace(Point p1, Point p2, Point p3, Point p4);  // 画四边面
    void drawFace(Point p1, Point p2, Point p3);            // 画三角面
    std::vector<Point> rotateLine(const std::vector<Point> &line, float angle);    // 将线按给定角度绕 Y 轴旋转
    std::vector<Point> line;    // 构成线的顶点集
    int count;  // 旋转分段数
};