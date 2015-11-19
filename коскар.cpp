#include "TXLib.h"
void DrowPushka (int x, int y, COLORREF color_Korpus, COLORREF color_turbin, COLORREF color_stabil);
void MovePushka ();
void Drou_SNARYAD (int x, int y, int rad, COLORREF color);
void Vragi (int x, int y, COLORREF color);
void upravl (double* vx, double* vy);
void Score (double Score, int x, int y, const char* tekst);
void Ogranich (int* x, int* y);

int main ()
    {
    txCreateWindow (1500, 800);
    MovePushka ();
    }

void MovePushka ()
    {
    int x = 100, y = 400, x_sn = x + 90, y_sn = y, x_vr = random(300, 1400), y_vr = -20;
    double schet = 0;
    double vx = 0, vy = 0;
    double vx_sn = 0, vy_sn = 0, vx_vr = 0, vy_vr = 3;
    COLORREF color_vr = TX_RED, color_Korpus = RGB(215, 215, 0), color_turbin = RGB(255, 69, 0),color_stabil = RGB(72, 118, 255), color_sn = TX_LIGHTRED;
    double dt = 1;

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        x = x + vx * dt;
        y = y + vy * dt;

        if (x_sn < x + 91)
            {
            y_sn = y;
            }
        x_sn = x_sn + vx_sn * dt;
        y_vr = y_vr + vy_vr * dt;

        Drou_SNARYAD (x_sn, y_sn, 15, color_sn);

        if (GetAsyncKeyState (VK_SPACE))
            {
            if (x_sn < 1485)
                {
                vy_sn = 0;
                vx_sn = 5;
                }
            else
                {
                x_sn = x + 90;
                vx_sn = 0;
                }
            }

        Vragi (x_vr, y_vr, color_vr);

        if (y_vr > 785)
            {
            x_vr = random(300, 1400);
            y_vr = -20;
            }

        DrowPushka (x, y, color_Korpus, color_turbin, color_stabil);

        upravl (&vx, &vy);
        Ogranich (&x, &y);
        if (txGetPixel (x, y) == txGetPixel (x_vr, y_vr)) break;
        if (txGetPixel (x_sn, y_sn) == txGetPixel (x_vr, y_vr))
            {
            schet = schet + 1;
            }
        Score (schet, 1400, 780, "У вас %lg очков");
        txSleep (0);
        }
    }

void Score (double Score, int x, int y, const char* tekst)
    {
    txSetColor (RGB(255, 215, 0));
    txSetFillColor (TX_BLACK);
    txRectangle (x - 100, y - 20, x + 100, y + 20);
    char text [100] = "";
    sprintf (text, tekst, Score);
    txTextOut (x - 75, y- 10, text);
    }

void DrowPushka (int x, int y, COLORREF color_Korpus, COLORREF color_turbin, COLORREF color_stabil)
    {
    txSetFillColor (color_Korpus);
    POINT Korpus [10] = {{x - 75, y - 45}, {x + 30, y - 45}, {x + 75, y - 30}, {x + 90, y - 15}, {x + 90, y + 15},
                         {x + 75, y + 30}, {x + 30, y + 45}, {x - 75, y + 45}, {x - 30, y + 15}, {x - 30, y - 15}};
    txPolygon (Korpus, 10);

    txSetFillColor (color_turbin);
    POINT turbin [4] = {{x - 30, y + 15}, {x - 75, y + 4}, {x - 75,  y - 4}, {x - 30, y - 15}};
    txPolygon (turbin, 4);

    txSetFillColor (color_stabil);
    POINT stabil1 [4] = {{x, y - 45}, {x - 30, y - 45}, {x - 45, y - 60}, {x - 15, y - 60}};
    txPolygon (stabil1, 4);

    POINT stabil2 [4] = {{x, y + 45}, {x - 30, y + 45}, {x - 45, y + 60}, {x - 15, y + 60}};
    txPolygon (stabil2, 4);
    }

void Drou_SNARYAD (int x, int y, int rad, COLORREF color)
    {
    txSetFillColor (color);
    txCircle (x, y, rad);
    }

void Vragi (int x, int y, COLORREF color)
    {
    txSetFillColor (color);
    POINT Vrag [4] = {{x - 25 , y - 20}, {x + 25 , y - 20},
                      {x + 25 , y + 20}, {x - 25 , y + 20}};
    txPolygon (Vrag, 4);
    }

void upravl (double* vx, double* vy)
    {
    if (!GetAsyncKeyState ('D' && 'A' && 'S' && 'W'))
        {
        *vx = 0;
        *vy = 0;
        }
    if (GetAsyncKeyState ('W'))
        {
        *vy = -2.5;
        }
    if (GetAsyncKeyState ('S'))
        {
        *vy = 2.5;
        }
    if (GetAsyncKeyState ('A'))
        {
        *vx = -2.5;
        }
    if (GetAsyncKeyState ('D'))
        {
        *vx = 2.5;
        }
    }

void Ogranich (int* x, int* y)
    {
    if (*x < 75)
        {
        *x = 75;
        }
    if (*x > 500)
        {
        *x = 500;
        }
    if (*y < 60)
        {
        *y = 60;
        }
    if (*y > 740)
        {
        *y = 740;
        }
    }
