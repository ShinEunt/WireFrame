🔷 Wireframe Teapot (와이어프레임 주전자 예제)
이 프로젝트는 OpenGL(FreeGLUT)을 사용하여 회전하는 와이어프레임 주전자를 화면에 출력하는 예제입니다.
glutWireTeapot() 함수를 이용하여 3D 오브젝트의 뼈대 형태만을 렌더링하며,
타이머 함수로 지속적인 회전을 구현합니다.

✅ 주요 기능
glutWireTeapot()으로 와이어프레임 형태의 3D 주전자 출력

Y축 기준으로 주전자가 회전함

카메라 시점을 gluLookAt()으로 조절하여 입체적으로 보이도록 설정

타이머 함수(glutTimerFunc)를 이용한 부드러운 애니메이션 구현


🧩 주요 코드 설명

glutWireTeapot(0.5)	크기 0.5의 와이어프레임 주전자 렌더링

glRotatef(...)	Y축 회전 적용 (애니메이션용)

glutTimerFunc(16, update, 0)	약 60FPS로 회전 각도 업데이트

gluLookAt(...)	카메라 위치 설정 (3D 시점 연출)

glEnable(GL_DEPTH_TEST)	깊이 버퍼 활성화로 객체 겹침 방지

glClearColor(...)	배경색 설정


📌 핵심 코드 예시

void drawWireTeapot() {

    glPushMatrix();
    
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Y축 회전
    
    glColor3f(0.0f, 1.0f, 1.0f); // 청록색
    
    glutWireTeapot(0.5); // 와이어프레임 주전자
    
    glPopMatrix();
    
}

void update(int value) {

    rotationAngle += 1.0f;
    
    if (rotationAngle >= 360.0f)
    
        rotationAngle -= 360.0f;
        
    glutPostRedisplay();
    
    glutTimerFunc(16, update, 0);
    
}

