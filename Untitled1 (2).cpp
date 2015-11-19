#include "TXLib.h"

struct XY
    {
    double x, y;
    };

void Grafik (COLORREF color, double a, double b);
void Grafik2(double a, double b, COLORREF color, double a_o, double b_o);
void Grafik3 (COLORREF color, double a, double b);
void Grafik4 (COLORREF color, double a, double b);
void Grafik5 (COLORREF color, double a, double b);
void Grafik6 (COLORREF color, double a, double b);
void Grafik7 (COLORREF color, double a, double b);
void Setka (int Zoom, int a, int b);
void text (const char * text, int x, int y);
void All_Vmeste (int zoom, int a, int b);

int main()
    {
    double a = 800, b = 800;

    txCreateWindow (a, b);
    All_Vmeste (25, a, b);

    Grafik7 (TX_GREEN, a, b);

    Grafik6 (TX_RED, a, b);

    All_Vmeste (25, a, b);

    Grafik5 (TX_BLUE, a, b);

    Grafik4 (TX_ORANGE, a, b);

    All_Vmeste (25, a, b);

    Grafik3 (TX_MAGENTA, a, b);

    Grafik2 (5, 10, TX_LIGHTGREEN, a, b);

    Grafik (TX_LIGHTBLUE, a, b);


    return 0;
    }

void Grafik (COLORREF color, double a, double b)
    {
    XY xy = {-3};
    txSetFillColor (color);
    txSetColor (color);

    text ("y= x*x*(x-2)*(x-2)", 0, 50);
    while (xy.x <= +3)
        {
        xy.y = xy.x * xy.x * (xy.x - 2) * (xy.x - 2);

        txCircle (xy.x * 25 + a / 2, -xy.y * 25 + b / 2, 2);
        xy.x += 0.005;

        txSleep (0);
        }
    }

void Grafik2(double a, double b, COLORREF color, double a_o, double b_o)
    {
    XY xy = {-a_o / 50};
    txSetFillColor (color);
    txSetColor (color);

    text ("y = a*x+b", 0, 750);

    while (xy.x <= +a_o / 50)
        {
        xy.y = a * xy.x + b;

        txCircle (xy.x * 25 + a_o / 2, -xy.y * 25 + b_o / 2, 2);
        xy.x+=0.05;

        txSleep (0);
        }
    }

void Grafik3 (COLORREF color, double a, double b)
    {
    XY xy = {-a / 50};
    txSetFillColor (color);
    txSetColor (color);

    text ("y = arctg(2Cos(x))-5", a - 200, 50);
    while (xy.x <= +a / 50)
        {
        xy.y = atan(2 * cos(xy.x)) - 5;

        txCircle (xy.x * 25 + a / 2, -xy.y * 25 + b / 2, 2);
        xy.x += 0.01;

        txSleep (0);
        }
    }

void Grafik4 (COLORREF color, double a, double b)
    {
    XY xy = {-a / 50};
    txSetFillColor (color);
    txSetColor (color);

    text ("y = 2^(1/x)", 0, 50);
    while (xy.x <= +a / 50)
        {
        xy.y = pow (2, 1 / xy.x);

        txCircle (xy.x * 25 + a / 2, -xy.y * 25 + b / 2, 2);

        if (xy.x > 0.01 || xy.x < -0.01)
            {
            xy.x += 0.01;
            }
        if (xy.x >= -0.01 && xy.x <= 0.01)
            {
            xy.x = 0.21;
            }

        txSleep (0);
        }
    }

void Grafik5 (COLORREF color, double a, double b)
    {
    XY xy = {-5};
    txSetFillColor (color);
    txSetColor (color);

    text ("y = |x-1|*(x^2-4)/(x - 1)", 0, 750);
    while (xy.x <= +6)
        {
        xy.y = abs(xy.x - 1) * (xy.x * xy.x - 4) / (xy.x - 1);

        txCircle (xy.x * 25 + a / 2, -xy.y * 25 + b / 2, 2);

        if (xy.x > 1.01 || xy.x < 0.99)
            {
            xy.x += 0.01;
            }
        if (xy.x >= 0.99 && xy.x < 1.01)
            {
            xy.x = 1.02;
            }
        txSleep (0);
        }
    }

void Grafik6 (COLORREF color, double a, double b)
    {
    XY xy = {0};
    txSetFillColor (color);
    txSetColor (color);
    double t = 0;

    text ("y = t*sin(t)", a - 150, 700);
    text ("x = t*cos(t)", a - 150, 750);
    while (t <= 5 * txPI)
        {
        xy.y = t * sin(t) + 5;
        xy.x = t * cos(t) + 5;

        txCircle (xy.x * 25 + a / 2, -xy.y * 25 + b / 2, 2);

        t += 0.01;

        txSleep (0);
        }
    }

void Grafik7 (COLORREF color, double a, double b)
    {
    XY xy = {0};
    txSetFillColor (color);
    txSetColor (color);
    double t = 0;

    text ("y = cos(t)*(exp(cos(t))-2*cos(4*t)+sin(t/12)^5)", 0, 10);
    text ("x = sin(t)*(exp(cos(t))-2*cos(4*t)+sin(t/12)^5)", 0, 60);
    while (t <= 10 * txPI)
        {
        xy.x = sin(t) * (exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 12), 5)) - 5;
        xy.y = cos(t) * (exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 12), 5)) - 5;

        txCircle (xy.x * 50 + a / 2, -xy.y * 50 + b / 2, 1);

        t += 0.005;

        txSleep (0);
        }
    }

void Setka (int Zoom, int a, int b)
    {
    XY xy = {};

    txSetColor (TX_BLACK);

    while (xy.x < a / Zoom)
        {
        txLine (xy.x * Zoom, xy.y, xy.x * Zoom, b);
        xy.x++;
        }

    xy.x = 0;
    while (xy.y < b / Zoom)
        {
        txLine (xy.x, xy.y * Zoom, a, xy.y * Zoom);
        xy.y++;
        }
    txSetColor (TX_BLACK, 3);
    txLine (0, b / 2, a, b / 2);
    txLine (a / 2, 0, a / 2, b);
    txLine (a, b / 2, a - 30, b / 2 - 15);
    txLine (a, b / 2, a - 30, b / 2 + 15);
    txLine (a / 2, 0, a / 2 + 15 , 30);
    txLine (a / 2, 0, a / 2 - 15, 30);
    }

void text (const char * text, int x, int y)
    {
    txSelectFont ("Comic Sans MS", 30, 10, 50, false, false, false, 0);
    txTextOut (x, y, text);
    }

void All_Vmeste (int zoom, int a, int b)
    {
    txSetFillColor (TX_WHITE);
    txClear ();
    Setka (zoom, a, b);
    }
