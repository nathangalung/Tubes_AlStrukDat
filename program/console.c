#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"

boolean word_cmp(Word word_1, Word word_2)
{
    Word temp;
    boolean found = false;
    int check = 0;
    int count = 0;
    
    while ((count < word_1.Length) && (!found))
    {
        if (word_1.TabWord[count] == BLANK)
        {
            found = true;
            count--;

        }
        temp.TabWord[count] = word_1.TabWord[count];
        count++;
        temp.Length = count;
    }

    for (int o=0; o<temp.Length; o++)
    {
        printf("%c", temp.TabWord[o]);
    }
    printf("\n");

    if (temp.Length == word_2.Length)
    {
        found = true;
        while ((check < word_1.Length) && (found))
        {
            if (temp.TabWord[check] != word_2.TabWord[check])
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

    while (string[i] != '\0')
    {
        command.TabWord[i] = string[i];
        i++;
    }
    command.Length = i;

    return command;
}

Word split_word(Word word)
{
    Word new_word;
    int length = 0, i = 0;

    while (word.TabWord[i] != BLANK)
    {
        i++;
    }

    int j = i + 1;

    while (word.TabWord[j] != MARK)
    {
        new_word.TabWord[length] = word.TabWord[j];
        length++, j++;
    }
    new_word.Length = length;

    return (new_word);
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
        j++;
    }

    for(int i=0; i<word_2.Length; i++)
    {
        word.TabWord[j] = word_2.TabWord[i];
        j++;
    }

    return (word);
}

int check_command(Word word)
{
    Word start_cmp = {"START", 5};
    Word load_cmp = {"LOAD", 4};
    Word list_cmp = {"LIST", 4};
    Word play_cmp = {"PLAY", 4};
    Word queue_cmp = {"QUEUE", 5};
    Word song_cmp = {"SONG", 4};
    Word playlist_cmp = {"PLAYLIST", 8};
    Word status_cmp = {"STATUS", 6};
    Word save_cmp = {"SAVE", 4};
    Word quit_cmp = {"QUIT", 4};
    Word help_cmp = {"HELP", 4};
    Word default_cmp = {"DEFAULT", 7};
    Word swap_cmp = {"SWAP", 4};
    Word remove_cmp = {"REMOVE", 6};
    Word clear_cmp = {"CLEAR", 5};
    Word next_cmp = {"NEXT", 4};
    Word previous_cmp = {"PREVIOUS", 8};
    Word create_cmp = {"CREATE", 6};
    Word add_cmp = {"ADD", 3};
    Word delete_cmp = {"DELETE", 6};
    Word album_cmp = {"ALBUM", 5};

    if (word_cmp(word, start_cmp))
    {
        return 1;
    }
    else if (word_cmp(word, load_cmp))
    {
        return 2;
    }
    else
    {
        return 0;
    }

}