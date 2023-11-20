#ifndef __USER_H__
#define __USER_H__

#include "../queuestack/queue.h"
#include "../queuestack/stack.h"
#include "../list/dynamic_list.h"

#define NilUser 0
#define MaxElUser 25
#define UndefinedUser NULL

typedef struct {
	Queue Queue;
	Stack History;
    DynamicList Playlist;
} Type;

typedef struct {
	Type Elements[MaxElUser];
    int Count;
} User;

void CreateEmptyUser(User *multi);

#endif