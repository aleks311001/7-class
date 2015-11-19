
#include "TXLib.h"

typedef void (ner) (double x, double y, double Zoom);

double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);

void DrawNerav (double Zoom, ner* narav);
void Paraboli_s_glazom (double x, double y, double Zoom);

int main()
    {
    _txWindowStyle &= ~ WS_CAPTION;

    txCreateWindow (XWindow, YWindow);

    DrawNerav (50, Paraboli_s_glazom);

    return 0;
    }

void DrawNerav (double Zoom, ner* nerav)
    {
    for (double y = -YWindow / (2 * Zoom); y <= YWindow / (2 * Zoom); y += 2 / Zoom)
        {
        for (double x = -XWindow / (2 * Zoom); x <= XWindow / (2 * Zoom); x += 2 / Zoom)
            {
            nerav (x, y, Zoom);
            }
        }
    }

void Paraboli_s_glazom (double x, double y, double Zoom)
    {
    if (y >=  x * x - 4)
        {
        txSetPixel (x * Zoom + XWindow/2, -y * Zoom + YWindow / 2,         RGB (255, 0, 0));
        }
    if (y <= -x * x + 4)
        {
        txSetPixel (x * Zoom + XWindow/2, -y * Zoom + YWindow / 2 + 1,     RGB (0, 255, 0));
        }
    if (x * x + y * y <= 8)
        {
        txSetPixel (x * Zoom + XWindow/2 + 1, -y * Zoom + YWindow / 2,     RGB (0, 0, 255));
        }
    txSetPixel (x * Zoom + XWindow/2 + 1, -y * Zoom + YWindow / 2 + 1,    RGB (255 / 3, 255 / 3, 255 / 3));
    }


