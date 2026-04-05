CC = gcc
CFLAGS = -Wall -g

TARGET = db

all: $(TARGET)

$(TARGET): main.o lib.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o lib.o

main.o: main.c lib.h
	$(CC) $(CFLAGS) -c main.c

lib.o: lib.c lib.h
	$(CC) $(CFLAGS) -c lib.c

clean:
	rm -f *.o $(TARGET)