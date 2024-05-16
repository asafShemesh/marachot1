CC=gcc
CFLAGS=-Wall -O0 -fprofile-arcs -ftest-coverage
LDFLAGS=-fprofile-arcs -ftest-coverage

all: Main

Main: Main.o dijkstra.o
	$(CC) $(LDFLAGS) -o $@ $^

Main.o: Main.c dijkstra.h
	$(CC) $(CFLAGS) -c Main.c

dijkstra.o: dijkstra.c dijkstra.h
	$(CC) $(CFLAGS) -c dijkstra.c

.PHONY: clean all

clean:
	rm -f Main Main.o dijkstra.o *.gcda *.gcno *.gcov
