.PHONY: clean run asm

OBJS = main.o factorial.o
CFLAGS =-Os -g3 -Wall

run: factorial
	./factorial

factorial: $(OBJS)
	gcc $(CFLAGS) -o factorial $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f factorial $(OBJS)

asm:
	gcc -S -o factorial.s factorial.c
	gcc -S -o main.s main.c