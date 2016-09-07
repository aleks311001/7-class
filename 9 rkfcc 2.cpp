#include "TXLib.h"

struct C_Ball
    {
    double x, y;
    double vx, vy;
    double r;
    COLORREF color;
    };

double VX [15000] = {}, VY [15000] = {};
int N_M = 0;
double k = 3.525;

void Mass_Ball (C_Ball b [], int N);
void Dvig_and_draw (C_Ball b [], int N);
double Dist (double x1, double y1, double x2, double y2);
void Osnovn ();

double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);

int main ()
    {
    _txWindowStyle &= ~ WS_CAPTION;
    txCreateWindow (XWindow, YWindow);
    txTextCursor (false);
    Osnovn ();
    }

void Osnovn ()
    {
    C_Ball ball [3000] = {};
    Mass_Ball (ball, 3000);
    printf ("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");
    for (int i = 0; !GetAsyncKeyState (VK_ESCAPE); i++)
        {
        txBegin ();
        if (GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txSetColor (TX_BLACK);
            txClear ();
            }
        Dvig_and_draw (ball, 3000);
        if (GetAsyncKeyState (VK_UP) && k != 0.025) k -= 0.025;
        if (GetAsyncKeyState (VK_DOWN)) k += 0.025;
        printf ("%g,\n\n\n\n\n\n\n\n\n\n\n\n\n ", k);
        //txSleep (10);
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

    for (int i = 0; i < N; i++, N_M ++)
        {
        N_M = N_M%15000;
        d = Dist (txMouseX (), txMouseY(), b[i].x, b[i].y);
        if (d > 765) d_c = 255;
        else         d_c = d / 3;
        b[i].color = RGB (d_c, d_c, 255 - d_c);

        txSetColor (b[i].color);
        txSetFillColor (b[i].color);
        txCircle (b[i].x, b[i].y, b[i].r);

        b[i].vx = VX[N_M];
        b[i].vy = VY[N_M];

        VX[N_M] = (txMouseX() - b[i].x) / k; //+ (txMouseX() - b[i].x) / fabs(txMouseX() - b[i].x);
        VY[N_M] = (txMouseY() - b[i].y) / k; //+ (txMouseY() - b[i].y) / fabs(txMouseY() - b[i].y);

        /*if (VX[i] > 10) VX[i] = 10;
        if (VY[i] > 10) VY[i] = 10;

        if (VX[i] < -10) VX[i] = -10;
        if (VY[i] < -10) VY[i] = -10;*/

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
            }*/
        b[i].x += b[i].vx;
        b[i].y += b[i].vy;
        }
    }

double Dist (double x1, double y1, double x2, double y2)
    {
    return sqrt ((x2- x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
