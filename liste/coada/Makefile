CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

build: main.c
	$(CC) $(CFLAGS) main.c -o main

run: main
	./main

valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./main

check:
	../../pclp-cs-21.11.2025/cs.sh ./

clean:
	rm -f main

