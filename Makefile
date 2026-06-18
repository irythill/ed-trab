CC = gcc
CFLAGS = -Wall -std=c99
TARGET = main

$(TARGET): main.c sistema.c sistema.h
	$(CC) $(CFLAGS) -o $(TARGET) main.c sistema.c

clean:
	rm -f $(TARGET) sistema

