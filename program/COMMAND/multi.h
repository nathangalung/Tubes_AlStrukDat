#ifndef __LOGIN_H__
#define __LOGIN_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

int Login(DynamicList *user, User *multi, int idx_user);

void Logout(DynamicList *user, int idx_user);

void SignUp(DynamicList *user, User *multi);

#endif