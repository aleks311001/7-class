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
double Dist (double x1, double y1, double x2, double y2);
void Osnovn ();

double XWindow = 1500, YWindow = 800;

int main ()
    {
    txCreateWindow (XWindow, YWindow);
    txTextCursor (false);
    Osnovn ();
    }

void Osnovn ()
    {
    C_Ball ball [15000] = {};
    Mass_Ball (ball, 15000);
    for (int i = 0;; i++)
        {
        txBegin ();
        if (!GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txSetColor (TX_BLACK);
            txClear ();
            }
        Dvig_and_draw (ball, 15000);
        txSleep (10);
        txEnd ();
        }
    }

void Mass_Ball (C_Ball b [], int N)
    {
    for (int i = 0; i < N; i++)
        {
        b[i].r  = random (0.5, 1);
        b[i].x  = random (b[i].r, XWindow - b[i].r);
        b[i].y  = random (b[i].r, YWindow - b[i].r);
        b[i].vx = 0;
        b[i].vy = 0;
        b[i].color = RGB (0, 255, 0);
        }
    }

void Dvig_and_draw (C_Ball b [], int N)
    {
    double d = 0, d_c = 0;

    for (int i = 0; i < N; i++)
        {
        d = Dist (txMouseX (), txMouseY(), b[i].x, b[i].y);
        if (d > 510) d_c = 255;
        else         d_c = d / 2;
        b[i].color = RGB (255 - d_c, d_c, 0);

        txSetColor (b[i].color);
        txSetFillColor (b[i].color);
        txCircle (b[i].x, b[i].y, b[i].r);

        b[i].vx = (txMouseX() - b[i].x); //+ (txMouseX() - b[i].x) / fabs(txMouseX() - b[i].x);
        b[i].vy = (txMouseY() - b[i].y); //+ (txMouseY() - b[i].y) / fabs(txMouseY() - b[i].y);
        b[i].x += b[i].vx;
        b[i].y += b[i].vy;

        /*if (b[i].x + b[i].r >= XWindow)
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
           */
        }
    }

double Dist (double x1, double y1, double x2, double y2)
    {
    return sqrt ((x2- x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
