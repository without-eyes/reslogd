#include <stdlib.h>
#include "../include/reslogd.h"

int main(int argc, char* argv[]) {
    create_daemon();

    if (argc == 2) {
        save_pid_to_file(argv[1]);
    }

    return EXIT_SUCCESS;
}