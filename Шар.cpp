#include "TXLib.h"
struct CRest
    {
    int x, y;
    double ZoomX;
    };
struct CBall
    {
    double x, y;
    double vx, vy;
    double r;
    };//
void Move_Platf ();
void Drow_Platf (double x, double y, double ZoomX);
void upravlenie (double* vx, double v, COLORREF vlevo, COLORREF vpravo);
void ogranich (double* x, double vx, double dt, double ZoomX);
void Drow_Shar (CBall ball);
void ogranich_Shar (CBall* b, double x_pl, double y_pl, double ZoomX, double* dt);
void text (const char * text, int x, int y, COLORREF color);
void Vzr (CRest Rest, CBall* b);

int main ()
    {
    txCreateWindow (1500, 800);
    Move_Platf ();
    }

void Move_Platf ()
    {
    CRest Rest [1000] = {}; //dddd
    double x = 750, y = 700, ZoomX = 10, vx = 0, v = 10, dt = 1;
    CBall ball = {750, 675, random (5, 10), random (-10, -5), 15};
    int i = 1;

    HDC fon = txLoadImage ("fon.bmp");

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        if (!GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txClear ();
            }
        assert (i > 0 && i <= 1000);
        txBitBlt (txDC(), 0, 0, 1500, 800, fon, 0, 0);
        while (i < 1000)
            {
            int Randome  = random (1, 38);
            int Rendome2 = random (1, 23);
            Rest[i].x = Randome * 40;
            Rest[i].y = Rendome2 * 20;
            Rest[i].ZoomX = 2;
            i++;
            }

        i = 1;
        while (i < 1000)
            {
            Drow_Platf (Rest[i].x, Rest[i].y, Rest[i].ZoomX);
            i++;
            }
        i = 1;

        while (i < 1000)
            {
            Vzr (Rest[i], &ball);
            i++;
            }

        Drow_Platf (x, y, ZoomX);
        ogranich (&x, vx, dt, ZoomX);
        upravlenie (&vx, v, 'A', 'D');                                     //

        Drow_Shar (ball);
        ogranich_Shar (&ball, x, y, ZoomX, &dt);

        if (ball.y + ball.r > 800)
            {
            text ("Game Over!", 200, 250, TX_RED);
            break;
            }
        txSleep (0);
        }

    txDeleteDC (fon);
    }

void Drow_Platf (double x, double y, double ZoomX)
    {
    txSetFillColor (RGB(127, 255, 0));
    POINT Prepyatstvie [4] = {{x - 10 * ZoomX, y - 10}, {x + 10 * ZoomX, y - 10}, {x + 10 * ZoomX, y + 10}, {x - 10 * ZoomX, y + 10}};
    txPolygon (Prepyatstvie, 4);
    }

void ogranich (double* x, double vx, double dt, double ZoomX)
    {
    *x = *x + vx * dt;

    if (*x - 10 * ZoomX < 0)
        {
        *x = 10 * ZoomX;
        }
    if (*x + 10 * ZoomX > 1500)
        {
        *x = 1500 - 10 * ZoomX;
        }
    }

void upravlenie (double* vx, double v, COLORREF vlevo, COLORREF vpravo)
    {
    if (!GetAsyncKeyState (vpravo && vlevo))
        {
        *vx = 0;
        }
    if (GetAsyncKeyState (vlevo))
        {
        *vx = -v;
        }
    if (GetAsyncKeyState (vpravo))
        {
        *vx = v;
        }
    }

void Drow_Shar (CBall ball)
    {
    txSetFillColor (RGB (255, 193, 37));
    txCircle (ball.x, ball.y, ball.r);
    }

void ogranich_Shar (CBall* b, double x_pl, double y_pl, double ZoomX, double* dt)
     {
     b->x = b->x + b->vx * *dt;
     b->y = b->y + b->vy * *dt;
     *dt += 0.001;

    if (b->x - b->r < 0)
        {
        b->x = 0 + b->r;
        b->vx = -b->vx;
        }
    if (b->x + b->r > 1500)
        {
        b->x = 1500 - b->r;
        b->vx = -b->vx;
        }
    if (b->y - b->r < 0)
        {
        b->y = 0 + b->r;
        b->vy = -b->vy;
        }

    if (y_pl + 10 + b->r >= b->y && y_pl - 10 - b->y - b->r <= 0 && x_pl - 10 * ZoomX <= b->x && x_pl + 10 * ZoomX >= b->x)
        {
        b->y = y_pl - 10 - b->r;
        b->vy = -b->vy;
        }
    }

void text (const char * text, int x, int y, COLORREF color)
    {
    txSetColor (color);
    txSelectFont ("Comic Sans MS", 300, 100, 50, false, false, false, 0);
    txTextOut (x, y, text);
    }

void Vzr (CRest Rest, CBall* b)
    {
    if (Rest.y - b->y <= 10 + b->r && b->y - Rest.y <= 10 + b->r && b->x - Rest.x <= 10 * Rest.ZoomX + b->r && Rest.x - b->x <= 10 * Rest.ZoomX + b->r)
        {
        b->vy = -b->vy;
        }
    }
