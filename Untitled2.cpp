#include "TXLib.h"
void MoveShar ();
void DrawShar (double x, double y, COLORREF color);
void MoveSharrr (double* x, double* y, double* vx, double* vy, double dt);

int main ()
    {
    txCreateWindow (1500, 800);
    MoveShar ();
    }

void MoveShar ()
    {
    double x1 = 0, y1 = 0;
    double vx1 = 6, vy1 = 4;
    double x2 = 50, y2 = 50;
    double vx2 = 6, vy2 = 4;
    double x3 = 100, y3 = 100;
    double vx3 = 6, vy3 = 4;
    double dt = 1;

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        DrawShar (x1, y1, TX_LIGHTRED);
        MoveSharrr (&x1, &y1, &vx1, &vy1, dt);
        DrawShar (x2, y2, TX_LIGHTBLUE);
        MoveSharrr (&x2, &y2, &vx2, &vy2, dt);
        DrawShar (x3, y3, TX_LIGHTGREEN);
        MoveSharrr (&x3, &y3, &vx3, &vy3, dt);
        txSleep (0);
        }
    }

void DrawShar (double x, double y, COLORREF color)
    {
    txSetFillColor (color);
    txCircle (x, y, 10);
    }

void MoveSharrr (double* x, double* y, double* vx, double* vy, double dt)
    {
    *x = *x + *vx * dt;
    *y = *y + *vy * dt;

    if (*x < 0)
        {
        *x = 0;
        *vx = -*vx;
        }
    if (*x > 1500)
        {
        *x = 1500;
        *vx = -*vx;
        }
    if (*y > 800)
        {
        *y = 800;
        *vy = -*vy;
        }
    if (*y < 0)
        {
        *y = 0;
        *vy = -*vy;
        }
    }
