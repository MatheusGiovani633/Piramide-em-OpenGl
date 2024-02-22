#include <GL/glut.h>
#include <iostream>

static GLfloat angTrianguloY = 0.0;
static GLfloat angTrianguloZ = 0.0;
static GLfloat angTrianguloX = 0.0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa o buffer de profundidade
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(angTrianguloZ, 0.0, 0.0, 1.0); // Rotação em torno do eixo Z
    glRotatef(angTrianguloY, 0.0, 1.0, 0.0); // Rotação em torno do eixo Y
    glRotatef(angTrianguloX, 1.0, 0.0, 0.0); // Rotação em torno do eixo X

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);


    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);


    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);


    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();

    glutSwapBuffers();
    // Desenhar texto
    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos3f(-1.0f, -1.5f, 0.0f);
    std::string texto = "Pressione 'A' para ir para a esquerda e 'D' para a direita, 'S' para baixo e 'W' para cima";

    for (char c : texto) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    glRasterPos3f(-1.0f, -1.7f, 0.0f);
    std::string texto2 = "para girar a camera 'E' e Q ";
    for (char c1 : texto2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c1);
    }

    glFlush();
}

void girandoTriangulo(unsigned char key, int x, int y)
{
    if (key == 'A' || key == 'a')
    {
        angTrianguloY -= 5.0;
    }
    else if (key == 'D' || key == 'd')
    {
        angTrianguloY += 5.0;
    }
    else if (key == 'S' || key == 's')
    {
        angTrianguloX += 5.0;
    }
    else if (key == 'W' || key == 'w')
    {
        angTrianguloX -= 5.0;
    }
    else if (key == 'Q' || key == 'q')
    {
        angTrianguloZ += 5.0;
    }
    else if (key == 'E' || key == 'e')
    {
        angTrianguloZ -= 5.0;
    }
    glutPostRedisplay(); // Redesenha a cena
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Triângulo Girando");
    glEnable(GL_DEPTH_TEST); // Habilita o teste de profundidade
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(girandoTriangulo);
    glutMainLoop();
    return 0;
}