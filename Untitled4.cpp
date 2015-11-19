#include "TXLib.h"

struct XY
    {
    double x, y;
    };

void Setka (int Zoom);
void All_Vmeste (int zoom);
void Grafik3(COLORREF color);
void Grafik9 (COLORREF color);
void Grafik12 (COLORREF color)æ

int main()
    {
    txCreateWindow (1000, 800);
    All_Vmeste (25);

    Grafik3 (TX_RED);
    Grafik9 (TX_ORANGE);
    Grafik12 (TX_GREEN);
    }

void All_Vmeste (int zoom)
    {
    txSetFillColor (TX_WHITE);
    txClear ();
    Setka (zoom);
    }

void Setka (int Zoom)
    {
    XY xy = {};

    txSetColor (TX_BLACK);

    while (xy.x < 40)
        {
        txLine (xy.x*Zoom, xy.y, xy.x*Zoom, 1000);
        xy.x++;
        }

    xy.x = 0;
    while (xy.y < 36)
        {
        txLine (xy.x, xy.y*Zoom, 1000, xy.y*Zoom);
        xy.y++;
        }
    txSetColor (TX_BLACK, 3);
    txLine (0, 400, 1000, 400);
    txLine (500, 0, 500, 800);
    }

void Grafik3(COLORREF color)
    {
    XY xy = {-7};
    txSetFillColor (color);
    txSetColor (color);

    while (xy.x < 7)
        {
        xy.y = -3*xy.x*xy.x/49 + 8;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.05;

        txSleep (0);
        }

    xy.x = -7;

    while (xy.x < 7)
        {
        xy.y = 4*xy.x*xy.x/49 + 1;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.05;

        txSleep (0);
        }

    xy.x = -6.8;

    while (xy.x < -2)
        {
        xy.y = -0.75*(xy.x + 4)*(xy.x + 4) + 11;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.025;

        txSleep (0);
        }

    xy.x = 2;

    while (xy.x < 6.8)
        {
        xy.y = -0.75*(xy.x - 4)*(xy.x - 4) + 11;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.025;

        txSleep (0);
        }

    xy.x = -5.8;

    while (xy.x < -2.8)
        {
        xy.y = -(xy.x + 4)*(xy.x + 4) + 9;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.025;

        txSleep (0);
        }

    xy.x = 2.8;

    while (xy.x < 5.8)
        {
        xy.y = -(xy.x - 4)*(xy.x - 4) + 9;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.025;

        txSleep (0);
        }

    xy.x = -4;

    while (xy.x < 4)
        {
        xy.y = 4*xy.x*xy.x/9 - 5;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.025;

        txSleep (0);
        }

    xy.x = -5.2;

    while (xy.x < 5.2)
        {
        xy.y = 4*xy.x*xy.x/9 - 9;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.025;

        txSleep (0);
        }

    xy.x = -7;

    while (xy.x < -2.8)
        {
        xy.y = -(xy.x + 3)*(xy.x + 3)/4 - 6;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.05;

        txSleep (10);
        }

    xy.x = 2.8;

    while (xy.x < 7)
        {
        xy.y = -(xy.x - 3)*(xy.x - 3)/4 - 6;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.05;

        txSleep (10);
        }

    xy.x = -7;

    while (xy.x < 0)
        {
        xy.y = (xy.x + 4)*(xy.x + 4)/9 - 11;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.05;

        txSleep (0);
        }

    xy.x = 0;

    while (xy.x < 7)
        {
        xy.y = (xy.x - 4)*(xy.x - 4)/9 - 11;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.05;

        txSleep (0);
        }

    xy.x = -7;

    while (xy.x < -4.5)
        {
        xy.y = -(xy.x + 5)*(xy.x + 5);

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.025;

        txSleep (0);
        }

    xy.x = 4.5;

    while (xy.x < 7)
        {
        xy.y = -(xy.x - 5)*(xy.x - 5);

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.025;

        txSleep (0);
        }

    xy.x = -3;

    while (xy.x < 3)
        {
        xy.y = 2*xy.x*xy.x/9 + 2;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);
        xy.x+=0.05;

        txSleep (0);
        }

    }

void Grafik9 (COLORREF color)
    {
    XY xy = {-10};
    txSetFillColor (color);
    txSetColor (color);

    text ("|y| + |x| = 1", 850, 770);
    while (xy.x <= 0)
        {
        xy.y = 10 + xy.x;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);

        xy.x +=0.05;

        txSleep (0);
        }

    xy.x = -10;

    while (xy.x <= 0)
        {
        xy.y = -xy.x - 10;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);

        xy.x +=0.05;

        txSleep (0);
        }

    xy.x = 0;

    while (xy.x <= 10)
        {
        xy.y = 10 - xy.x;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);

        xy.x +=0.05;

        txSleep (0);
        }

    xy.x = 0;

    while (xy.x <= 10)
        {
        xy.y = xy.x - 10;

        txCircle (xy.x*25 + 1000/2, -xy.y*25 + 800/2, 2);

        xy.x +=0.05;

        txSleep (0);
        }
    }

void Grafik12 (COLORREF color)
    {
    XY xy = {-4};
    XY ab = {-4};
    txSetFillColor (color);
    txSetColor (color);

    while (xy.x <= +4 && ab.x <= +4)
        {
        xy.y =  sqrt(16 - xy.x*xy.x);
        ab.y = -sqrt(16 - ab.x*ab.x);

        txCircle (xy.x*50 + 1000/2, -xy.y*50 + 800/2, 2);
        txCircle (ab.x*50 + 1000/2, -ab.y*50 + 800/2, 2);

        xy.x+=0.01;
        ab.x+=0.01;

        txSleep (0);
        }
    }
