#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a pentagon
    glColor3f(1.0, 0.5, 0.0); // Orange color
    int num_sides = 5;
    float radius = 0.5f;
    float angle = 2 * 3.1415926f / num_sides;

    glBegin(GL_POLYGON);
    for (int i = 0; i < num_sides; i++) {
        float x = radius * cosf(i * angle);
        float y = radius * sinf(i * angle);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  // Use glOrtho here
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Pentagon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
