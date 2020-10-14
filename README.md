# Unix Shell
Implements a Unix shell filesystem in C

# Demo 
Watch the video below
[![Watch the video](https://imgur.com/xuJWqSJ.jpg)](https://youtu.be/uhuevBkelrc)

# How to run
## Windows
Run "unix.exe"
## Mac or Linux
Using gcc or your preferred C compiler, compile the following 3 files and run the output.
```
gcc unix.c unix.h unix-datastructure.h  
```

# Commands
## mkfs
Called by the system on launch, creates file system.
## rmfs
Deletes all files and directories in the filesystem and frees their memory.
## touch [arg]
Creates file of argument name.
## rm [arg]
Removes file or directory with argument name.
## mkdir [arg]
Creates directory of argument name.
## cd [arg]
Changes current directory to argument.
## ls
Lists all files and directories in the current directory.
## pwd
Prints current working directory.
