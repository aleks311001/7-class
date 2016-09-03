#include "TXLib.h"

struct C_Ball
    {
    double x, y;
    double vx, vy;
    double r;
    COLORREF color;
    };

void Mass_Ball (C_Ball * b, int N)

double XWindow = 1500, YWindow = 800;

int main ()
    {
    txCreateWindow (XWindow, YWindow);
    C_Ball ball [15] = {};
    Mass_Ball (ball, 15);
    for (int i = 0; )
    }

void Mass_Ball (C_Ball b [], int N)
    {
    for (int i = 0; i < N; i++)
        {
        b.r[i]  = random (5, 20);
        b.x[i]  = random (b.r[i], XWindow - b.r[i]);
        b.y[i]  = random (b.r[i], YWindow - b.r[i]);
        b.vx[i] = random (0.1, 5);
        b.vy[i] = random (0.1, 5);
        b.color[i] = RGB (random (100, 255), random (100, 255), random (100, 255));
        }
    }

void Dvig_and_draw (C_Ball b [], int N)
    {
    for (int i = 0; i < N; i++)
        {
        if (b.x[i] + b.r[i] >= XWindow)
            {
            b.vx[i] = -b.vx[i];
            b.x[i] = XWindow - b.r[i];
            }
        if (b.x[i] - b.r[i] <= 0)
        if (b.y[i] + b.r[i] >= YWindow || b.y[i] - b.r[i] <= 0)
            {
            b.vy[i] = -b.vy[i];
            b.y[i] = YWindow - b.r[i];
            }
        txSetColor (b.color[i]);
        txSetFillColor (b.color[i]);
        txCircle (b.x[i], b.y[i], b.r[i]);
        }
    }
