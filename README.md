# reslogd (Resource Logger Daemon)

`reslogd` is a lightweight Linux daemon that logs system resource usage (CPU, RAM, and process count) to a log file every minute.

## Features

- Runs as a daemon in the background
- Logs:
  - CPU usage (%)
  - RAM used (MiB)
  - Number of active processes
- Logs saved to `/var/log/reslogd.log`
- PID saved to a file (default: `/run/reslogd.pid`)
- Supports log rotation and init script

## Build and Install

```bash
sudo make
````

This will:

* Build the binary (`/usr/bin/reslogd`)
* Copy the logrotate config to `/etc/logrotate.d/reslogd`
* Copy the init script to `/etc/init.d/reslogd`

## Run

```bash
sudo /usr/bin/reslogd
```

Or use the init system:

```bash
sudo service reslogd start
```

## Log Format

```
[Tue Jun 17 15:34:14 2025] CPU: 17.5%	RAM: 7450.7MiB	Processes: 305
```

## Log Rotation

A sample config is installed to `/etc/logrotate.d/reslogd`. You can rotate logs manually:

```bash
sudo logrotate -f /etc/logrotate.d/reslogd
```

## Uninstall

```bash
sudo rm /usr/bin/reslogd
sudo rm /etc/init.d/reslogd
sudo rm /etc/logrotate.d/reslogd
sudo rm /var/log/reslogd.log
sudo rm /run/reslogd.pid
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

