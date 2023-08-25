CC=gcc
CROSS_COMPILE?=

TARGET=writer

all: $(TARGET)
$(TARGET): $(TARGET).c
	$(CROSS_COMPILE)$(CC) -o $(TARGET) $(TARGET).c	


clean:
	rm -f *.o $(TARGET)
