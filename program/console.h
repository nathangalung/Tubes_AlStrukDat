#ifndef __CONSOLE_H__
#define __CONSOLE_H__


#include "FUNGSI/start.h"
#include "FUNGSI/load.h"
#include "boolean.h"

boolean cmp_word_1(Word word_1, Word word_2);

int word_to_int(Word word);

Word string_to_word(char *s);

Word split_word(Word word);

boolean cmp_word_2(Word word_1, Word word_2);

boolean cmp_word(Word word_1, Word word_2);

Word read_line_name();

int read_word_count();

int read_line_count();

Word concat(Word word_1, Word word_2);

#endif