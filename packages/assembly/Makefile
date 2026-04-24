CC = gcc
CFLAGS = -no-pie

SRCS = $(wildcard *.s)
OBJS = $(SRCS:.s=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
