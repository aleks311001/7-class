#include "TXLib.h"
void Derevo (int x, int y, double zoomX, double zoomY, COLORREF colorcrona, int Crona);
void Mashina (int x, int y, double zoomX, double zoomY, COLORREF colorshina, COLORREF colordiski, COLORREF colormashina, COLORREF colorokno, int diametrcoles);
void chelovek (int x, int y, double zoomX, double zoomY, int handup, int legs, COLORREF colorgolova, COLORREF colorglaza);
void Dom (int x, int y, double zoomX, double zoomY);
void dog (int x, int y, double zoomX, double zoomY, int hvost, COLORREF color_sobaka, COLORREF color_nos, COLORREF color_nosniz, COLORREF color_glaz, COLORREF color_ushi);
void Avtobus(int x, int y, double zoomX, double zoomY, COLORREF coloravtobus, COLORREF colorokkno, COLORREF colorshinu,COLORREF colordiska,int  diametrcoles);
void Buh (int x, int y, double zoomX, double zoomY, COLORREF color_snarudgi, COLORREF color_vnutri);
void Pushka (int x, int y, double zoomX, double zoomY, double diametrcol, COLORREF color_pli, COLORREF color_dulo, COLORREF color_platforma, COLORREF color_colesa);
void Text (const char * text, int x, int y, int visota, int shirina, const char * Srift, bool kursiv, int Ugol, COLORREF color);
void Nazvanie (int t);
void Nachalo_Vstrecha ();
void Nachalo_Vozvrashenie();
void Razvitie ();
void Kradga ();
void Pomosh ();
void Smert ();
void Vozvrat_doma ();
void Pobeda ();
void Konech ();

int main()
    {
    txCreateWindow (1500, 850);

    txSetColor(RGB(150, 150, 150));
    txLine (0, 600, 1600, 600);
    txLine (0, 1000, 1600, 1000);
    txSetFillColor(RGB(150, 150, 150));
    txFloodFill(1, 800);
    txSetColor (RGB(128, 255, 0));
    txLine (0, 400, 1600, 400);
    txSetFillColor(RGB(128, 255, 0));
    txFloodFill(44, 560);
    txSetFillColor(RGB(162, 255, 255));
    txFloodFill(22, 50);

    txSetColor (TX_BLACK);

    Nazvanie (20);
    Nachalo_Vstrecha ();
    Nachalo_Vozvrashenie ();
    Razvitie ();
    Kradga ();
    Pomosh ();
    Smert ();
    Vozvrat_doma ();
    Pobeda ();
    Konech ();

    return 0;
    }

void Avtobus(int x, int y, double zoomX, double zoomY, COLORREF coloravtobus, COLORREF colorokkno, COLORREF colorshinu,COLORREF colordiska, int diametrcoles)

    {
    POINT avtobus[6] = {{x - 336 * zoomX, y - 40 * zoomY}, {x - 296 * zoomX, y - 160 * zoomY}, {x + 404 * zoomX, y - 160 * zoomY}, {x + 424 * zoomX, y - 120 * zoomY}, {x + 424 * zoomX, y + 100 * zoomY}, {x - 336 * zoomX, y + 100 * zoomY}};
    txSetFillColor (coloravtobus);
    txPolygon (avtobus, 6);

    txSetFillColor (colorshinu);
    txCircle (x - 216 * zoomX, y + 100 * zoomY, 40 * zoomX * diametrcoles);
    txCircle (x + 304 * zoomX, y + 100 * zoomY, 40 * zoomX * diametrcoles);

    txSetFillColor (colordiska);
    txCircle (x + 304 * zoomX, y + 100 * zoomY, 30 * zoomX * diametrcoles);
    txCircle (x - 216 * zoomX, y + 100 * zoomY, 30 * zoomX * diametrcoles);

    txSetFillColor (coloravtobus);
    POINT Dver[7] {{x - 316 * zoomX, y - 40 * zoomY}, {x - 280 * zoomX, y - 140 * zoomY}, {x - 200 * zoomX, y - 140 * zoomY}, {x - 200 * zoomX, y + 40 * zoomY}, {x - 260 * zoomX, y + 40 * zoomY}, {x - 280 * zoomX, y + 80 * zoomY}, {x - 316 * zoomX, y + 80 * zoomY}};
    txPolygon (Dver, 7);

    POINT okno_v_dveri[5] = {{x - 296 * zoomX, y - 40 * zoomY}, {x - 260 * zoomX, y - 120 * zoomY}, {x - 220 * zoomX, y - 120 * zoomY}, {x - 220 * zoomX, y}, {x - 296 * zoomX, y}};
    txSetFillColor (colorokkno);
    txPolygon (okno_v_dveri, 5);

    POINT okno[4] = {{x - 180 * zoomX, y - 120 * zoomY}, {x + 360 * zoomX, y - 120 * zoomY}, {x + 360 * zoomX, y}, {x - 180 * zoomX, y}};
    txPolygon (okno, 4);

    txLine (x, y - 120 * zoomY, x, y);
    txLine (x + 180 * zoomX, y, x + 180 * zoomX, y - 120 * zoomY);
    }
void Derevo (int x, int y, double zoomX, double zoomY, COLORREF colorcrona, int Crona)

    {
    POINT stvol[4] = {{x - 20 * zoomX, y + 150 * zoomY}, {x - 20 * zoomX, y + 270 * zoomY}, {x + 20 * zoomX, y + 270 * zoomY}, {x + 20 * zoomX, y + 150 * zoomY}};
    txSetFillColor (RGB(170, 85, 0));
    txPolygon (stvol,4);
    txSetFillColor (colorcrona);
    txCircle (x, y, 160 * zoomY * Crona);
    }

void Mashina (int x, int y, double zoomX, double zoomY, COLORREF colorshina, COLORREF colordiski, COLORREF colormashina, COLORREF colorokno, int diametrcoles)

    {
    POINT mashina[12] = {{x - 180 * zoomX, y + 80 * zoomY}, {x - 240 * zoomX, y + 80 * zoomY}, {x - 260 * zoomX, y + 60 * zoomY}, {x - 260 * zoomX, y + 40 * zoomY}, {x - 240 * zoomX, y}, {x - 180 * zoomX, y}, {x - 140 * zoomX, y - 80 * zoomY}, {x + 140 * zoomX, y - 80 * zoomY}, {x + 180 * zoomX, y}, {x + 180 * zoomX, y + 80 * zoomY}, {x + 100 * zoomX, y + 80 * zoomY}, {x - 140 * zoomX, y + 80 * zoomY}};
    txSetFillColor (colormashina);
    txPolygon (mashina, 12);

    txSetFillColor (colorshina);
    txCircle (x - 140 * zoomX, y + 80 * zoomY, 40 * zoomX * diametrcoles);
    txCircle (x + 100 * zoomX, y + 80 * zoomY, 40 * zoomX * diametrcoles);

    txSetFillColor (colordiski);
    txCircle (x - 140 * zoomX, y + 80 * zoomY, 30 * zoomX * diametrcoles);
    txCircle (x + 100 * zoomX, y + 80 * zoomY, 30 * zoomX * diametrcoles);

    POINT oknalob[4] = {{x - 140 * zoomX, y}, {x, y}, {x, y - 60 * zoomY}, {x - 110 * zoomX, y - 60 * zoomY}};
    txSetFillColor (colorokno);
    txPolygon (oknalob, 4);

    POINT okno[4] =  {{x + 20 * zoomX, y}, {x + 20 * zoomX, y - 60 * zoomY}, {x + 120 * zoomX, y - 60 * zoomY}, {x + 150 * zoomX, y}};
    txPolygon (okno, 4);
    }

void chelovek (int x, int y, double zoomX, double zoomY, int handup, int legs, COLORREF colorgolova, COLORREF colorglaza)

    {
    txSetColor (colorgolova);
    txLine (x, y, x * zoomX, y + 100*zoomY);
    txLine (x * zoomY, y + 100 * zoomY, x - legs / 2 * zoomX, y + 160 * zoomY);
    txLine (x * zoomY, y + 100 * zoomY, x + legs / 2 * zoomX, y + 160 * zoomY);
    txLine (x, y, x - 40 * zoomX, y - handup * zoomY);
    txLine (x, y, x + 40 * zoomX, y - handup * zoomY);
    txSetFillColor (colorgolova);
    txCircle (x, y-20 * zoomY , 20 * zoomY);
    txSetColor (colorglaza);
    txSetFillColor (colorglaza);
    txCircle (x + 8 * zoomX, y - 25 * zoomY, 2 * zoomY);
    txCircle (x - 8 * zoomX, y - 25 * zoomY, 2 * zoomY);
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txLine (x + 10 * zoomX, y - 15 * zoomY, x + 5 * zoomX, y - 10 * zoomY);
    txLine (x + 5 * zoomX, y - 10 * zoomY, x - 5 * zoomX, y - 10 * zoomY);
    txLine (x - 5 * zoomX, y - 10 * zoomY, x - 10 * zoomX, y - 15 * zoomY);
    }

void Dom (int x, int y, double zoomX, double zoomY)

    {
    txSetFillColor(RGB(205, 255, 90));
    txFloodFill(1499, 2);
    txSetFillColor(TX_BLUE);

    POINT dom[4] = {{x - 420 * zoomX, y - 40 * zoomY}, {x - 420 * zoomX, y + 260 * zoomY}, {x, y + 260 * zoomY}, {x , y - 40 * zoomY}};
    txPolygon (dom, 4);

    POINT krusha[3] = {{x - 440 * zoomX, y - 40 * zoomY}, {x - 212 * zoomX, y - 220 * zoomY}, {x + 20 * zoomX, y - 40 * zoomY}};
    txPolygon (krusha, 3);

    POINT dver[4] = {{x - 140 * zoomX, y + 40 * zoomY}, {x - 20 * zoomX, y + 40 * zoomY}, {x - 20 * zoomX, y + 260 * zoomY}, {x - 140 * zoomX, y + 260 * zoomY}};
    txSetFillColor(RGB(128, 64, 0));
    txPolygon (dver, 4);
    txSetFillColor(TX_BLACK);
    txCircle (x - 128 * zoomX, y + 152 * zoomY, 12 * zoomX);

    txSetColor(TX_BLACK);
    txSetFillColor(RGB(255, 255, 90));
    POINT okno [4] = {{x - 360 * zoomX, y}, {x - 260 * zoomX, y}, {x - 260 * zoomX, y + 200 * zoomY}, {x - 360 * zoomX, y + 200 * zoomY}};
    txPolygon (okno, 4);
    txLine (x - 320 * zoomX, y, x - 320 * zoomX, y + 200 * zoomY);
    txLine (x - 360 * zoomX, y + 80 * zoomY, x - 260 * zoomX, y + 80 * zoomY);

    txSetFillColor(TX_BLUE);
    POINT Garag [4] = {{x, y}, {x + 340 * zoomX, y}, {x + 340 * zoomX, y + 260 * zoomY}, {x, y + 260 * zoomY}};
    txPolygon (Garag, 4);
    POINT GaragDver [4] = {{x + 20 * zoomX, y + 260 * zoomY}, {x + 20 * zoomX, y + 20 * zoomY}, {x + 320 * zoomX, y + 20 * zoomY}, {x + 320 * zoomX, y + 260 * zoomY}};
    txSetFillColor(RGB(202, 202, 202));
    txPolygon (GaragDver, 4);
    }

void Nazvanie (int t)

    {
    int (t = 0);
    while (t <= 160)
        {
        txSetFillColor (TX_BLACK);
        txFloodFill (1,1);
        Text ("Продюссер, режисер, художник и", 200, 425 - 6 * t, 70, 30, "Cambria", true, 15, TX_WHITE);
        Text ("композитор: Столповский Александр", 200, 500 - 6 * t, 70, 30, "Cambria", true, 15, TX_WHITE);
        Text ("Похищение", 600, 1450 - 6 * t, 70 , 30, "Cambria", true, 15, TX_WHITE);
        txTextCursor (false);
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Nachalo_Vstrecha ()

    {
    int t = 0;
    while (t <= 350)
        {
        Dom (460 - 4 * t, 260 - 0 * t, 1, 1);
        Derevo (1140 - 4 * t, 230 - 0 * t, 1.1, 1.1, RGB(100, 255, 33), 1);
        Derevo (1800 - 4 * t, 180 - 0 * t, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (2330 - 4 * t, 180 - 0 * t, 1, 1, RGB(100, 255, 33), 1);
        chelovek (400, 350, 1, 1, -t/7%2 * 40, t/7%2 * 90, TX_BLACK, TX_GREEN);
        Derevo (1250 - 4 * t, 500 - 0 * t, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (1700 - 4 * t, 500 - 0 * t, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (2730 - 4 * t, 600 - 0 * t, 0.8, 0.8, RGB(100, 255, 33), 1);
        txTextCursor (false);
        t += 1;
        txSleep (0);
        txClear ();
        }
    t = 0;
    while (t <= 200)
        {
        Derevo (930, 200, 1, 1, RGB(100, 255, 33), 1);
        Derevo (400, 180, 0.8, 0.8, RGB(100, 255, 33), 1);
        dog (1500 - 5 * t, 450, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        chelovek (400, 350, 1, 1, -40, 90, TX_BLACK, TX_GREEN);
        Derevo (300, 500, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (1330, 600, 0.8, 0.8, RGB(100, 255, 33), 1);
        Text ("Человек: Привет!", 500, 700 + t/2, 40, 15, "Arial", false, 0, TX_WHITE);
        Text ("Собака: Гав! Гав!", 500, 750 + t/2, 40, 15, "Arial", false, 0, TX_WHITE);
        t += 1;
        txSleep (5);
        txClear ();
        }
    }

void Nachalo_Vozvrashenie ()

    {
    int t = 0;
    while (t <= 215)
        {
        Derevo (930 + 4 * t, 200, 1, 1, RGB(100, 255, 33), 1);
        Derevo (-270 + 4 * t, 230 , 1.1, 1.1, RGB(100, 255, 33), 1);
        Derevo (400 + 4 * t, 180, 0.8, 0.8, RGB(100, 255, 33), 1);
        Dom (-870 + 4 * t, 260 - 0 * t, 1, 1);
        dog (475, 450, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        chelovek (400, 350, 1, 1, -t/4%2 * 40, t/4%2 * 90, TX_BLACK, TX_GREEN);
        Derevo (1330 + 4 * t, 600, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (-160 + 4 * t, 500 , 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (300 + 4 * t, 500, 0.8, 0.8, RGB(100, 255, 33), 1);
        t += 1;
        txSleep (0);
        txClear ();
        }
    t = 0;
    while (t <= 140)
        {
        Dom (0 + 4 * t, 260, 1, 1);
        Derevo (590 + 4 * t, 230, 1.1, 1.1, RGB(100, 255, 33), 1);
        Derevo (1260 + 4 * t, 180, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (2330, 180, 1, 1, RGB(100, 255, 33), 1);
        chelovek (400, 350 +2 * t, 1, 1, -t/5%2 * 40, t/4%2 * 90, TX_BLACK, TX_GREEN);
        dog (475, 450 + 2 * t, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        Derevo (700 + 4 * t, 500, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (1160 + 4 * t, 500, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (2730, 600, 0.8, 0.8, RGB(100, 255, 33), 1);
        //printf ("t = %d/n", t);
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Razvitie ()

    {
    int t = 0;
    while (t <= 70)
        {
        Dom (560, 260, 1 - 0.01428571425714257142571 * t, 1 - 0.01428571425714257142571 * t);
        Buh (160, 500, 0.01 + 0.05 * t, 0.01 + 0.05 * t, TX_ORANGE , TX_ORANGE );
        Buh (880, 500, 0.01 + 0.05 * t, 0.01 + 0.05 * t, TX_ORANGE , TX_ORANGE );
        Buh (160, 240, 0.01 + 0.05 * t, 0.01 + 0.05 * t, TX_ORANGE , TX_ORANGE );
        Buh (880, 240, 0.01 + 0.05 * t, 0.01 + 0.05 * t, TX_ORANGE , TX_ORANGE );
        Derevo (1160, 230, 1.1, 1.1, RGB(100, 255, 33), 1);
        Derevo (1820, 180, 0.8, 0.8, RGB(100, 255, 33), 1);
        chelovek (400, 630, 1, 1, -t/5%2 * 40, t/4%2 * 90, TX_BLACK, TX_GREEN);
        dog (475, 730, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        Derevo (1270 , 500, 0.8, 0.8, RGB(100, 255, 33), 1);
        chelovek (520, 290, 1, 1, 30, 80, RGB(255, 200, 0), TX_GREEN);
        Text ("Человек: Вор! Лови его!", 700, 750 + t/1.5, 40, 15, "Arial", false, 0, TX_WHITE);
        Text ("Вор: Ха-ха-ха-ха", 700, 700 + t/1.5, 40, 15, "Arial", false, 0, TX_WHITE);
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Kradga ()

    {
    int t = 0;
    while (t <= 225)
        {
        Derevo (-200 + 4 * t, 200, 0.8, 0.8, RGB(100, 255, 33), 1);
        chelovek (520 - 3.977777777777777777777777777778 * t, 290 + 0.04444444444444444444 * t, 1, 1, -t/5%2 * 30, t/4%2 * 80, RGB(255, 200, 0), TX_GREEN);
        chelovek (400, 630 - t, 1, 1, -t/5%2 * 40, t/4%2 * 90, TX_BLACK, TX_GREEN);
        Derevo (1160 + 4 * t, 230, 1.1, 1.1, RGB(100, 255, 33), 1);
        Pushka (2000 - 7 * t, 630, 1, 1, 1, TX_ORANGE, TX_BLUE, TX_GRAY, TX_BLACK);
        dog (475 + 2 * t, 730, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        Derevo (1270 + 4 * t, 500, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (-300 + 4 * t, 500, 1, 1, RGB(100, 255, 33), 1);
        Derevo (-660 + 4 * t, 180, 1, 1, RGB(100, 255, 33), 1);
        Text ("Собака: Тяв-тяв-тяв", 700, 700 + t, 40, 15, "Arial", false, 0, TX_WHITE);
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Pomosh ()

    {
    int t = 0;
    while (t <= 110)
        {
        Derevo (700 + 4 * t, 200, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (-425 + 4 * t, 180, 1, 1, RGB(100, 255, 33), 1);
        Derevo (240 + 4 * t, 180, 1, 1, RGB(100, 255, 33), 1);
        chelovek (400 + 0.5 * t, 405, 1, 1, -t/5%2 * 40, t/4%2 * 90, TX_BLACK, TX_GREEN);
        chelovek (-350 + 4 * t, 300, 1, 1, -30, 80, RGB(255, 200, 0), TX_GREEN);
        Pushka (425, 630, 1, 1, 1, TX_ORANGE, TX_BLUE, TX_GRAY, TX_BLACK);
        dog (925 + 2 * t, 730, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        Derevo (600 + 4 * t, 500, 1, 1, RGB(100, 255, 33), 1);
        t += 1;
        txSleep (0);
        txClear ();
        }
    t = 0;
    while (t <= 56)
        {
        Derevo (1140, 200, 0.8, 0.8, RGB(100, 255, 33), 1);
        chelovek (455 + 2 * t, 405 + 3 * t, 1, 1, -t/5%2 * 40, t/4%2 * 90, TX_BLACK, TX_GREEN);
        dog (1145, 730, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        Derevo (15, 180, 1, 1, RGB(100, 255, 33), 1);
        chelovek (90, 300, 1, 1, -30, 80, RGB(255, 200, 0), TX_GREEN);
        Pushka (425, 630, 1, 1, 1, TX_ORANGE, TX_BLUE, TX_GRAY, TX_BLACK);
        Derevo (1040, 500, 1, 1, RGB(100, 255, 33), 1);
        Derevo (680, 180, 1, 1, RGB(100, 255, 33), 1);
        Text ("Человек: Пли!", 500, 750 + t/1.5, 40, 15, "Arial", false, 0, TX_WHITE);
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Smert ()

    {
    int t = 0;
    while (t <= 55)
        {
        Derevo (1140, 200, 0.8, 0.8, RGB(100, 255, 33), 1);
        chelovek (567, 573, 1, 1, -40, 90, TX_BLACK, TX_GREEN);
        Derevo (1040, 500, 1, 1, RGB(100, 255, 33), 1);
        dog (1145 - 2 * t, 730, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        Derevo (15, 180, 1, 1, RGB(100, 255, 33), 1);
        chelovek (90, 300, 1, 1, -30, 80, RGB(255, 200, 0), TX_GREEN);
        txCircle (365 - 5 * t, 610 - 5.63 * t, 20);
        Pushka (425, 630, 1, 1, 1, TX_ORANGE, TX_BLUE, TX_GRAY, TX_BLACK);
        Derevo (680, 180, 1, 1, RGB(100, 255, 33), 1);
        Text ("Вор: Ааааааа!", 500, 700 + t/1.5, 40, 15, "Arial", false, 0, TX_WHITE);
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Vozvrat_doma ()

    {
    int t = 0;
    while (t <= 55)
        {
        Derevo (1140, 200, 0.8, 0.8, RGB(100, 255, 33), 1);
        chelovek (567, 573, 1, 1, -40, 90, TX_BLACK, TX_GREEN);
        Derevo (1040, 500, 1, 1, RGB(100, 255, 33), 1);
        dog (1035 - 4 * t, 730, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        Derevo (15, 180, 1, 1, RGB(100, 255, 33), 1);
        Pushka (425 - 6 * t, 630, 1, 1, 1, TX_ORANGE, TX_BLUE, TX_GRAY, TX_BLACK);
        Derevo (680, 180, 1, 1, RGB(100, 255, 33), 1);
        Dom (90, 300, 0.1 + 0.0163636363 * t, 0.1 + 0.0163636363 * t);
        Text ("Человек: Ура! Ура! Ура! Наш дом!", 500, 750 + t, 40, 15, "Arial", false, 0, TX_WHITE);
        Text ("Собака: Гав-гав-гав", 500, 700 + t, 40, 15, "Arial", false, 0, TX_WHITE);
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Pobeda ()

    {
    int t = 0;
    while (t <= 57)
        {
        Derevo (1140 + 3 * t , 200, 0.8, 0.8, RGB(100, 255, 33), 1);
        chelovek (567, 573 + t, 1, 1, -t/5%2 * 40, t/4%2 * 90, TX_BLACK, TX_GREEN);
        Derevo (1040 + 3 * t, 500, 1, 1, RGB(100, 255, 33), 1);
        dog (815 - 3 * t, 730, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        Derevo (15 + 3 * t, 180, 1, 1, RGB(100, 255, 33), 1);
        Pushka (95 - 6 * t, 630, 1, 1, 1, TX_ORANGE, TX_BLUE, TX_GRAY, TX_BLACK);
        Derevo (680 + 3 * t, 180, 1, 1, RGB(100, 255, 33), 1);
        Dom (90 + 3 * t, 300, 1, 1);
        t += 1;
        txSleep (0);
        txClear ();
        }
    t = 0;
    while (t <= 100)
        {
        Derevo (1311 + 4 * t , 200, 0.8, 0.8, RGB(100, 255, 33), 1);
        Derevo (186 + 4 * t, 180, 1, 1, RGB(100, 255, 33), 1);
        Derevo (851 + 4 * t, 180, 1, 1, RGB(100, 255, 33), 1);
        Dom (261 + 4 * t, 300, 1, 1);
        chelovek (567, 630, 1, 1, -t/5%2 * 40, t/4%2 * 90, TX_BLACK, TX_GREEN);
        Derevo (1211 + 4 * t, 500, 1, 1, RGB(100, 255, 33), 1);
        dog (644, 730, 1, 0.8, t/4%2 * 5, RGB(255, 135, 0), TX_BLACK, TX_BROWN, TX_BLUE, RGB(230, 115, 0));
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Konech ()

    {
    int t = 0;
    while (t <= 200)
        {
        txSetFillColor (TX_BLACK);
        txFloodFill (1,1);
        Text ("Конец фильма", 450, 425 - 2 * t, 70, 30, "Cambria", true, 15, TX_WHITE);
        t += 1;
        txSleep (0);
        txClear ();
        }
    }

void Text (const char * text, int x, int y, int visota, int shirina, const char * Srift, bool kursiv, int Ugol, COLORREF color)

    {
    txSetFillColor (color);
    txSetColor (color);
    txSelectFont (Srift, visota, shirina, 0, kursiv, false, false, Ugol);
    txTextOut (x, y, text);
    }


void Pushka (int x, int y, double zoomX, double zoomY, double diametrcol, COLORREF color_pli, COLORREF color_dulo, COLORREF color_platforma, COLORREF color_colesa)

    {
    POINT pli[4] = {{x + 33 * zoomX, y + 5 * zoomY}, {x + 10 * zoomX, y + 7.5 * zoomY}, {x + 7.5  * zoomX,y + 12.5 * zoomY}, {x + 26  * zoomX,y + 15 * zoomY}};
    txSetFillColor (color_pli);
    txPolygon (pli, 4);

    POINT dulo[4] = {{x - 100 * zoomX, y - 20 * zoomY}, {x - 60 * zoomX, y - 80 * zoomY}, {x + 60 * zoomX, y}, {x + 20 * zoomX, y + 60 * zoomY}};
    txSetFillColor (color_dulo);
    txPolygon (dulo, 4);

    POINT platforma[3] = {{x, y}, {x - 30 * zoomX, y + 80 * zoomY}, {x + 30 * zoomX, y + 80 * zoomY}};
    txSetFillColor (color_platforma);
    txPolygon (platforma, 3);

    txSetFillColor (color_colesa);
    txCircle (x + 30 * zoomX, y + 80 * zoomY, 10 * zoomX * diametrcol);
    txCircle (x - 30 * zoomX, y + 80 * zoomY, 10 * zoomX * diametrcol);
    }

void Buh (int x, int y, double zoomX, double zoomY, COLORREF color_snarudgi, COLORREF color_vnutri)

    {
    txSetColor (color_snarudgi);
    txSetFillColor(color_snarudgi);
    POINT star[10] = {{x - 30 * zoomX, y - 10 * zoomY}, {x - 10 * zoomX, y - 10 * zoomY}, {x, y - 30 * zoomY}, {x + 10 * zoomX, y - 10 * zoomY}, {x + 30 * zoomX, y - 10 * zoomY}, {x + 10 * zoomX, y}, {x + 20 * zoomX, y + 20 * zoomY}, {x, y + 10 * zoomY}, {x - 20 * zoomX, y + 20 * zoomY}, {x - 10 * zoomX, y}};
    txPolygon (star, 10);
    txSetFillColor(color_vnutri);
    POINT starr[10] = {{x - 15 * zoomX, y - 5 * zoomY}, {x - 5 * zoomX, y - 5 * zoomY}, {x, y - 15 * zoomY}, {x + 5 * zoomX, y - 5 * zoomY}, {x + 15 * zoomX, y - 5 * zoomY}, {x + 5 * zoomX, y}, {x + 10 * zoomX, y + 10 * zoomY}, {x, y + 5 * zoomY}, {x - 10 * zoomX, y + 10 * zoomY}, {x - 5 * zoomX, y}};
    txPolygon (starr, 10);
    }

void dog (int x, int y,  double zoomX, double zoomY, int hvost, COLORREF color_sobaka, COLORREF color_nos, COLORREF color_nosniz, COLORREF color_glaz, COLORREF color_ushi)

    {
    txSetFillColor(RGB(205, 255, 90));
    txFloodFill(1499, 0.5);
    txSetColor (TX_BLACK);

    POINT nogi[10] = {{x - 30 * zoomX, y + 90 * zoomY}, {x - 5 * zoomX, y + 90 * zoomY}, {x - 5 * zoomX, y + 70 * zoomY}, {x + 5 * zoomX, y + 70 * zoomY}, {x + 5 * zoomX, y + 90 * zoomY}, {x + 30 * zoomX, y + 90 * zoomY}, {x + 15 * zoomX, y + 10 * zoomY}, {x + 20 * zoomX, y + 10 * zoomY}, {x - 21 * zoomX, y + 10 * zoomY}, {x - 15 * zoomX, y + 10 * zoomY}};
    txSetFillColor (color_sobaka);
    txPolygon (nogi, 10);

    POINT uho_pr[3] = {{x + 60 * zoomX, y}, {x + 10 * zoomX, y - 50 * zoomY}, {x + 50 * zoomX, y - 30 * zoomY}};
    txSetFillColor (color_ushi);
    txPolygon (uho_pr , 3);

    POINT uho_lv[3] = {{x - 10 * zoomX, y - 50 * zoomY}, {x - 60 * zoomX, y}, {x - 50 * zoomX, y - 30 * zoomY}};
    txSetFillColor (color_ushi);
    txPolygon (uho_lv , 3);

    POINT golova[6] = {{x + 20 * zoomX, y + 10 * zoomY}, {x + 40 * zoomX, y - 20 * zoomY}, {x + 10 * zoomX, y - 50 * zoomY}, {x - 10 * zoomX, y - 50 * zoomY}, {x - 40 * zoomX, y - 20 * zoomY}, {x - 20 * zoomX, y + 10 * zoomY}};
    txSetFillColor (color_sobaka);
    txPolygon (golova, 6);

    POINT nosniz[4] = {{x - 20 * zoomX, y + 10 * zoomY}, {x - 10 * zoomX, y - 10 * zoomY}, {x + 10 * zoomX, y - 10 * zoomY}, {x + 20 * zoomX, y + 10 * zoomY}};
    txSetFillColor (color_nosniz);
    txPolygon (nosniz, 4);

    POINT nos[3] = {{x + 10 * zoomX, y - 10 * zoomY}, {x, y}, {x - 10 * zoomX, y - 10 * zoomY}};
    txSetFillColor (color_nos);
    txPolygon (nos, 3);

    POINT rot[3] = {{x - 10 * zoomX, y + 10 * zoomY}, {x, y + 20 * zoomY}, {x + 10 * zoomX, y + 10 * zoomY}};
    txSetFillColor (RGB(250, 50, 0));
    txPolygon (rot, 3);

    txSetFillColor (color_glaz);
    txCircle (x - 15 * zoomX, y - 25 * zoomY, 5 * zoomY);
    txCircle (x + 15 * zoomX, y - 25 * zoomY, 5 * zoomY);

    POINT tulovishe[8] = {{x + 15 * zoomX, y + 10 * zoomY}, {x + 30 * zoomX, y + 20 * zoomY}, {x + 90 * zoomX, y + 20 * zoomY}, {x + 100 * zoomX, y + 30 * zoomY}, {x + 100 * zoomX, y + 90 * zoomY}, {x + 80 * zoomX, y + 90 * zoomY}, {x + 70 * zoomX, y + 60 * zoomY}, {x + 23 * zoomX, y + 60 * zoomY}};
    txSetFillColor (color_sobaka);
    txPolygon (tulovishe, 8);

    txLine (x + 95 * zoomX, y + 25 * zoomY, x + 110 + hvost * zoomX, y + hvost * zoomY);

    POINT noga[4] = {{x + 70 * zoomX, y + 90 * zoomY}, {x + 60 * zoomX, y + 60 * zoomY}, {x + 70 * zoomX, y + 60 * zoomY}, {x + 80 * zoomX, y + 90 * zoomY}};
    txSetFillColor (color_ushi);
    txPolygon (noga, 4);

    }
