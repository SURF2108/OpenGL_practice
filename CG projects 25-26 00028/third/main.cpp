#include <GL/glut.h>
#include <cmath>  // Required for cosf and sinf

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a star-shaped polygon
    glColor3f(1.0, 0.0, 1.0); // Purple color
    int num_points = 5;
    float radius = 0.5f;
    float angle = 2 * M_PI / num_points;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_points * 2; i++) {
        float r = (i % 2 == 0) ? radius : radius / 2; // Alternating between outer and inner points
        float theta = angle * i;
        float x = r * cosf(theta);  // Use cosf
        float y = r * sinf(theta);  // Use sinf
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
    glutCreateWindow("Polygon (Star)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
