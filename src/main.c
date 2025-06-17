#include <stdlib.h>
#include "../include/reslogd.h"

int main(void) {
    create_daemon();
    save_pid_to_file();
    run_daemon();
    return EXIT_SUCCESS;
}