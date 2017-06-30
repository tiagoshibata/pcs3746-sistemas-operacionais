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

void mount_fs()
{
	printf("Mounting filesystems\n");
	// If /sys is not created, make it read-only (mode = 444)
	if (mkdir("/sys", 0x124) && errno != EEXIST)
		panic("mkdir");
	if (mount("none", "/sys", "sysfs", 0, ""))
		panic("mount");
	// If /dev is not created, make it read-only (mode = 444)
	if (mkdir("/dev", 0x124) && errno != EEXIST)
		panic("mkdir");
	if (mount("none", "/dev", "devtmpfs", 0, ""))
		panic("mount");
}

int main()
{
	mount_fs();
	return 0;
}
