//JESUS HUERTA AGUILAR - FACULTAD DE CIENCIAS DE LA COMPUTACION BUAP

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <cmath>  //para operar con las funciones trigonometricas

GLfloat sizep;
int i;

void init(void){
    //Establece el color de la ventana de visualizacion
    //Los tres primeros parametros corresponden al RGB
    //El cuarto parametro corresponde al valor alfa, que permite el efecto de transparencias
    //0: objeto totalmente transparente; 1: objeto totalmente opaco
    glClearColor(0.0, 0.0, 0.0, 1.0); //FONDO NEGRO
    //establece los parametros de proyeccion ortogonal
    //Se visualizara una proyeccion bidimensional de dimensiones 200 x 150
    //(0,0): esquina inferior izquierda: punto de referencia de esta ventana
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200,200,-200,200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void dibujaGrafica(){
    float x,y,rpolar,angulo,r,g,b;
    glClear(GL_COLOR_BUFFER_BIT);  //borra la ventana de visualizacion
    //glColor3f(0.0, 0.0, 0.0);      //establece que lo que se dibuja sera rojo

    //MUESTRA GRAFICA
    angulo = 0;
    glPointSize(1);

    for (i=0;i<720;i++){
        rpolar = 5*cos(4*angulo);  //donde a = longitud del petalo y n = 4 (r = a*cos(n*theta))
        x = (rpolar*cos(angulo))*(25);
        y = (rpolar*sin(angulo))*(25);

        //arcoiris
        if(i <= 240){
            r = 1.0;
            g = 0.0;
            b = 0.0;
        }
        else if((i > 240) && (i <= 480)){
            r = 0.0;
            g = 1.0;
            b = 0.0;
        }
        else if((i > 480) && (i <= 720)){
            r = 0.0;
            g = 0.0;
            b = 1.0;
        }

        glColor3f(r, g, b);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        angulo = angulo + 0.5;
    }

    //se obliga a procesar todas las instrucciones de openGL tan rapidamente como sea posible
    glFlush();
}

int main(int argc, char** argv){
    //se inicializa la pantalla grafica
    glutInit(&argc, argv);
    //establece el modo de visualizacion
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //Establece la posicion de la esquina superior izquierda del grafico en la pantalla
    glutInitWindowPosition(100,100);
    //se establece el ancho y la altura de la ventana de visualizacion
    glutInitWindowSize(400,400);
    //se crea la ventana de visualizacion
    glutCreateWindow("Curva Rosa");
    //se ejecuta la funcion de inicializacion de parametros
    init();
    //se envian los graficos a pantalla
    glutDisplayFunc(dibujaGrafica);
    glutMainLoop();

    return 0;
}

