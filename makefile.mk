CC=gcc
CFLAGS=-I.
DEPS = time_handler.h
OBJ = time_handler.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
