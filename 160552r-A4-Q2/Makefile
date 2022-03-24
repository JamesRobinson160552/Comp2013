CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = myMath

all: $(TARGET)

TARGET: $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

TARGET.o: $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c

debug: CFLAGS += -DDEBUG
debug: all


clean:
	rm $(TARGET) *.o


