#include<windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#include "admin_Fdec.h"
#include "customer_Fdec.h"
#include "admin_Fdef.h"
#include "customer_Fdef.h"

int main()
{   
    int i=0,j;
    system("cls");
    char d[] = " Welcome to DIU Cineplex ";
    gotoxy(10,1);
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=0;j<strlen(d);j++)
    {
        Sleep(50); 
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }

    welcome();

    //admin();
    //customer();

    return 0;
}