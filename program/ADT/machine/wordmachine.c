#include <stdio.h>

#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreMarks()
{
    while (currentChar == MARK)
    {
        AdvMark();
    }
}

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        AdvBlank();
    }
}

void IgnoreNewlines()
{
    while (currentChar == NEWLINE)
    {
        AdvNewline();
    }
}

void StartWordMark()
{
    StartMark();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPMark())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordMark();
    }
}

void StartWordBlank()
{
    StartBlank();
    IgnoreMarks();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPBlank())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordNewline();
    }
}

boolean StartWordNewline(Word filename)
{
    boolean found = StartNewline(filename);
    
    if (found)
    {
        IgnoreMarks();
        IgnoreBlanks();
        IgnoreNewlines();
        if (IsEOPNewline())
        {
            EndWord = true;
        }
        else
        {
            CopyWordNewline();
            IgnoreNewlines();
        }
        return found;
    }
    else
    {
        return false;
    }
}

void AdvWordMark()
{
    IgnoreMarks();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPMark())
    {
        EndWord = true;
    }
    else
    {
        CopyWordMark();
        IgnoreMarks();
    }
}

void AdvWordBlank()
{
    IgnoreMarks();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPBlank())
    {
        EndWord = true;
    }
    else
    {
        CopyWordBlank();
        IgnoreBlanks();
    }
}

void AdvWordNewline()
{
    IgnoreMarks();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPNewline())
    {
        EndWord = true;
    }
    else
    {
        CopyWordNewline();
        IgnoreNewlines();
    }
}

void CopyWordMark()
{
    int i = 0;

    while (!IsEOPMark())
    {
        if (currentChar != NEWLINE)
        {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        AdvMark();
    }
    currentWord.Length = i;
}

void CopyWordBlank()
{
    int i = 0;

    while (!IsEOPBlank())
    {
        currentWord.TabWord[i] = currentChar;
        AdvBlank();
        i++;
    }
    currentWord.Length = i;
}

void CopyWordNewline()
{
    int i = 0;

    while (!IsEOPNewline())
    {
        currentWord.TabWord[i] = currentChar;
        AdvNewline();
        i++;
    }
    currentWord.Length = i;
}

void DisplayWord(Word word)
{
    for (int i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
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

boolean CompareStringWord(Word word_1, char *string)
{
    Word word_2 = StringToWord(string);
    
    return (CompareWord(word_1, word_2));
}

int WordToInt(Word word)
{
    int val = 0;
    int i;
    for (i = 0; i < word.Length; i++)
    {
        val = val * 10 + (int)(word.TabWord[i] - 48);
    }

    return (val);
}

Word StringToWord(char *string)
{
    Word command;

    int i = 0;

    while (string[i] != '\0')
    {
        command.TabWord[i] = string[i];
        i++;
    }
    command.Length = i;

    return command;
}

void WordToString(Word word, char *string)
{
    string[word.Length] = '\0';

    for (int i = 0; i < word.Length; i++)
    {
        string[i] = word.TabWord[i];
    }
}

Word SplitWordMark(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == MARK)
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

Word SplitWordBlank(Word word)
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

Word SplitWordLeftMark(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == MARK)
        {
            idx = i;
            break;
        }
    }

    for (int i = 0; i < idx; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word SplitWordLeftBlank(Word word)
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

    for (int i = 0; i < idx; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word ConcatWord(Word word_1, Word word_2)
{
    Word word;
    int count = 0;
    for(int i=0; i<word_1.Length; i++)
    {
        word.TabWord[count] = word_1.TabWord[i];
        count++;
    }

    for(int i=0; i<word_2.Length; i++)
    {
        word.TabWord[count] = word_2.TabWord[i];
        count++;
    }
    word.Length = word_1.Length + word_2.Length;

    return (word);
}

Word ReadNameLine()
{
    AdvWordNewline();
    Word name_item = currentWord;

    return (name_item);
}

int ReadCountWord()
{
    AdvWordBlank();
    int count_item = WordToInt(currentWord);

    return (count_item);
}

int ReadCountLine()
{
    AdvWordNewline();
    int count_item = WordToInt(currentWord);

    return (count_item);
}