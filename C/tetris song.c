#include <windows.h>

int main()
{
        const int C    = 261;
        const int Cis  = 277;
        const int D    = 293;
        const int Dis  = 311;
        const int E    = 329;
        const int F    = 349;
        const int Fis  = 369;
        const int G    = 391;
        const int Gis  = 415;
        const int A    = 440;
        const int Ais  = 466;
        const int H    = 493;
        const int Takt = 1700;

        Beep(E * 2, Takt / 4);
        Beep(H , Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(C * 2, Takt / 8);
        Beep(H, Takt / 8);
        Beep(A, Takt / 4);
        Beep(A, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(D * 2, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(H, Takt / 2.5);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(E * 2, Takt / 4);
        Beep(C * 2, Takt / 4);
        Beep(A, Takt / 4);
        Beep(A, Takt / 4);
        Sleep(Takt / (8 / 3));
        Beep(D * 2, Takt / 3.25);
        Beep(F * 2, Takt / 8);
        Beep(A * 2, Takt / 8);
        Beep(A * 2, Takt / 8);
        Beep(G * 2, Takt / 8);
        Beep(F * 2, Takt / 8);
        Beep(E * 2, Takt / 3);
        Beep(C * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(D * 2, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(H, Takt / 4);
        Beep(H, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(E * 2, Takt / 4);
        Beep(C * 2, Takt / 4);
        Beep(A, Takt / 4);
        Beep(A, Takt / 4);

        return 0;
}
