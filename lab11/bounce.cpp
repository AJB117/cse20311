// Patrick Soga
// Lab 11 Section 2
// 5 December 2019
// bounce.cpp: bouncing ball in a box
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <cstdlib>
#include "gfx.h"

using namespace std;

int main() {
    int xdim = 800;
    int ydim = 550;
    int size = 30;
    gfx_open(xdim, ydim, "bounce");

    while(true) {
        int choice = gfx_wait();
        int x = gfx_xpos();
        int y = gfx_ypos();
        int vx, vy;
        if (choice == 1) {
            gfx_circle(x, y, size);
            // Velocities are between -20 and 20
            vx = rand() % 40 - 20;
            vy = rand() % 40 - 20;
        }

        while (x <= xdim && x >= 0 && y <= ydim && y >= 0) {
            if (gfx_event_waiting()) {
                choice = gfx_wait();
                if (choice == 1) {
                    x = gfx_xpos();
                    y = gfx_ypos();
                    gfx_circle(x, y, size);
                    vx = rand() % 40 - 20;
                    vy = rand() % 40 - 20;
                }
            }
            x += vx;
            y += vy;
            // Bounce logic; maintain velocity in direction that isn't affected by bounce
            if (y >= ydim - size || y <= size) {
                vy = -vy;
                y += vy;
            }
            else if (x >= xdim - size || x <= size) {
                vx = -vx;
                x += vx;
            }
            gfx_clear();
            gfx_circle(x, y, size);
            gfx_flush();
            usleep(10000);
        }
    }
    return 0;
}