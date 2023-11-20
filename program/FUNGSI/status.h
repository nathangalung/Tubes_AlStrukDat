#ifndef STATUS_H
#define STATUS_H

#include "../ADT/list/static_list.h"
#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/user/user.h"
#include "../ADT/machine/wordmachine.h"

void status(User multi, StaticList artist, Set album, StaticList playing, int idx_user);

#endif