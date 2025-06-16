#include "../include/reslogd.h"

#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>

void create_daemon(void) {
    const int status = daemon(0, 0);
    if (status == -1) {
        exit(EXIT_FAILURE);
    }
}