# Polar Function Graphing

### Description
This project, completed as part of the coursework at the Benemérita Universidad Autónoma de Puebla, focuses on graphing a polar function using OpenGL in the Code::Blocks IDE. The aim is to visualize a polar function, specifically a Rose Curve, and explore variations in shape and color.

### Overview
Polar coordinates offer a different way of representing points in a plane compared to Cartesian coordinates. In this system, each point is determined by an angle and a distance from a central point (the pole). This method is particularly useful for objects moving in circular paths, simplifying their equations of motion.

### Objectives
- Implement and visualize a polar function using OpenGL.
- Apply learned concepts to modify the graph's shape and color.
- Develop an understanding of polar coordinates and their applications in computer graphics.

### Key Features
- **Initialization**: Set up the OpenGL environment and window properties.
- **Graphing Function**: Calculate and plot points for the Rose Curve.
- **Color Variation**: Implement a color scheme that changes with the angle to create a rainbow effect.

### Project Structure
The project includes the following main components:

#### Initialization
This function sets up the OpenGL environment, defining the color of the window and the projection parameters.

```cpp
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
```

#### Graphing Function

This function draws the graph by converting polar coordinates to Cartesian coordinates and assigns colors to each point based on its angle.

```cpp
void dibujaGrafica() {
    float x, y, rpolar, angulo, r, g, b;
    glClear(GL_COLOR_BUFFER_BIT);
    angulo = 0;
    glPointSize(1);

    for (i = 0; i < 720; i++) {
        rpolar = 5 * cos(4 * angulo);
        x = (rpolar * cos(angulo)) * (25);
        y = (rpolar * sin(angulo)) * (25);

        if (i <= 240) {
            r = 1.0;
            g = 0.0;
            b = 0.0;
        } else if ((i > 240) && (i <= 480)) {
            r = 0.0;
            g = 1.0;
            b = 0.0;
        } else if ((i > 480) && (i <= 720)) {
            r = 0.0;
            g = 0.0;
            b = 1.0;
        }
        glColor3f(r, g, b);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        angulo = angulo + 0.5;
    }
    glFlush();
}
```

#### Main Function

This function initializes the graphics window and starts the main loop.

```cpp
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Curva Rosa");
    init();
    glutDisplayFunc(dibujaGrafica);
    glutMainLoop();

    return 0;
}
```

### Execution

The project initializes a graphical window and plots a Rose Curve with a rainbow color effect. The transition of colors is smooth, providing a visual representation of the mathematical function in a creative manner.

<div style="display: flex; justify-content: center;">
    <img src="https://github.com/KPlanisphere/binary-tree-operations/assets/60454942/9c05945b-f26a-4c6c-a1ae-c9c88b13f6f9" alt="image" style="width: 50%; height: auto;">
</div>
