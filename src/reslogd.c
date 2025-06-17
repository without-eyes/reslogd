#include "../include/reslogd.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

void run_daemon(void) {
    while (1) {
        char* cpuUsage = get_command_output("top -b -n1 | grep Cpu | tr -s ' ' | cut -d' ' -f2,4 | awk '{print $1 + $2}'");
        char* ramUsage = get_command_output("top -b -n1 | grep \"MiB Mem\" | tr -s ' ' | cut -d' ' -f8");
        char* processCount = get_command_output("top -b -n1 | grep Tasks | tr -s ' ' | cut -d' ' -f2");

        log_results(cpuUsage, ramUsage, processCount);

        free(cpuUsage);
        free(ramUsage);
        free(processCount);

        sleep(60);
    }
}

char* get_command_output(const char* command) {
    char* data = malloc(32);
    FILE *pipeHandle = popen(command, "r");
    if (fgets(data, sizeof(data), pipeHandle) == NULL) {
        data[0] = '\0';
    } else {
        const size_t length = strlen(data);
        if (length > 0 && data[length - 1] == '\n') {
            data[length - 1] = '\0';
        }
    }
    return data;
}

void log_results(const char* cpuUsage, const char* ramUsage, const char* processCount) {
    FILE* log = fopen("/var/log/reslogd.log", "a");
    if (log == NULL) {
        exit(EXIT_FAILURE);
    }
    fprintf(log, "[%s] CPU: %s%%\tRAM: %sMiB\tProcesses: %s\n", get_current_time(),cpuUsage, ramUsage, processCount);
    fflush(log);
}

char* get_current_time(void) {
    static char buffer[32];
    const time_t rawTime = time(NULL);
    const struct tm *timeInfo = localtime(&rawTime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    return buffer;
}