# AutoCGroup
This application simply watch a new child process then assign it to the assigned cpu cgroups.

It will not going to be a full featured app. But means to help some users to reduce the power consumption of their laptops.

Mainly because, Linux isn't targeting a desktop users at the first place - High performance computing / server aren't suitable for battery powered devices.






**Note:** Due to my limited free time I will put this project on hold in flavour of this [Linux-CPU-Hotplugger](https://github.com/fieldfirst/Linux-CPU-Hotplugger) instead.

Mainly because for the desktop/laptop user applying the CGroup only has a little effect on power consumption, But it's still useful for some administration tasks such as memory constraints for selected processes.

The concept is very simple, hence the implementation is quite complex - just using a ptrace() syscall to grab a new pid. Then compare it against the database before put it into a designated CGroup.

**P.S.** I will come back to finish it in the future (in my free time).






For a Linux user out there I recommend this options:

1. Reduce **a timer clock frequency to 300Hz** - By compiling your own custom kernel

    *Note: You can just grab a stock config from /proc/config.gz (by using zcat)*

2. Adjust your p_state values (for Sandy bridge or newer with kernel version >= 3.18) otherwise adjust your CPU's governor instead.

3. Using this simple application.

    *Note: You must enable a __cgroup subsystem__ - By compiling your own custom kernel*



**Supported environment**

1. Systemd init
2. Gnome desktop
3. _cgroup subsystem_ was enabled

For another desktop environment you just edit a source code to conform your desktop or it's a matter of preferences. :)
