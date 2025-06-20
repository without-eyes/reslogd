#ifndef RESLOGD_H
#define RESLOGD_H

void create_daemon(void);

void save_pid_to_file(void);

void run_daemon(void);

char* get_command_output(const char* command);

void log_results(const char* cpuUsage, const char* ramUsage, const char* processCount);

char* get_current_time(void);

#endif //RESLOGD_H