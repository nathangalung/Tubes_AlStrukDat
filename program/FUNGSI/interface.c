#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "interface.h"

// ========================================================================================= DELAY LOAD ======================================================================================================== //

void DelayLoad(int seconds)
{
    int milli_seconds = 500 * seconds;

    clock_t start_time = clock();
 
    while (clock() < start_time + milli_seconds);
}

// ========================================================================================= IMAGE ======================================================================================================== //

void Image(FILE *ascii)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string), ascii) != NULL)
    printf("%s%s", YELLOW, read_string);
    printf("\n");
}

// ========================================================================================= WELCOME IMAGE ======================================================================================================== //

void WelcomeImage()
{
    char *filename;
    FILE *ascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            filename = "interface/welcome/welcome_1.txt";
        }
        else if (i == 1)
        {
            filename = "interface/welcome/welcome_2.txt";
        }
        else if (i == 2)
        {
            filename = "interface/welcome/welcome_3.txt";
        } 
        else
        {
            filename = "interface/welcome/welcome_4.txt";
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
            Image(ascii);
            fclose(ascii);
        }
        DelayLoad(1);
    }
}
// ========================================================================================= START IMAGE ======================================================================================================== //
void StartImage()
{
    char *filename;
    FILE *ascii;
    system("cls || clear");
    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
        {
            filename = "interface/start/start_1.txt";
        }
        else if (i == 1)
        {
            filename = "interface/start/start_2.txt";
        }
        else if (i == 2)
        {
            filename = "interface/start/start_3.txt";
        } 
        else if (i == 3)
        {
            filename = "interface/start/start_4.txt";
        }
        else if (i == 4)
        {
            filename = "interface/start/start_5.txt";
        }
        else
        {
            filename = "interface/start/start_6.txt";
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
            Image(ascii);
            fclose(ascii);
        }
        DelayLoad(1);
    }
}
// ========================================================================================= LOAD IMAGE ======================================================================================================== //
void LoadImage()
{
    char *filename;
    FILE *ascii;
    system("cls || clear");
    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
        {
            filename = "interface/load/load_1.txt";
        }
        else if (i == 1)
        {
            filename = "interface/load/load_2.txt";
        }
        else if (i == 2)
        {
            filename = "interface/load/load_3.txt";
        } 
        else if (i == 3)
        {
            filename = "interface/load/load_4.txt";
        }
        else if (i == 4)
        {
            filename = "interface/load/load_5.txt";
        }
        else
        {
            filename = "interface/load/load_6.txt";
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
            Image(ascii);
            fclose(ascii);
        }
        DelayLoad(1);
    }
}
// ========================================================================================= QUIT IMAGE ======================================================================================================== //
void QuitImage()
{
    char *filename;
    FILE *ascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            filename = "interface/quit/quit_1.txt";
        }
        else if (i == 1)
        {
            filename = "interface/quit/quit_2.txt";
        }
        else if (i == 2)
        {
            filename = "interface/quit/quit_3.txt";
        } 
        else
        {
            filename = "interface/quit/quit_4.txt";
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
            Image(ascii);
            fclose(ascii);
        }
        DelayLoad(1);
    }
}