CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = myMath

all: $(TARGET)

TARGET1: $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

TARGET1.o: $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c

clean:
	rm $(TARGET) *.o


