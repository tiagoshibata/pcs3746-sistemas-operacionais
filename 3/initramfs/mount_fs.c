#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>

void __attribute__((noreturn)) panic(const char *msg)
{
	fprintf(stderr, "%s: %s (errno = %d)\n", msg, strerror(errno), errno);
	exit(-1);
}

void mount_fs(const char *source, const char *target, const char *type,
	unsigned long flags, const char *data)
{
	// If not created, make it read-only (mode = 555)
	if (mkdir(target, 0x16d) && errno != EEXIST)
		panic("mkdir");
	if (mount(source, target, type, flags, data))
		panic("mount");
}

void mount_all()
{
	printf("Mounting filesystems\n");
	mount_fs("none", "/proc", "proc", 0, "");
	mount_fs("none", "/sys", "sysfs", 0, "");
	mount_fs("none", "/dev", "devtmpfs", 0, "");
}

int main()
{
	mount_all();
	return 0;
}
