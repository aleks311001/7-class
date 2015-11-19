#include "TXLib.h"
void MoveShar ();
void text (const char * text, int x, int y, COLORREF color);
void Score (double Score, int x, int y);
void Sharik (int* x, int* y, int* vx, int* vy, double* v, double* dt);
void upravlenie (int* vx, int* vy, double* v, COLORREF vverh, COLORREF vlevo, COLORREF vniz, COLORREF vpravo);
void ogranich (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color);
void Sharik1 (int* x, int* y, int* vx, int* vy, double* v, double* dt);
void DrawShar (int x, int y, int Diametr, COLORREF color);
double Dist (int x1, int y1, int x2, int y2);
void ogranich_COMP (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color);
void Sharik_COMP (int* x, int* y, int* vx, int* vy, double* v, double* dt);

int main ()
    {
    txCreateWindow (1500, 800);
    MoveShar ();
    }

void MoveShar ()
    {
    int x = 100, y = 100;
    int x1 = 1000, y1 = 700;
    int x2 = 500, y2 = 300;
    int x3 = 800, y3 = 500;
    int x4 = 906, y4 = 701;
    int vx = 3, vy = 0;
    int vx1 = -3, vy1 = 0;
    int vx2 = -3, vy2 = 3;
    int vx3 = 4, vy3 = 4;
    int vx4 = 5, vy4 = -5;
    double dt = 1;
    double v = 3;
    double Diametr = 20;
    double Diametr1 = 10;

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

        DrawShar (x, y, Diametr, TX_LIGHTBLUE);
        DrawShar (x1, y1, Diametr, TX_LIGHTGREEN);
        DrawShar (x2, y2, Diametr, TX_RED);
        DrawShar (x3, y3, Diametr, TX_RED);
        DrawShar (x4, y4, Diametr, TX_RED);

        Sharik (&x, &y, &vx, &vy, &v, &dt);
        Sharik1 (&x1, &y1, &vx1, &vy1, &v, &dt);
        Sharik_COMP (&x2, &y2, &vx2, &vy2, &v, &dt);
        Sharik_COMP (&x3, &y3, &vx3, &vy3, &v, &dt);
        Sharik_COMP (&x4, &y4, &vx4, &vy4, &v, &dt);

        if (Dist (x1, y1, x2, y2) <= 15 + 15)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 2!", 100, 200, TX_LIGHTBLUE);
            break;
            }
        if (Dist (x1, y1, x3, y3) <= 15 + 15)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 2!", 100, 200, TX_LIGHTBLUE);
            break;
            }
        if (Dist (x, y, x2, y2) <= 15 + 15)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 1!", 100, 200, TX_LIGHTGREEN);
            break;
            }
        if (Dist (x, y, x3, y3) <= 15 + 15)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 1!", 100, 200, TX_LIGHTGREEN);
            break;
            }
        if (Dist (x, y, x4, y4) <= 15 + 15)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 1!", 100, 200, TX_LIGHTGREEN);
            break;
            }
        if (Dist (x1, y1, x4, y4) <= 15 + 15)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 2!", 100, 200, TX_LIGHTBLUE);
            break;
            }
        txSleep (0);
        }
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

void Sharik1 (int* x, int* y, int* vx, int* vy, double* v, double* dt)
    {
        *x = *x + *vx * *dt;
        *y = *y + *vy * *dt;

        ogranich (x, y, vx, vy, "Win 2!", TX_LIGHTBLUE);

        upravlenie (vx, vy, v, 'W', 'A', 'S', 'D');
    }

void Sharik_COMP (int* x, int* y, int* vx, int* vy, double* v, double* dt)
    {
        *x = *x + *vx * *dt;
        *y = *y + *vy * *dt;

        ogranich_COMP  (x, y, vx, vy, "Win 2!", TX_LIGHTRED);
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

void ogranich_COMP (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color)
    {
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
            y = 0;
            *vy = -*vy;
            }
    }

double Dist (int x1, int y1, int x2, int y2)
    {
    return sqrt ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }

void DrawShar (int x, int y, int Diametr, COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);
    txCircle (x, y, Diametr);
    }
