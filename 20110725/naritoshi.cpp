#include <cstdio>
#include <cstdlib>
#include <GLUT/GLUT.h>

int gWidth = 0;
int gHeight = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    std::printf("hoge\n");


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glBegin(GL_TRIANGLES);

    glColor3f(0.5, 0.5, 0.5);

    glVertex2f(-0.5, 0);
    glVertex2f(0, -0.5);
    glVertex2f(0, 0.5);

    glEnd();


    glutSwapBuffers();
}

void reshape(int width, int height) {
    gWidth = width;
    gHeight = height;
    std::printf("width = %d, height = %d\n", width, height);
}

void keyboard(unsigned char key, int x, int y) {
    if ( key == 27 ) {
        std::exit(0);
    }
    std::printf("%d, %d, %d\n", x, y, key);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    /*glutInitWindowSize();*/

    glutCreateWindow("naritoshi");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutReshapeFunc(reshape);

    /*glutSpecialFunc();*/
    /*glutMotionFunc();*/
    /*glutPassiveMotionFunc();*/

    glutMainLoop();
}
