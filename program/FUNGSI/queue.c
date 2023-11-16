/* file queue.c */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int queueClear(){
    IDX_HEAD(*queue) = IDX_UNDEF;
    IDX_TAIL(*queue) = IDX_UNDEF;
    return -1;
}