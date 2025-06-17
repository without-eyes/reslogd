#include "../include/reslogd.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_daemon(void) {
    const int status = daemon(0, 0);
    if (status == -1) {
        exit(EXIT_FAILURE);
    }
}

void save_pid_to_file(const char* pathToPidFile) {
    FILE* fd = fopen(pathToPidFile, "w");
    if (fd == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fd, "%d\n", getpid());
    fclose(fd);
}