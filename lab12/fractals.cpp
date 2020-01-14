// Patrick Soga
// Lab 12, Section 2
// 11 Wednesday 2019
// fractals.cpp: program to produce fractals

#include <iostream>
#include <cmath>
#include "gfx.h"
using namespace std;

void sierpinski(int, int, int, int, int, int);
void shrinkingSquares(int, int, int, int, int, int, int, int);
void spiralSquares(int, int, double, float);
void circularLace(int, int, float);
void snowflake(int, int, float);
void tree(int, int, float, double);
void fern(int, int, float, double);
void spirals(int, int, float, float);

void drawTriangle(int, int, int, int, int, int);
void drawSquare(int, int, int, int, int, int, int, int);
void drawCenterSquare(int, int, int);
void drawSnowflake(int, int, int, int, double);

int main() {
    char choice;
    int xdim = 1000;
    int ydim = 1000;
    int margin = 20;
    // I was inefficient and built two functions for drawing squares
    int spiralSquareLen = 10;
    bool loop = true;
    gfx_open(xdim, ydim, "fractals");
    while (loop) {
        choice = gfx_wait();
        gfx_clear();
        switch(choice) {
            case '1': 
                sierpinski(margin, margin, xdim-margin, margin, xdim/2, ydim-margin);
                break;
            case '2':
                shrinkingSquares(xdim/4 + margin, ydim/4 + margin, xdim-(xdim/4) - margin, ydim/4 + margin, xdim-(xdim/4) - margin, ydim-(ydim/4) - margin, xdim/4 + margin, ydim-(ydim/4) - margin);
                break;
            case '3':
                spiralSquares(xdim/2, ydim/2, 0, 1);
                break;
            case '4':
                circularLace(xdim/2, ydim/2, 250);
                break;
            case '5':
                snowflake(xdim/2 - margin, ydim/2 - margin, 350);
                break;
            case '6': 
                tree(xdim/2, ydim, 250, M_PI/2);
                break;
            case '7':
                fern(xdim/2, ydim - margin, 700, -M_PI/2);
                break;
            case '8':
                spirals(xdim/2, ydim/2, 8*M_PI, 400);
                break;
            case 'q':
                loop = false;
                break;
            default:
                break;
        }
    }
    return 0;
}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
   // Base case
    if( abs(x2-x1) < 5 ) return;

   // Draw the triangle
    drawTriangle( x1, y1, x2, y2, x3, y3 );

   // Recursive calls
    sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
    sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
    sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

void shrinkingSquares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int length = x2-x1;
    // Base case
    if (abs(x2 - x1) < 10) return;

    // Draw the square
    drawSquare(x1, y1, x2, y2, x3, y3, x4, y4);

    // Recursive calls
    shrinkingSquares(x1-length/4, y1-length/4, x1+length/4, y1-length/4, x1+length/4, y1+length/4, x1-length/4, y1+length/4);
    shrinkingSquares(x2-length/4, y2-length/4, x2+length/4, y2-length/4, x2+length/4, y2+length/4, x2-length/4, y2+length/4);
    shrinkingSquares(x3-length/4, y3-length/4, x3+length/4, y3-length/4, x3+length/4, y3+length/4, x3-length/4, y3+length/4);
    shrinkingSquares(x4-length/4, y4-length/4, x4+length/4, y4-length/4, x4+length/4, y4+length/4, x4-length/4, y4+length/4);
}

void spiralSquares(int x1, int y1, double angle, float r) {
    // Base case
    if (r > 300) return;

    // Draw the square
    drawCenterSquare(x1, y1, r);

    // Recursive call
    spiralSquares(x1 + r*2*cos(angle), y1 - r*2*sin(angle), angle + M_PI/4, r * 1.2);
}

void circularLace(int x, int y, float radius) {
    float angle = 0;
    int circles = 6;
    int xr, yr;
    float radiusr;
    // Base case
    if (radius < 1) return;

    // Draw the circle
    gfx_circle(x, y, radius);

    // Recursive call
    for (int i = 0; i < circles; i++) {
        xr = x + radius * cos(angle);
        yr = y + radius * sin(angle);
        radiusr = radius * (1.0/3);
        circularLace(xr, yr, radiusr);
        angle += M_PI/3;
    }
}

void snowflake(int x, int y, float length) {
    // Base case
    if (length < 1) return;
    // Draw the snowflake
    gfx_line(x, y, x + (length*cos(M_PI/2)), y + (length*sin(M_PI/2)));
    gfx_line(x, y, x + (length*cos(M_PI/2 + 2*M_PI/5)), y + (length*sin(M_PI/2 + 2*M_PI/5)));
    gfx_line(x, y, x + (length*cos(M_PI/2 + 4*M_PI/5)), y + (length*sin(M_PI/2 + 4*M_PI/5)));
    gfx_line(x, y, x + (length*cos(M_PI/2 + 6*M_PI/5)), y + (length*sin(M_PI/2 + 6*M_PI/5)));
    gfx_line(x, y, x + (length*cos(M_PI/2 + 8*M_PI/5)), y + (length*sin(M_PI/2 + 8*M_PI/5)));

    // Recursive calls
    snowflake(x + (length*cos(M_PI/2)), y + (length*sin(M_PI/2)), length/3);
    snowflake(x + (length*cos(M_PI/2 + 2*M_PI/5)), y + (length*sin(M_PI/2 + 2*M_PI/5)), length/3);
    snowflake(x + (length*cos(M_PI/2 + 4*M_PI/5)), y + (length*sin(M_PI/2 + 4*M_PI/5)), length/3);
    snowflake(x + (length*cos(M_PI/2 + 6*M_PI/5)), y + (length*sin(M_PI/2 + 6*M_PI/5)), length/3);
    snowflake(x + (length*cos(M_PI/2 + 8*M_PI/5)), y + (length*sin(M_PI/2 + 8*M_PI/5)), length/3);
}

void tree(int x, int y, float length, double angle) {
    // Base case
    if (length < 2) return;

    // Draw trunk
    gfx_line(x, y, x + length*cos(angle), y-length*sin(angle));

    // Recursive call
    tree(x + length*cos(angle), y - length*sin(angle), length * 0.7, angle + M_PI/6);
    tree(x + length*cos(angle), y - length*sin(angle), length * 0.7, angle - M_PI/6);
}

void fern(int x, int y, float length, double angle) {
    // Base case
    if (length < 2) return;

    // Draw stem
    gfx_line(x, y, x + length*cos(angle), y + length*sin(angle));

    // Recursive call
    for (int i = 1; i < 5; i++) {
        fern(x + length * i/5 * cos(angle), y + length * i/5 * sin(angle), length * 0.3, angle + M_PI/6);
        fern(x + length * i/5 * cos(angle), y + length * i/5 * sin(angle), length * 0.3, angle - M_PI/6);
    }
}

void spirals(int x, int y, float angle, float radius) {

    
    // Base case
    if (radius < 1) return;

    // Initial point
    gfx_point(x + radius * cos(1.1*angle), y - radius*sin(1.1*angle));
    // Recursive call
    spirals(x, y, angle - M_PI/6, radius*0.92);
    spirals(x + radius*cos(1.1*angle), y - radius*sin(1.1*angle), angle - M_PI/6, radius*0.32);
}

void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 )
{
    gfx_line(x1,y1,x2,y2);
    gfx_line(x2,y2,x3,y3);
    gfx_line(x3,y3,x1,y1);
}

void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    gfx_line(x1, y1, x2, y2);
    gfx_line(x2, y2, x3, y3);
    gfx_line(x3, y3, x4, y4);
    gfx_line(x4, y4, x1, y1);
}

void drawCenterSquare(int x, int y, int length) {
    int sideRef = length/2;
    gfx_line(x - sideRef, y - sideRef, x + sideRef, y - sideRef);
    gfx_line(x + sideRef, y - sideRef, x + sideRef, y + sideRef);
    gfx_line(x + sideRef, y + sideRef, x - sideRef, y + sideRef);
    gfx_line(x - sideRef, y + sideRef, x - sideRef, y - sideRef);
}

void drawSnowflake(int sides, int x, int y, int size, double offset) {
    size /= 2;
    float angle = (360/sides)*(M_PI/180);
    for (int i = 0; i < sides; i++) {
        gfx_line(x, y, x+size*cos(angle*i + offset), y+size*sin(angle*i + offset));
        angle + angle*(i+1);
    }
}