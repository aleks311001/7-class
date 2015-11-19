#include "TXLib.h"
void MoveShar ();
void Prepyatstvie (int x, int y);
void text (const char * text, int x, int y, COLORREF color);
void Score (double Score, int x, int y);
void Sharik (int* x, int* y, int* vx, int* vy, double* v, double* dt);
void upravlenie (int* vx, int* vy, double* v, COLORREF vverh, COLORREF vlevo, COLORREF vniz, COLORREF vpravo);
void ogranich (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color);
void Pr (COLORREF color, const char* text1, int* x, int* y, int* vx, int* vy, int* Xpr, int* Ypr);
void Chit (double* v1);

int main ()
    {
    txCreateWindow (1500, 800);
    MoveShar ();
    }

void MoveShar ()
    {
    int x = 100, y = 100;
    int vx = 3, vy = 0;
    int Xpr = 600, Ypr = 400;
    int Xpr1 = 400, Ypr1 = 600;
    int Xpr2 = 1200, Ypr2 = 450;
    int Xpr3 = 100, Ypr3 = 600;
    int Xpr4 = 300, Ypr4 = 300;
    double dt = 1;
    double v = 4;
    double Diametr = 20;

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        if (!GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            }

        dt = dt + 0.001;
        Score (dt, 750, 50);

        txSetColor (TX_LIGHTRED);
        txSetFillColor (TX_LIGHTRED);
        txCircle (x, y, Diametr);

        Prepyatstvie (Xpr, Ypr);
        Prepyatstvie (Xpr1, Ypr1);
        Prepyatstvie (Xpr2, Ypr2);
        Prepyatstvie (Xpr3, Ypr3);
        Prepyatstvie (Xpr4, Ypr4);

        Pr (TX_LIGHTRED, "Game over !", &x, &y, &vx, &vy, &Xpr, &Ypr);
        Pr (TX_LIGHTRED, "Game over !", &x, &y, &vx, &vy, &Xpr1, &Ypr1);
        Pr (TX_LIGHTRED, "Game over !", &x, &y, &vx, &vy, &Xpr2, &Ypr2);
        Pr (TX_LIGHTRED, "Game over !", &x, &y, &vx, &vy, &Xpr3, &Ypr3);
        Pr (TX_LIGHTRED, "Game over !", &x, &y, &vx, &vy, &Xpr4, &Ypr4);

        Sharik (&x, &y, &vx, &vy, &v, &dt);

        Chit (&v);

        txSleep (0);
        }
    }

void Prepyatstvie (int x, int y)
    {
    txSetFillColor (RGB(random (0, +255), random (0, +255), random (0, +255)));
    POINT Prepyatstvie [4] = {{x - 10, y - 40}, {x + 10, y - 40}, {x + 10, y + 40}, {x - 10, y + 40}};
    txPolygon (Prepyatstvie, 4);
    }

void text (const char * text, int x, int y, COLORREF color)
    {
    txSetColor (color);
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

void Sharik (int* x, int* y, int* vx, int* vy, double* v, double* dt)
    {
        *x = *x + *vx * *dt;
        *y = *y + *vy * *dt;

        ogranich (x, y, vx, vy, "Win 1!", TX_LIGHTGREEN);

        upravlenie (vx, vy, v, VK_UP, VK_LEFT, VK_DOWN, VK_RIGHT);
    }

void upravlenie (int* vx, int* vy, double* v, COLORREF vverh, COLORREF vlevo, COLORREF vniz, COLORREF vpravo)
    {
        if (GetAsyncKeyState(vverh))
            {
            *vx = 0;
            *vy = -*v;
            }
        if (GetAsyncKeyState(vlevo))
            {
            *vy = 0;
            *vx = -*v;
            }
        if (GetAsyncKeyState(vniz))
            {
            *vx = 0;
            *vy = *v;
            }
        if (GetAsyncKeyState(vpravo))
            {
            *vy = 0;
            *vx = *v;
            }
    }

void ogranich (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color)
    {
        if (*x < 0)
            {
            *vy = -10000;
            *vx = -10000;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text (text1, 100, 200, color);
            }
        if (*x > 1500)
            {
            *vy = 10000;
            *vx = 10000;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();

            text (text1, 100, 200, color);
            }
        if (*y > 800)
            {
            *vy = 10000;
            *vx = 10000;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text (text1, 100, 200, color);
            }
        if (*y < 0)
            {
            *vy = -10000;
            *vx = -10000;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text (text1, 100, 200, color);
            }
    }

void Pr (COLORREF color, const char* text1, int* x, int* y, int* vx, int* vy, int* Xpr, int* Ypr)
    {
        if (-20 < *Xpr - *x and *Xpr - *x < 20 and -50 < *Ypr - *y and *Ypr - *y < 50)
            {
            *vx = 0;
            *vy = 0;
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text (text1, 100, 200, color);
            }
    }

void Chit (double* v1)
    {
    if (GetAsyncKeyState ('C'))
        {
        *v1 = 3;
        }
    if (GetAsyncKeyState ('Q'))
        {
        *v1 = 2.5;
        }
    if (GetAsyncKeyState ('E'))
        {
        *v1 = 2;
        }
    if (GetAsyncKeyState ('Z'))
        {
        *v1 = 1.5;
        }
    if (GetAsyncKeyState ('X'))
        {
        *v1 = 1;
        }
    }
