#ifndef __LOGIN_H__
#define __LOGIN_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/user/user.h"

int Login(DynamicList *user, User *multi, int idx_user);

void Logout(DynamicList *user, int idx_user);

void Register(DynamicList *user, User *multi);

#endif