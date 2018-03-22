CFLAGS = -Wall -g

all:
	gcc $(CFLAGS) hello.c -o hello
clean:
	rm -f hello
