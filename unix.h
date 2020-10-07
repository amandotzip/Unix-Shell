#if !defined(UNIX_H)
#define UNIX_H

#include "unix-datastructure.h"

void mkfs(Unix *filesystem);
int touch(Unix *filesystem, const char arg[]);
int mkdir(Unix *filesystem, const char arg[]);
int cd(Unix *filesystem, const char arg[]);
int ls(Unix *filesystem, const char arg[]);
void pwd(Unix *filesystem);
void rmfs(Unix *filesystem);
int rm(Unix *filesystem, const char arg[]);

#endif
