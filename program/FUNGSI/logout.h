#ifndef __LOGOUT_H__
#define __LOGOUT_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/dynamic_list.h"
#include "../ADT/queuestack/queue.h"
#include "../ADT/queuestack/stack.h"

void logout(char *user, Queue *queue, char *history, char *playlist);

#endif