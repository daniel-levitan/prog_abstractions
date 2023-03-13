/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

//#include "console.h"
//#include "simpio.h"
#include "gwindow.h"
using namespace std;

/**
 * six stripes in the rainbow are red, orange, yellow, green, blue, and magenta, respectively; cyan makes a lovely color for the sky.
 */

int main()
{
    GWindow gw;
    double width = gw.getWidth();
    double height = gw.getHeight();

    gw.setColor("CYAN");
    gw.fillRect(0, 0, width, height);

    gw.setColor("RED");
    gw.fillOval(-width/2, 10, 2 * width, 4 * height);

    gw.setColor("ORANGE");
    gw.fillOval(-width/2, 20, 2 * width, 4 * height);

    gw.setColor("YELLOW");
    gw.fillOval(-width/2, 30, 2 * width, 4 * height);

    gw.setColor("GREEN");
    gw.fillOval(-width/2, 40, 2 * width, 4 * height);

    gw.setColor("BLUE");
    gw.fillOval(-width/2, 50, 2 * width, 4 * height);

    gw.setColor("MAGENTA");
    gw.fillOval(-width/2, 60, 2 * width, 4 * height);

    gw.setColor("CYAN");
    gw.fillOval(-width/2, 70, 2 * width, 20 * height);


//    gw.setColor("RED");
//    gw.fillOval(0, height / 4, width, height/2);

    return 0;
}
