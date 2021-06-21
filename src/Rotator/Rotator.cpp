#include "Rotator.h"
#include "GL/glew.h"
#include <iostream>
#include <math.h>

using namespace std;

void Rotator::draw() {

    vector<Point> drawingLine = line;
    for (int i = 0; i < count; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(ROTATOR_COLOR);
        for (Point p : drawingLine) {
            glVertex3f(p.x, p.y, p.z);
            // cout << sqrt(pow(p.x, 2) + pow(p.z, 2)) << endl;
        } 
        glEnd();
        drawingLine = rotateLine(line, (2 * M_PI / count) * (float)(i + 1));
    }
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