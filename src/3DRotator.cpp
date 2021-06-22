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

    // glEnable(GL_CULL_FACE);

    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

    GLfloat ambient[] = { .3f,.3f,.3f,1.f };
	GLfloat diffuse[] = { .7f,.7f,.7f,1.f };
	GLfloat specular[] = { .5f,.5f,.5f,1.f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    GLfloat position[] = { 5.0f,5.0f,0.f,1.f };
	glLightfv(GL_LIGHT0, GL_POSITION, position);


}

// 画坐标轴
void showCoordinateAxis() {
    
    glBegin(GL_LINES);
    // X
    glColor3f(1, 0, 0);
    glVertex3f(-2.f, 0, 0);
    glVertex3f(2.f, 0, 0);
    
    // Y
    glColor3f(0, 1, 0);
    glVertex3f(0, -2.f, 0);
    glVertex3f(0, 2.f, 0);

    // Z
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, -2.f);
    glVertex3f(0, 0, 2.f);

    glEnd();
}

float time = 0;
void render() {
    // 清除之前帧数据
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glPushMatrix();
    float cax = cos(time) * 5;
    float caz = sin(time) * 5;
    gluLookAt(cax, 2.5f, caz, 0, 0, 0, 0, 1, 0);
    time += 0.001;

    showCoordinateAxis();

    GLfloat green[] = { 0.0f,0.2f,0.1f,1.0f };
	GLfloat yellow[] = { 0.7f,0.6f,0.1f,1.0f };
	GLfloat white[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat gray[] = {0.2f, 0.2f, 0.2f, 1.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, gray);
	// 漫反射光
	glMaterialfv(GL_FRONT, GL_DIFFUSE , yellow);
	// 镜面反射光
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 10.0f);
    
    // 设置旋转体的母线顶点序列，从下到上设置
    // 72 指分段为72段
    // 调用draw函数完成绘制。

    Rotator({
        Point(0.1, 0),
        Point(1, 0),
        Point(1.1, 0.2),
        Point(1.25, 0.25),
        Point(1.25, 0.5),
        Point(1.1, 0.9),
        Point(0.9, 1.2),
        Point(0.8, 1.5),
        Point(0.85, 1.75),
        Point(1.0, 2)
    }, 72).draw();

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