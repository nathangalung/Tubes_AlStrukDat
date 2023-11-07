#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "ADT/machine/wordmachine.h"


boolean word_cmp(Word word_1, Word word_2)
{
    boolean found = false;
    int check = 0;
    if (word_1.Length == word_2.Length)
    {
        found = true;
        while (check < word_1.Length && found)
        {
            if (word_1.TabWord[check] != word_2.TabWord[check])
            {
                found = false;
            }
            else
            {
                check++;
            }
        }
    }

    return (found);
}

int word_to_int(Word word)
{
    int val = 0;
    int i;
    for (i = 0; i < word.Length; i++)
    {
        val = val * 10 + (int)(word.TabWord[i] % 48);
    }

    return (val);
}

Word string_to_word(char *string)
{
    Word command;

    int i;

    while (string[i] != "\0")
    {
        command.TabWord[i] = string[i];
        i++;
    }
    command.Length = i;

    return command;
}

Word split_word(Word a)
{
    Word temp;
    int length = 0, i = 0;

    while (a.TabWord[i] != BLANK)
    {
        i++;
    }

    int j = i + 1;

    while (a.TabWord[j] != MARK)
    {
        a.TabWord[length] = a.TabWord[j];
        length++, j++;
    }
    a.Length = length;

    return (a);
}

void load_queue(Queue queue)
{
    int count, i;

    if (!EOP)
    {
        count = word_to_int(currentWord);
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            enqueue(&queue, currentWord);
        }
        ADVWORD();
    }
}

void load_history(Stack stack)
{
    int count, i;

    if (!EOP)
    {
        count = word_to_int(currentWord);
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            enqueue(&stack, currentWord);
        }
        ADVWORD();
    }
}

void load_set(Set set)
{
    
}

void load_map(Map map)
{
    
}
