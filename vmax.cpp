
#include "TXLib.h"

typedef double (func_t) (double x);

struct XY
    {
    double x, y;
    };

void Grafik (COLORREF color, double a, double b, func_t* f, double c = 1, double d = 0);
void Grafik_Parametr (COLORREF color, double a, double b, func_t* f1, func_t* f2, double kol_bo_pi , double c = 1, double d =0);
double Parabola (double x);
double Liney (double x);
double f_10_plus_x_delit_x (double x);
double f_1delit_x_umnogit_x_minus_9 (double x);
double sqrt_xplus2_plus_s_xminus2 (double x);
double prer_pryam (double x);
double diagr (double x);
double t_umnog_cos(double t);
double t_umnog_sin(double t);
double zvez_cos(double t);
double zvez_sin(double t);
double Babochka_sin (double t);
double Babochka_cos (double t);
double CatX (double t);
double CatY (double t);
void Setka (int Zoom, int a, int b);
void text (const char * text, int x, int y);
void All_Vmeste (int zoom, int a, int b);

int main()
    {
    double a = GetSystemMetrics (SM_CXSCREEN), b = GetSystemMetrics (SM_CYSCREEN);
    _txWindowStyle &= ~ WS_CAPTION;
    txCreateWindow (a, b);
    All_Vmeste (25, a, b);

    txTextCursor (false);

    double e = 0;

    while (e < 0.12)
        {
        Grafik_Parametr (TX_ORANGE, a, b, CatY, CatX, 5, e);
        e += 0.001;
        txSleep (0);
        }

    e = -2;
    All_Vmeste (25, a, b);

    while (e < 2)
        {
        Grafik (TX_MAGENTA, a, b, Parabola, e);
        e += 0.01;
        txSleep (0);
        }

    All_Vmeste (25, a, b);

    e = -2;
    while (e < 2)
        {
        Grafik (TX_GREEN, a, b, tan, e);
        e += 0.05;
        txSleep (0);
        }

    All_Vmeste (25, a, b);
    e = -2;

    while (e < 2)
        {
        Grafik (TX_RED, a, b, sin, e, 5);
        e += 0.04;
        txSleep (0);
        }

    All_Vmeste (25, a, b);
    e = -2;

    while (e < 2)
        {
        Grafik (TX_LIGHTGREEN, a, b, f_10_plus_x_delit_x, e);
        e += 0.03;
        txSleep (0);
        }

    All_Vmeste (25, a, b);
    e = -2;

    while (e < 2)
        {
        Grafik (TX_LIGHTMAGENTA, a, b, f_1delit_x_umnogit_x_minus_9, e);
        e += 0.1;
        txSleep (0);
        }

    All_Vmeste (25, a, b);
    e = -2;

    while (e < 2)
        {
        Grafik (TX_LIGHTRED, a, b, sqrt_xplus2_plus_s_xminus2, e);
        e += 0.05;
        txSleep (0);
        }

    All_Vmeste (25, a, b);
    e = -2;

    while (e < 2)
        {
        Grafik (TX_LIGHTBLUE, a, b, prer_pryam, e);
        e += 0.03;
        txSleep (0);
        }

    All_Vmeste (25, a, b);
    e = -2;

    while (e < 2)
        {
        Grafik (TX_LIGHTBLUE, a, b, diagr, e);
        e += 0.06;
        txSleep (0);
        }

    All_Vmeste (25, a, b);

    Grafik_Parametr (TX_ORANGE, a, b, t_umnog_cos, t_umnog_sin, 5);

    Grafik_Parametr (TX_GREEN, a, b, zvez_cos, zvez_sin, 20, 3, 5);

    Grafik_Parametr (TX_RED, a, b, Babochka_cos, Babochka_sin, 10, 2, -9);

    return 0;
    }

double CatX (double t)
    {
    return  - (721 * sin(t)) / 4 + 196 / 3 * sin(2 * t) - 86 / 3 * sin(3 * t) - 131 / 2 * sin(4 * t) + 477 / 14 * sin(5 * t) + 27 * sin(6 * t) - 29 / 2 * sin(7 * t) + 68 /
    5 * sin(8 * t) + 1 / 10 * sin(9 * t) + 23 / 4 * sin(10 * t) - 19 / 2 * sin(12 * t) - 85 / 21 * sin(13 * t) + 2 / 3 * sin(14 * t) + 27 / 5 * sin(15 * t) + 7 / 4 *
    sin(16 * t) + 17 / 9 * sin(17 * t) - 4 * sin(18 * t) - 1 / 2 * sin(19 * t) + 1 / 6 * sin(20 * t) + 6 / 7 * sin(21 * t) - 1 / 8 * sin(22 * t) + 1 / 3 * sin(23 * t) +
    3 / 2 * sin(24 * t) + 13 / 5 * sin(25 * t) + sin(26 * t) - 2 * sin(27 * t) + 3 / 5 * sin(28 * t) - 1 / 5 * sin(29 * t) + 1 / 5 * sin(30 * t) + (2337 * cos(t)) / 8 -
    43 / 5 * cos(2 * t) + 322 / 5 * cos(3 * t) - 117 / 5 * cos(4 * t) - 26 / 5 * cos(5 * t) - 23 / 3 * cos(6 * t) + 143 / 4 * cos(7 * t) - 11 / 4 * cos(8 * t) - 31 / 3 *
    cos(9 * t) - 13 / 4 * cos(10 * t) - 9 / 2 * cos(11 * t) + 41 / 20 * cos(12 * t) + 8 * cos(13 * t) + 2 / 3 * cos(14 * t) + 6 * cos(15 * t) + 17 / 4 * cos(16 * t) - 3 /
    2 * cos(17 * t) - 29 / 10 * cos(18 * t) + 11 / 6 * cos(19 * t) + 12 / 5 * cos(20 * t) + 3 / 2 * cos(21 * t) + 11 / 12 * cos(22 * t) - 4 / 5 * cos(23 * t) + cos(24 * t) +
    17 / 8 * cos(25 * t) - 7 / 2 * cos(26 * t) - 5 / 6 * cos(27 * t) - 11 / 10 * cos(28 * t) + 1 / 2 * cos(29 * t) - 1 / 5 * cos(30 * t);
    }

double CatY (double t)
    {
    return  - (637 * sin(t)) / 2 - 188 / 5 * sin(2 * t) - 11 / 7 * sin(3 * t) - 12 / 5 * sin(4 * t) + 11 / 3 * sin(5 * t) - 37 / 4 * sin(6 * t) + 8 / 3 * sin(7 * t) +
    65 / 6 * sin(8 * t) - 32 / 5 * sin(9 * t) - 41 / 4 * sin(10 * t) - 38 / 3 * sin(11 * t) - 47 / 8 * sin(12 * t) + 5 / 4 * sin(13 * t) - 41 / 7 * sin(14 * t) - 7 / 3 *
    sin(15 * t) - 13 / 7 * sin(16 * t) + 17 / 4 * sin(17 * t) - 9 / 4 * sin(18 * t) + 8 / 9 * sin(19 * t) + 3 / 5 * sin(20 * t) - 2 / 5 * sin(21 * t) + 4 / 3 * sin(22 * t) +
    1 / 3 * sin(23 * t) + 3 / 5 * sin(24 * t) - 3 / 5 * sin(25 * t) + 6 / 5 * sin(26 * t) - 1 / 5 * sin(27 * t) + 10 / 9 * sin(28 * t) + 1 / 3 * sin(29 * t) - 3 / 4 *
    sin(30 * t) - (125 * cos(t)) / 2 - 521 / 9 * cos(2 * t) - 359 / 3 * cos(3 * t) + 47 / 3 * cos(4 * t) - 33 / 2 * cos(5 * t) - 5 / 4 * cos(6 * t) + 31 / 8 * cos(7 * t) +
    9 / 10 * cos(8 * t) - 119 / 4 * cos(9 * t) - 17 / 2 * cos(10 * t) + 22 / 3 * cos(11 * t) + 15 / 4 * cos(12 * t) - 5 / 2 * cos(13 * t) + 19 / 6 * cos(14 * t) + 7 / 4 *
    cos(15 * t) + 31 / 4 * cos(16 * t) - cos(17 * t) + 11 / 10 * cos(18 * t) - 2 / 3 * cos(19 * t) + 13 / 3 * cos(20 * t) - 5 / 4 * cos(21 * t) + 2 / 3 * cos(22 * t) + 1 / 4 *
    cos(23 * t) + 5 / 6 * cos(24 * t) + 3 / 4 * cos(26 * t) - 1 / 2 * cos(27 * t) - 1 / 10 * cos(28 * t) - 1 / 3 * cos(29 * t) - 1 / 19 * cos(30 * t);
    }

double Parabola (double x)
    {
    return x * x;
    }

double Liney (double x)
    {
    return x;
    }

double f_10_plus_x_delit_x (double x)
    {
    return (-10 + x) / x;
    }

double f_1delit_x_umnogit_x_minus_9 (double x)
    {
    return 1 / (x * x - 9);
    }

double sqrt_xplus2_plus_s_xminus2 (double x)
    {
    return sqrt((x + 2) * (x + 2)) + sqrt((x - 2) * (x - 2));
    }

double prer_pryam (double x)
    {
    return abs(x - 1) * (x * x - 4) / (x - 1);
    }

double diagr (double x)
    {
    return (1 + sin(x)) * (1 + 0.9 * cos(8 * x))*(1 + 0.1 * cos(24 * x));
    }

double t_umnog_sin(double t)
    {
    return t * sin(t);
    }

double t_umnog_cos(double t)
    {
    return t * cos(t);
    }

double zvez_cos(double t)
    {
    return (cos(t) + cos(1.1 * t) / (1.1));
    }

double zvez_sin(double t)
    {
    return (sin(t) - sin(1.1 * t) / (1.1));
    }

double Babochka_sin (double t)
    {
    return sin(t) * (exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 12), 5));
    }

double Babochka_cos (double t)
    {
    return cos(t) * (exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 12), 5));
    }

void Grafik (COLORREF color, double a, double b, func_t* f, double c /*= 1*/, double d /*=0*/)
    {
    XY xy = {-a / 50};
    txSetFillColor (color);
    txSetColor (color);

    //text ("y= x*x*(x-2)*(x-2)", 0, 50);
    while (xy.x <= +a / 50)
        {
        xy.y = c * f (xy.x) + d;

        txCircle (xy.x * 25 + a / 2, -xy.y * 25 + b / 2, 1);

        if (xy.x > 0.01 || xy.x < -0.02)
            {
            xy.x += 0.003;
            }
        else
            {
            xy.x = 0.02;
            }

        if (xy.x <= -2.98 && xy.x >= - 3.02)
            {
            xy.x = - 2.97;
            }
        if (xy.x >= 2.98 && xy.x <= 3.02)
            {
            xy.x = 3.03;
            }
        if (xy.x > 3.02 || xy.x < -3.02)
            {
            xy.x += 0.003;
            }
        if (xy.x < 2.98 && xy.x > -2.98)
            {
            xy.x += 0.003;
            }
        if (xy.x >= 0.99 && xy.x < 1.01)
            {
            xy.x = 1.02;
            }
        //txSleep (0);
        }
    }

void Grafik_Parametr (COLORREF color, double a, double b, func_t* f1, func_t* f2, double kol_bo_pi , double c /*= 1*/, double d /*=0*/)
    {
    XY xy = {0};
    txSetFillColor (color);
    txSetColor (color);
    double t = 0;

    while (t <= kol_bo_pi * txPI)
        {
        xy.y = c * f1(t) + d;
        xy.x = c * f2(t) + d;

        txCircle (xy.x * 25 + a / 2, -xy.y * 25 + b / 2, 1);

        t += 0.005;

        //txSleep (0);
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
