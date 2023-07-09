CC = gcc
CFLAGS = -g -Wall -Wextra
TARGET = main
LIBS = -lxcb  



all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LIBS)
clean:
	$(RM) $(TARGET)
