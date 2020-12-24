#include <stdio.h>
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
int s;
const int RM = 16385; double KrdX[RM], KrdY[RM];
void Traf(double xA, double yA, double xB, double yB, int k)
{
    KrdX[k] = xA;   KrdY[k] = yA;
    KrdX[k + 1] = (2 * xA + xB) / 3; KrdY[k + 1] = (2 * yA + yB) / 3;
    KrdX[k + 2] = (xB + xA) / 2 + (yA - yB) / (2 * sqrt(3.0));
    KrdY[k + 2] = (yB + yA) / 2 + (xB - xA) / (2 * sqrt(3.0));
    KrdX[k + 3] = (xA + 2 * xB) / 3; KrdY[k + 3] = (yA + 2 * yB) / 3;
    KrdX[k + 4] = xB;   KrdY[k + 4] = yB;
}
void Fractal(int n)
{
    double Ax = -0.7, Ay = -0.4, Bx = 0.7, By = -0.4, Cx, Cy;
    Cx = (Bx + Ax) / 2 + (Ay - By) * sqrt(3.0) / 2;
    Cy = (By + Ay) / 2 + (Bx - Ax) * sqrt(3.0) / 2;
    Traf(Bx, By, Ax, Ay, 0);
    Traf(Ax, Ay, Cx, Cy, 4);
    Traf(Cx, Cy, Bx, By, 8);
    for (int j = 0; j < n; j++)
    {
        double KrdX1[RM], KrdY1[RM];   s = 3 * pow(4.0, j + 1);
        for (int i = 0; i <= s; i++)
        {
            KrdX1[i] = KrdX[i];  KrdY1[i] = KrdY[i];
        }
        for (int i = 0; i < s; i++)
        {
            Traf(KrdX1[i], KrdY1[i], KrdX1[i + 1], KrdY1[i + 1], 4 * i);
        }
    }
}
int main() {
    int n;
    cout << "n = ";
    cin >> n;
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "");
    Fractal(n);
    int del = 50 * n;
    line(KrdX[0] * del + del, KrdY[0] * del + del, KrdX[1] * del + del, KrdY[1] * del + del);
    for (int i = 2; i < 4 * s; i++)
    {
        lineto(KrdX[i] * del + del, KrdY[i] * del + del);
    }
    readkey();
    closegraph();
}
