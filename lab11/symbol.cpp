// Patrick Soga
// Lab 11 Section 2
// 5 December 2019
// symbol.cpp: editor with symbols
#include <iostream>
#include <cmath>
#include "gfx.h"
using namespace std;

void drawSquare(int, int, int);
void drawCircle(int, int, int);
void drawTriangle(int, int, int);
void drawPolygon(int, int, int, int);

int main() {
    int xdim, ydim;
    xdim = ydim = 500;
    gfx_open(xdim, ydim, "Symbolic Typewriter");
    int size = 50;
    while(true) {
        char choice = gfx_wait();
        switch(choice) {
            case 1:
                drawSquare(gfx_xpos(), gfx_ypos(), size);
            break;
            case 'c':
                drawCircle(gfx_xpos(), gfx_ypos(), size/2);
            break;
            case 't':
                drawTriangle(gfx_xpos(), gfx_ypos(), size);
            break;
            case '9':
            case '8':
            case '7':
            case '6':
            case '5':
            case '4':
            case '3':
                drawPolygon(choice, gfx_xpos(), gfx_ypos(), size);
            break;
            case 27:
                gfx_clear();
            break;
            case 'q':
                return 1;
            break;
            default:
            break;
        }
    }
    return 0;
}

void drawSquare(int x, int y, int size) {
    gfx_color(0, 0, 255);
    gfx_line(x-size/2, y-size/2, x-size/2, y+size/2);
    gfx_line(x-size/2, y-size/2, x+size/2, y-size/2);
    gfx_line(x+size/2, y-size/2, x+size/2, y+size/2);
    gfx_line(x+size/2, y+size/2, x-size/2, y+size/2);
}
void drawCircle(int x, int y, int size) {
    gfx_color(255, 255, 255);
    gfx_circle(x, y, size);
}
void drawTriangle(int x, int y, int size) {
    gfx_color(0, 255, 0);
    gfx_line(x, y-size*0.5, x + size*0.5, y+size*0.5);
    gfx_line(x, y-size*0.5, x - size*0.5, y+size*0.5);
    gfx_line(x - size*0.5, y+size*0.5, x + size*0.5, y+size*0.5);
}
void drawPolygon(int sides, int x, int y, int size) {
    size /= 2;              // Fix polygon scaling
    sides -= 48;            // Offset to get the number represnted
    gfx_color(120, 0, 255);
    float angle = (360/sides)*(M_PI/180);
    for (int i = 0; i < sides; i++) {
        gfx_line(x+size*cos(angle*i), y+size*sin(angle*i), x+size*cos(angle*(i+1)), y+size*sin(angle*(i+1)));
        angle + angle*(i+1);
    }
}