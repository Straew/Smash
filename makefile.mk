CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lreadline

SRCS = main.c commands.c executor.c
OBJS = $(SRCS:.c=.o)
TARGET = shell

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
