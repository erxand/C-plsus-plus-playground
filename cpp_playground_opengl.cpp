// In Visual Studio, goto Tools, Nuget Package Manager, and Package Manage Console.
// Enter: Install-Package nupengl.core


#include <GL/glut.h>

#include <iostream>

#include <random>


using namespace std;


// A star is defined by a location (x,y) and a color (r,g,b)
struct Star {

    float x;
    float y;
    int r;
    int g;
    int b;

};


// We will have 400 stars to draw
Star stars[400];


// Draw a point at (x,y) using RGB color (r,g,b)
void drawPoint(float x, float y, int r, int g, int b)

{

    // Every drawing operation in OpenGL begins with glBegin and ends with glEnd
    glBegin(GL_POINTS);

    // Set the color of our "paintbrush"
    glColor3f((GLfloat)(r / 255.0), (GLfloat)(g / 255.0), (GLfloat)(b / 255.0));

    // Draw a single point
    glVertex2f(x, y);

    glEnd();

}


// The draw function is called every frame to repaint the screen
void drawCallback()

{

    // Step 1: Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);


    // Step 2: Draw stuff (perhaps loop through a list of objects
    // and draw each one individually here).  In this case,
    // draw all our global stars
    for (int i = 0; i < 400; i++) {

        drawPoint(stars[i].x, stars[i].y, stars[i].r, stars[i].g, stars[i].b);

    }


    // Step 3: Apply the drawings to the screen
    glutSwapBuffers();

}


// If you want to react to mouse activity
void mouseCallback(int button, int state, int x, int y)

{

    cout << "Button, State, X, Y: " << button

        << ", " << state << ", " << x << ", " << y << endl;

}


// If you want to react to keyboard activity
void keyboardCallback(unsigned char key, int x, int y)

{

    cout << "Key, X, Y: " << key

        << ", " << x << ", " << y << endl;

}


// This will intialize the window and define the functions involved with drawing and handling events. We need to receive the
// command line arguments (if any) because they are needed int the glutInit. 
void initGL(int argc, char** argv)

{

    // Initialize open GL
    glutInit(&argc, argv);


    // Create a window in the upper left hand corner of the screen
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);


    // The window graphics support color and double buffering
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);


    // Title for the window
    glutCreateWindow("OpenGL Demo");


    // Set the background to be black
    glClearColor(0, 0, 0, 0);


    // Create a grid system for the window going from -10 to 10 in both directions
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10, 10, -10, 10);


    // Identify the funcitons to call for drawing, mouse/keyboard events
    glutDisplayFunc(drawCallback);
    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);

}



class Car {
public:
    string make;
    string model;
    string fuel_type;
    int year;
    float odometer;
    Car(string ma, string mo, string f, int y, float o);
    void print_info();
};

Car::Car(string ma, string mo, string f, int y, float o) {
    make = ma;
    model = mo;
    fuel_type = f;
    year = y;
    odometer = o;
}

void Car::print_info() {
    cout << "Make: " << make << " Model: " << model << " Fuel Type: " << fuel_type << " Year: " << year << " Mileage: " << odometer;
}




int main(int argc, char** argv)

{

    Car my_dream_car = Car("Audi", "E-Tron GT", "Electric", 2022, 0.0);
    my_dream_car.print_info();


    // Initialize the graphics
    initGL(argc, argv);


    // Initialize our stars
    std::default_random_engine generator;

    std::uniform_real_distribution<float> distribution(-10.0, 10.0);


    int index = 0;
    for (int i = -10; i < 10; i ++) {
        for (int j = -10; j < 10; j++) {
            if ((i + j) % 2 == 0) {
                stars[index].r = 255;
                stars[index].g = 255;
                stars[index].b = 255;
            }
            else {
                stars[index].r = 255;
                stars[index].g = 0;
                stars[index].b = 0;
            }

            stars[index].x = i + 0.5;
            stars[index].y = j + 0.5;

            index++;

        }
    }


    // Run the infinite loop. Drawing and event handling will be done by the callback functions that we previously defined
    glutMainLoop();

    


    return 0;

}