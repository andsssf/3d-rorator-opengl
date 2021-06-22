#include "Rotator.h"
#include "GL/glew.h"
#include <math.h>

using namespace std;

void Rotator::draw() {

    vector<Point> beforLine = line;
    vector<Point> afterLine = rotateLine(beforLine, (2 * M_PI / count));
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < beforLine.size() - 1; j++) {
            drawFace(beforLine[j], afterLine[j], afterLine[j+1], beforLine[j+1]);
        }
        beforLine = afterLine;
        afterLine = rotateLine(beforLine, (2 * M_PI / count));
    }
}

void Rotator::drawFace(Point p1, Point p2, Point p3, Point p4) {
    Point n = cross((p2 - p1), (p4 - p2));
    n.norm();
    
    // 画出面的法向量
    // glBegin(GL_LINES);
    // glColor3f(1, 0, 0);
    // Point b = p4;
    // Point e = b + n * 0.5;
    // glVertex3f(b.x, b.y, b.z);
    // glVertex3f(e.x, e.y, e.z);
    // glEnd();

    glBegin(GL_QUADS);
    glColor3f(ROTATOR_COLOR);
    // 设置法向量
    glNormal3f(n.x, n.y, n.z);

    glVertex3f(p1.x, p1.y, p1.z);
    glVertex3f(p2.x, p2.y, p2.z);
    glVertex3f(p3.x, p3.y, p3.z);
    glVertex3f(p4.x, p4.y, p4.z);
    glEnd();

}

vector<Point> Rotator::rotateLine(const vector<Point> &line, float angle) {
    vector<Point> result;
    for (Point p : line) {
        Point r = p;
        r.z = cos(angle) * p.z - sin(angle) * p.x;
        r.x = sin(angle) * p.z + cos(angle) * p.x;
        result.push_back(r);
    }
    return result;
}