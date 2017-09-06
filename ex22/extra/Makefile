HEADERS=dbg.h ex22.h
CFLAGS=-Wall -g

default: ex22_main

ex22_main: ex22.o $(HEADERS)
	cc -DNDEBUG -c ex22_main.c


ex22.o: ex22.c $(HEADERS)
	cc -DNDEBUG -c ex22.c 

