#define _GNU_SOURCE
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
	char buf[1024];
	int mfd, n, cs;

	mfd = memfd_create("", MFD_CLOEXEC);
	if(mfd < 0)
		exit(1);

	while((n = read(0, buf, sizeof buf)) > 0)
		if(write(mfd, buf, n) != n)
			exit(2);

	switch(fork()){
	case -1:
		exit(3);
	case 0:
		snprintf(buf, sizeof buf, "/proc/self/fd/%d", mfd);
		execl(buf, "", NULL);
		exit(66);
	default:
		wait(&cs);
	}
	exit(cs);
}
