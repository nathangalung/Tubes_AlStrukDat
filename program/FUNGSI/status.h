#ifndef STATUS_H
#define STATUS_H

#include "../ADT/list/static_list.h"
#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/user/user.h"
#include "../ADT/machine/wordmachine.h"

void Status(User multi, StaticList  artist, Set album, DynamicList playing, int idx_user);

#endif