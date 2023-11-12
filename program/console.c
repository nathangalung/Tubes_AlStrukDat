#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"

boolean cmp_word_1(Word word_1, Word word_2)
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

    while (string[i] != '\0')
    {
        command.TabWord[i] = string[i];
        i++;
    }
    command.Length = i;

    return command;
}

boolean cmp_word_2(Word word_1, Word word_2)
{
    Word temp;
    int sum = 0;
    for (int i = 0; i < word_1.Length; i++)
    {
        if (word_1.TabWord[i] == BLANK)
        {
            break;
        }
        temp.TabWord[i] = word_1.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (cmp_word_1(temp, word_2));
}

boolean cmp_word(Word word_1, Word word_2)
{
    boolean found = false;
    int check = 0;
    if (word_1.Length == word_2.Length)
    {
        found = true;

        while ((check < word_1.Length) && (found))
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

    return found;
}

Word split_word(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == BLANK)
        {
            idx = i;
            break;
        }
    }
    for (int i = (idx + 1); i < word.Length; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word read_line_name()
{
    AdvWordNewline();
    Word name_item = currentWord;

    return (name_item);
}

int read_word_count()
{
    AdvWordBlank();
    int count_item = word_to_int(currentWord);

    return (count_item);
}

int read_line_count()
{
    AdvWordNewline();
    int count_item = word_to_int(currentWord);

    return (count_item);
}

Word concat(Word word_1, Word word_2)
{
    Word word;
    int j = 0;
    for(int i=0; i<word_1.Length; i++)
    {
        word.TabWord[j] = word_1.TabWord[i];
        word.Length++;
        j++;
    }

    for(int i=0; i<word_2.Length; i++)
    {
        word.TabWord[j] = word_2.TabWord[i];
        word.Length++;
        j++;
    }

    return (word);
}