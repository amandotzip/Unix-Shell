#Aliased flags and compiler
CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror -Wshadow\
-g

#all 10 public tests x files
all: public01.x public02.x public03.x public04.x public05.x\
public06.x public07.x public08.x public09.x public10.x\
#Any x file must be updated if unix.o or its respective.o is edited
public01.x: public01.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public01.o unix.o driver.o memory-checking.o -o public01.x
public02.x: public02.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public02.o unix.o driver.o memory-checking.o -o public02.x
public03.x: public03.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public03.o unix.o driver.o memory-checking.o -o public03.x
public04.x: public04.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public04.o unix.o driver.o memory-checking.o -o public04.x
public05.x: public05.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public05.o unix.o driver.o memory-checking.o -o public05.x
public06.x: public06.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public06.o unix.o driver.o memory-checking.o -o public06.x
public07.x: public07.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public07.o unix.o driver.o memory-checking.o -o public07.x
public08.x: public08.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public08.o unix.o driver.o memory-checking.o -o public08.x
public09.x: public09.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public09.o unix.o driver.o memory-checking.o -o public09.x
public10.x: public10.o unix.o driver.o memory-checking.o
	$(CC) $(CFLAGS) public10.o unix.o driver.o memory-checking.o -o public10.x

#only changes if unix.c or unix.h edited
unix.o: unix.c unix.h unix-datastructure.h
	$(CC) $(CFLAGS) -c unix.c
#All public test object, update if public test source or list header
#updated
public01.o: public01.c unix.o driver.o memory-checking.h
	$(CC) $(CFLAGS) -c public01.c

public02.o: public02.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public02.c

public03.o: public03.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public03.c

public04.o: public04.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public04.c

public05.o: public05.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public05.c

public06.o: public06.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public06.c

public07.o: public07.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public07.c

public08.o: public08.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public08.c

public09.o: public09.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public09.c

public10.o: public10.c unix.h driver.h memory-checking.h
	$(CC) $(CFLAGS) -c public10.c


#tidbit for driver to compile
driver.o:

memory-checking.o:

#remove all generated .x and .o files
clean:
	rm -f *.x public*.o