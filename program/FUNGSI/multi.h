#ifndef __LOGIN_H__
#define __LOGIN_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/user/user.h"

int Login(DynamicList *user, User *multi, int idx_user);

int Logout(User *multi, int idx_user);

void SignUp(DynamicList *user);

#endif