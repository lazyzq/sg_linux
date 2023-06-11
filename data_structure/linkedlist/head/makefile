all:main

main:main.o list.o
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $^ -c -o $@

clean:
	rm *.o main -rf