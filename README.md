```
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "models.h"
```

```
int main(int argc, char** argv) {

    instructions();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Window");
    glutFullScreen();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();

    return 0;

}
```

```
void instructions() {

    std::cout << "Welcome to Rubik's Cube Engine!\n--------------------------------\n" << std::endl;

    std::cout << "Controls\n" << std::endl;

    std::cout << "ALT + F\t\tToggle On Fullscreen" << std::endl;
    std::cout << "ESC\t\tToggle Off Fullescreen" << std::endl;

}
```