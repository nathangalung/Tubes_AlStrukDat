#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "interface.h"

void DelayLoad(int seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 500 * seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void LoadImage(FILE *ascii)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string), ascii) != NULL)
    printf("%s%s", "\x1B[33m", read_string);
    printf("\n");
}

void Welcome()
{
    char *filename;
    FILE *ascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            filename = "interface/welcome_1.txt";
        }
        else if (i == 1)
        {
            filename = "interface/welcome_2.txt";
        }
        else if (i == 2)
        {
            filename = "interface/welcome_3.txt";
        } 
        else
        {
            filename = "interface/welcome_4.txt";
        } 
        ascii = NULL;
        ascii = fopen(filename,"r");
        if (ascii == NULL)
        {
            printf("error opening %s\n",filename);
        }
        else
        {
            system("cls || clear");
            LoadImage(ascii);
            fclose(ascii);
        }
        DelayLoad(1);
    }
}