// Patrick Soga
// Lab 11 Section 2
// 8 December 2019
// funanim.cpp: fun animation; spin colorful polygons

#include <iostream>
#include <cmath>
#include <unistd.h>
#include <cstdlib>
#include "gfx.h"

using namespace std;
void drawPolygon(int, int, int, int, double);

int main() {
    int size = 100;
    int xdim, ydim;
    xdim = 800;
    ydim = 700;
    gfx_open(xdim, ydim, "funanimation");
    while(true) {
        char choice;
        float rotation = 0;
        char sides = '4';
        int x = xdim/2;
        int y = ydim/2;
        while (rotation != 2*M_PI) {
            if (gfx_event_waiting()) {
                x = gfx_xpos();
                y = gfx_ypos();
                choice = gfx_wait();
                switch(choice) {
                    case '9':
                    case '8':
                    case '7':
                    case '6':
                    case '5':
                    case '4':
                    case '3':
                        sides = choice;
                        drawPolygon(choice, x, y, size, rotation);
                        break;
                }
            }
            drawPolygon(sides, x, y, size, rotation);
            rotation += M_PI/180;
            gfx_clear();
            drawPolygon(sides, x, y, size, rotation);
            gfx_flush();
            usleep(10000);
        }        
    }
    return 0;
}

// Adjusted drawPolygon to make it spin
void drawPolygon(int sides, int x, int y, int size, double rotation) {
    size /= 2;              // Fix polygon scaling
    sides -= 48;            // Offset to get the number represnted
    switch(sides) {
        case 9:
            gfx_color(255, 255, 255);
            break;
        case 8:
            gfx_color(0, 255, 255);
            break;
        case 7:
            gfx_color(255, 0, 255);
            break;
        case 6:
            gfx_color(255, 255, 0);
            break;
        case 5:
            gfx_color(0, 0, 255);
            break;
        case 4:
            gfx_color(255, 0, 0);
            break;
        case 3:
            gfx_color(0, 255, 0);
            break;
        default:
            gfx_color(255, 255, 255);
            break;
    }
    float angle = (360/sides)*(M_PI/180);
    for (int i = 0; i < sides; i++) {
        gfx_line(x+size*cos(((angle)*i) + rotation), y+size*sin(((angle)*i) + rotation), x+size*cos(((angle)*(i+1)) + rotation), y+size*sin(((angle)*(i+1)) + rotation));
        (angle + rotation) + ((angle)*(i+1) + rotation);
    }
}