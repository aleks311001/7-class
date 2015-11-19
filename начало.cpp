#include "TXLib.h"
void text (int x, int y, COLORREF color);
void Nachalo ();

int main ()
    {
    txCreateWindow (1500, 800);
    Nachalo ();
    }

void Nachalo ()
    {
    int x = 300, y = 400;
    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_LIGHTGREEN);
        txClear ();
        text (x, y, TX_BLUE);
        }

    }

void text (int x, int y, COLORREF color)
    {
    txSetColor (RGB(255, 215, 0));
    txSetFillColor (TX_GREEN);
    txRectangle (x, y, x + 100, y + 50);
    txSetColor (color);
    txSelectFont ("Arial", 50, 16, 50, false, false, false, 0);
    txTextOut (x, y, "Play");
    }
