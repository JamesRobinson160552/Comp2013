CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = a3-1


all: $(TARGET)	

TARGET: $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

TARGET.o: $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c

input:
	cp sourceInput.c input.c

clean:
	rm $(TARGET)
	rm *.o
	rm input.c


