CC = gcc
CFLAGS = -g -Wall -Wextra
TARGET = main
LIBS = -lxcb  
DIR = build
SRC = src

all: $(TARGET)



$(TARGET): $(TARGET).c
	mkdir $(DIR)
	$(CC) $(CFLAGS) -o  ../$(DIR)/$(TARGET) ./$(SRC)/$(TARGET).c $(LIBS)
clean:
	rm -rf $(DIR)
