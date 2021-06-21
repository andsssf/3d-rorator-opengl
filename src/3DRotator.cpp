#include <iostream>
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "Rotator/Rotator.h"
#include <math.h>

using namespace std;

// 初始化参数
void init();
// 绘制坐标轴
void showCoordinateAxis();
void render();

// 窗口大小变化回调函数
void reshape(int w, int h);

void idle() {
    glutPostRedisplay();
}

int main(int argc,char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
 
    // 初始化窗口
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Rotator Demo");
 
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutIdleFunc(idle);
 
    // 开始主循环绘制
    glutMainLoop();
    return 0;
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(0.1, 0.1, 0.4, 0.0);
    glShadeModel(GL_SMOOTH);
}

// 画坐标轴
void showCoordinateAxis() {
    
    glBegin(GL_LINES);
    // X
    glColor3f(1, 0, 0);
    glVertex3f(-0.2f, 0, 0);
    glVertex3f(0.2f, 0, 0);
    
    // Y
    glColor3f(0, 1, 0);
    glVertex3f(0, -0.2f, 0);
    glVertex3f(0, 0.2f, 0);

    // Z
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, -0.2f);
    glVertex3f(0, 0, 0.2f);

    glEnd();
}

float time = 0;
void render() {
    // 清除之前帧数据
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glPushMatrix();
    float cax = cos(time);
    float caz = sin(time);
    gluLookAt(cax, 1, caz, 0, 0, 0, 0, 1, 0);
    time += 0.001;

    showCoordinateAxis();

    Rotator({Point(0.3, 0.3), Point(0.2, 0.15), Point(0.2, -0.15), Point(0.3, -0.3)}).draw();


    glFlush();
    glutSwapBuffers();

    glPopMatrix();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 0.01, 100000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}