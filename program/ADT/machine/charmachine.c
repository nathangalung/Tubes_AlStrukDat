#include <stdio.h>

#include "charmachine.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void StartMark()
{
    pita = stdin;
    AdvMark();
}

void StartBlank()
{
    pita = stdin;
    AdvBlank();
}

void StartNewline(Word filename)
{
    pita = fopen(filename.TabWord, "r");
    Word temp = {"FILE_CONFIG/default.txt", 23};
    if (pita == NULL)
    {
        EOP = true;
        fclose(pita);
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
    else
    {
        if (CompareWord(filename, temp))
        {
            printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
        else
        {
            printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
        AdvNewline();
    }
}
 
void AdvMark()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP)
        {
            fclose(pita);
        }
    }
}

void AdvBlank()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP)
        {
            fclose(pita);
        }
    }
}

void AdvNewline()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP)
        {
            fclose(pita);
        }
    }
}


boolean IsEOPMark()
{
    if (EOP)
    {
        return (EOP);
    }
    else
    {
        return (currentChar == MARK);
    }
}

boolean IsEOPBlank()
{
    if (EOP)
    {
        return (EOP);
    }
    else
    {
        return (currentChar == BLANK);
    }
}

boolean IsEOPNewline()
{
    if (EOP)
    {
        return (EOP);
    }
    else
    {
        return (currentChar == NEWLINE);
    }
}

boolean CompareWord(Word word_1, Word word_2)
{
    if (word_1.Length != word_2.Length)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < word_2.Length; i++)
        {
            if (word_1.TabWord[i] != word_2.TabWord[i])
            {
                return false;
            }
        }
    }

    return true;
}