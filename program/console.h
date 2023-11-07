#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>

#include "ADT/charmachine.h"
#include "ADT/queue/queue.h"
#include "ADT/wordmachine.h"
#include "boolean.h"

boolean word_cmp(Word a, Word b);

int word_to_int(Word word);

Word string_to_word(char *s);

Word split_word(Word a);

#endif