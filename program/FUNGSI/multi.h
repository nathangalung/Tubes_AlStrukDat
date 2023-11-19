#ifndef __LOGIN_H__
#define __LOGIN_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/dynamic_list.h"
#include "../ADT/queuestack/queue.h"
#include "../ADT/queuestack/stack.h"
#include "../ADT/linkedlist/linier_list.h"

void Login(DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist, LinierList *palylist_song);

void Logout(DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist, LinierList *palylist_song);

void SignUp(DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist, LinierList *palylist_song);

#endif