#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "ADT/list/static_list.h"
#include "ADT/list/dynamic_list.h"
#include "ADT/setmap/set.h"
#include "ADT/setmap/map.h"
#include "ADT/queuestack/queue.h"
#include "ADT/queuestack/stack.h"
#include "ADT/machine/charmachine.h"
#include "ADT/machine/wordmachine.h"
#include "boolean.h"

boolean word_cmp(Word a, Word b);

int word_to_int(Word word);

Word string_to_word(char *s);

Word split_word(Word word);

Word read_line_name();

int read_word_count();

int read_line_count();

Word concat(Word word_1, Word word_2);

int check_command(Word word);

#endif