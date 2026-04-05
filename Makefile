CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = -lpthread -lm
TARGET = game
SRCS = main.c supporting.c level.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LIBS) 	

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)