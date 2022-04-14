#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define _WIN32_WINNT 0x0500

int main()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_MINIMIZE );  //won't hide the window without SW_MINIMIZE
    ShowWindow( hWnd, SW_HIDE );


    return 0;
}
