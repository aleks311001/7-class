#include "Sasha.h"

int main()
    {
    txCreateWindow (1000, 800);
    txSetFillColor (TX_WHITE);
    txClear ();
    Setka (25);

    Grafik4 (0.5, 5);

    txSetFillColor (TX_WHITE);
    txClear ();
    Setka (50);

    GrafikVolna ();

    txSetFillColor (TX_WHITE);
    txClear ();
    Setka (50);

    Grafik ();

    txSetFillColor (TX_WHITE);
    txClear ();
    Setka (50);

    Grafik2 ();

    txSetFillColor (TX_WHITE);
    txClear ();
    Setka (25);

    Grafik3 ();

    return 0;
    }
