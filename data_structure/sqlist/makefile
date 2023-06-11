CFLAGS+=-c -Wall -g
all:main
main:main.o sqlist.o
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@
clean:
	rm *.o main -rf
