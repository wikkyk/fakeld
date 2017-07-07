#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"

#define err(msg) \
	do{fputs(msg, stderr);fputc('\n', stderr);return -1;}while(0)

int
main(int argc, char **argv)
{
	char library_path[] = "--library-path", **newargv;
	int i, newargc = argc + 4;
	
	newargv = malloc(newargc * sizeof(char *));
	if (!newargv)
		err("malloc failed");

	newargv[0] = argv[0];
	newargv[1] = library_path;
	newargv[2] = libpaths;

	for (i = 0; i < argc; ++i)
		newargv[i + 3] = argv[i];

	argv[newargc - 1] = '\0';

	execv(realld, newargv);
	err(strerror(errno));
}
