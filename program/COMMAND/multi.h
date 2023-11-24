#ifndef __LOGIN_H__
#define __LOGIN_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

int Login(DynamicList *user, User *multi, int idx_user);
/* Melakukan login / masuk ke akun yang sudah terdaftar */

void Logout(DynamicList *user, int idx_user);
/* Melakukan logout / keluar dari akun yang sedang aktif */

void SignUp(DynamicList *user, User *multi);
/* Melakukan signup / mendaftarkan akun*/

#endif