#include <stdio.h>
#include <windows.h>  
#include <GL/glut.h>  
 
void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-5,5,-5,5); 
    glClearColor(0.0,0.0,0.0,0.0);  
}
 
void createTriangulo(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.431,0.141,0.706);
    glBegin (GL_TRIANGLES);
    glVertex3f(0.25,0.25,0.0);
    glVertex3f(0.25,0.00,0.25);
    glVertex3f(-0.25,0.25,0.0);
    glEnd();
    glFlush();
}
 
void createPunto(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin (GL_POINTS);
    glVertex3f(0.25,0.25,0.0);
    glEnd();
    glFlush();
}

void createLinea(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin (GL_LINES);
    glVertex3f(0.25,0.25,0.0);
    glVertex3f(0.75,0.25,0.0);
    glEnd();
    glFlush();
}
 
int validar(char num[]){
    int i;
    for (i = 0; i < strlen(num); i++){
        if(!isdigit(num[i]) ) {
            return 0;
        }
    }
    return atoi(num);
}
 
 
void menuEleccion(){
 
    char text[256];
    int opcion;
    printf("\n -------- MENU ------------");
    printf("\n 1.- TRIANGULO");
    printf("\n 2.- PUNTO");
    printf("\n 3.- LINEA");
    printf("\n ELIJA UNA OPCION:");
    scanf("%s", text);

    opcion = validar(text);

    switch(opcion){
        case 1 :
        printf("\n TRIANGULO \n");
            glutDisplayFunc(createTriangulo);
        break;
        case 2 :
            printf("\n PUNTO \n");
        glutDisplayFunc(createPunto);
            break;
        case 3 :
        printf("\n LINEA \n");
            glutDisplayFunc(createLinea);
        break;
        default:
            printf("\n CARACTER INCORRECTO, VUELVA A ELEGIR OTRO.... \n");
        menuEleccion();
        break;
    }
  
}
 
void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Mi Primera Linea");
    glutInitWindowSize(600, 450);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    inicio();
    menuEleccion();
    glutMainLoop();
}
