#include <windows.h>
#include <GL/freeglut.h>   // NuGet: freeglut 설치 필요
#pragma comment(lib, "freeglut.lib") // 자동 링크

float rotationAngle = 0.0f;

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // 배경 어둡게
    glEnable(GL_DEPTH_TEST);              // 깊이 버퍼 활성화
}

void drawWireTeapot() {
    glPushMatrix(); // 현재 행렬 저장
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Y축 회전
    glColor3f(0.0f, 1.0f, 1.0f); // 청록색 와이어프레임
    glutWireTeapot(0.5); // 와이어프레임 주전자
    glPopMatrix(); // 원래 상태 복원
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 2.0,   // 눈 위치
        0.0, 0.0, 0.0,   // 바라볼 중심
        0.0, 1.0, 0.0);  // 위쪽 방향

    drawWireTeapot();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
}

void update(int value) {
    rotationAngle += 1.0f;
    if (rotationAngle >= 360.0f)
        rotationAngle -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Wireframe Rotating Teapot");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
