#include "TXLib.h"

struct C_Ball
    {
    double x, y;
    double vx, vy;
    double r;
    COLORREF color;
    };

void Mass_Ball (C_Ball b [], int N);
void Dvig_and_draw (C_Ball b [], int N);

double XWindow = 1500, YWindow = 800;

int main ()
    {
    txCreateWindow (XWindow, YWindow);
    C_Ball ball [150] = {};
    Mass_Ball (ball, 150);
    for (int i = 0;; i++)
        {
        txBegin ();
        if (!GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txSetColor (TX_BLACK);
            txClear ();
            }
        Dvig_and_draw (ball, 150);
        txSleep (0);
        txEnd ();
        }
    }

void Mass_Ball (C_Ball b [], int N)
    {
    for (int i = 0; i < N; i++)
        {
        b[i].r  = random (5, 20);
        b[i].x  = random (b[i].r, XWindow - b[i].r);
        b[i].y  = random (b[i].r, YWindow - b[i].r);
        b[i].vx = random (-5, 5);
        b[i].vy = random (-5, 5);
        b[i].color = RGB (random (100, 255), random (100, 255), random (100, 255));
        }
    }

void Dvig_and_draw (C_Ball b [], int N)
    {
    for (int i = 0; i < N; i++)
        {
        b[i].x += b[i].vx;
        b[i].y += b[i].vy;

        if (b[i].x + b[i].r >= XWindow)
            {
            b[i].vx = -b[i].vx;
            b[i].x = XWindow - b[i].r;
            }
        if (b[i].x - b[i].r <= 0)
            {
            b[i].vx = -b[i].vx;
            b[i].x = b[i].r;
            }

        if (b[i].y + b[i].r >= YWindow)
            {
            b[i].vy = -b[i].vy;
            b[i].y = YWindow - b[i].r;
            }
        if (b[i].y - b[i].r <= 0)
            {
            b[i].vy = -b[i].vy;
            b[i].y = b[i].r;
            }

        txSetColor (b[i].color);
        txSetFillColor (b[i].color);
        txCircle (b[i].x, b[i].y, b[i].r);
        }
    }
