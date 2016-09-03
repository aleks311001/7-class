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
    C_Ball ball [1500] = {};
    Mass_Ball (ball, 1500);
    for (int i = 0;; i++)
        {
        txBegin ();
        /*if (!GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txSetColor (TX_BLACK);
            txClear ();
            }*/
        Dvig_and_draw (ball, 1500);
        txSleep (10000);
        txEnd ();
        }
    }

void Mass_Ball (C_Ball b [], int N)
    {
    for (int i = 0; i < N; i++)
        {
        b[i].r  = random (1, 2);
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
    int MX = 0, MY = 0;
    for (int i = 0; i < N; i++)
        {
        MX = (int)txMouseX;
        MY = (int)txMouseY;
        b[i].vx = (MX - b[i].x)/60 + (MX - b[i].x) / abs(MX - b[i].x);
        b[i].vy = (MY - b[i].y)/60 + (MY - b[i].y) / abs(MY - b[i].y);
        b[i].x += b[i].vx;
        b[i].y += b[i].vy;

        d = Dist (MX, MY, b[i].x, b[i].y);
        if (d > 400) d_c = 200;
        else         d_c = d / 2;
        b[i].color = RGB (255 - d_c, d_c + 55, 0);

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

        txSetColor (b[i].color);
        txSetFillColor (b[i].color);
        txCircle (b[i].x, b[i].y, b[i].r);
        }
    }

double Dist (double x1, double y1, double x2, double y2)
    {
    return sqrt ((x2- x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
