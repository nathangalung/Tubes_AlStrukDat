#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>

#include "program/ADT/charmachine.h"
#include "program/ADT/wordmachine.h"

boolean cmp_word(Word a, Word b);

Word split_word(Word a);

#endif