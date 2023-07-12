CC = gcc
CFLAGS = -g -Wall -Wextra
TARGET = freq_test
LIBS = -lxcb  



all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LIBS)
clean:
	$(RM) $(TARGET)
