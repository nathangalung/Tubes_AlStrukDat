#ifndef __LOGIN_H__
#define __LOGIN_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/dynamic_list.h"
#include "../ADT/queuestack/queue.h"
#include "../ADT/queuestack/stack.h"

void login(DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist);

#endif