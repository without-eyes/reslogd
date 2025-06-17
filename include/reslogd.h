#ifndef RESLOGD_H
#define RESLOGD_H

void create_daemon(void);

void save_pid_to_file(const char* pathToPidFile);

void run_daemon(void);

char* get_command_output(const char* command);

void log_results(const char* cpuUsage, const char* ramUsage, const char* processCount);

#endif //RESLOGD_H