#include "TXLib.h"
void MoveShar ();
void Prepyatstvie (int x, int y);
void text (const char * text, int x, int y);
void Score (double Score, int x, int y);

int main ()
    {
    txCreateWindow (1500, 800);
    MoveShar ();
    }

void MoveShar ()
    {
    double x = 100, y = 100;
    double vx = 0, vy = 0;
    double dt = 1;
    int Xpr = 600, Ypr = 400;
    int Xpr1 = 400, Ypr1 = 600;
    int Xpr2 = 1200, Ypr2 = 450;
    int Xpr3 = 100, Ypr3 = 600;
    int Xpr4 = 300, Ypr4 = 300;
    double v = 3;
    double Diametr = 20;
    double Heart = 5;

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        txSetColor (RGB(random (0, +255), random (0, +255), random (0, +255)));
        txSetFillColor (RGB(random (0, +255), random (0, +255), random (0, +255)));
        txCircle (x, y, Diametr);
        Prepyatstvie (Xpr, Ypr);
        Prepyatstvie (Xpr1, Ypr1);
        Prepyatstvie (Xpr2, Ypr2);
        Prepyatstvie (Xpr3, Ypr3);
        Prepyatstvie (Xpr4, Ypr4);
        Score (dt, 750, 50);
        Score (Heart, 550, 50);

        dt = dt + 0.001;
        x = x + vx * dt;
        y = y + vy * dt;

        if (x < 0)
            {
            vy = -10000;
            vx = -10000;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Game Over!", 100, 200);
            }
        if (x > 1500)
            {
            vy = 10000;
            vx = 10000;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Game Over!", 100, 200);
            }
        if (y > 800)
            {
            vy = 10000;
            vx = 10000;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Game Over!", 100, 200);
            }
        if (y < 0)
            {
            vy = -10000;
            vx = -10000;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Game Over!", 100, 200);
            }

        if (GetAsyncKeyState(VK_UP))
            {
            vx = 0;
            vy = -v;
            }
        if (GetAsyncKeyState(VK_LEFT))
            {
            vy = 0;
            vx = -v;
            }
        if (GetAsyncKeyState(VK_DOWN))
            {
            vx = 0;
            vy = v;
            }
        if (GetAsyncKeyState(VK_RIGHT))
            {
            vy = 0;
            vx = v;
            }

        if (-20 < Xpr - x and Xpr - x < 20 and -50 < Ypr - y and Ypr - y < 50)
            {
            Heart = Heart - 1;
            }
        if (-20 < Xpr3 - x and Xpr3 - x < 20 and -50 < Ypr3 - y and Ypr3 - y < 50)
            {
            Heart = Heart - 1;
            }
        if (-20 < Xpr2 - x and Xpr2 - x < 20 and -50 < Ypr2 - y and Ypr2 - y < 50)
            {
            Heart = Heart - 1;
            }
        if (-20 < Xpr1 - x and Xpr1 - x < 20 and -50 < Ypr1 - y and Ypr1 - y < 50)
            {
            Heart = Heart - 1;
            }
        if (-20 < Xpr4 - x and Xpr4 - x < 20 and -50 < Ypr4 - y and Ypr4 - y < 50)
            {
            Heart = Heart - 1;
            }

        if (GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            }
        if (GetAsyncKeyState ('L'))
            {
            v = 1;
            }

        if (Heart < 0)
            {
            vx = 0;
            vy = 0;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Game over!", 100, 200);
            }
        if (dt > 3)
            {
            Heart = Heart + 0.002;
            }

        txSleep (2);
        }
    }
void Prepyatstvie (int x, int y)
    {
    txSetFillColor (RGB(random (0, +255), random (0, +255), random (0, +255)));
    POINT Prepyatstvie [4] = {{x - 10, y - 40}, {x + 10, y - 40}, {x + 10, y + 40}, {x - 10, y + 40}};
    txPolygon (Prepyatstvie, 4);
    }
void text (const char * text, int x, int y)
    {
    txSelectFont ("Comic Sans MS", 300, 100, 50, false, false, false, 0);
    txTextOut (x, y, text);
    }
void Score (double Score, int x, int y)
    {
    txSetColor (RGB(255, 215, 0));
    txSetFillColor (TX_BLACK);
    txRectangle (x - 100, y - 20, x + 100, y + 20);
    char text [100] = "You have";
    sprintf (text, "You have %lg", Score);
    txTextOut (x - 75, y- 10, text);
    }
