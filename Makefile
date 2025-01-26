# Makefile for Linux and Windows

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lcurl -lcjson

TARGET_LINUX = gsh
TARGET_WINDOWS = gsh.exe

SRCS = gsh.c ask_service.c json_parser.c

all: linux

linux: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET_LINUX) $(SRCS) $(LDFLAGS)

windows: $(SRCS)
	x86_64-w64-mingw32-gcc $(CFLAGS) -o $(TARGET_WINDOWS) $(SRCS) -lcurl -lcjson

clean:
	rm -f $(TARGET_LINUX) $(TARGET_WINDOWS)

.PHONY: all linux windows clean