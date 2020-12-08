CC = gcc
FLAGS = -lpthread -o
DEBUG_FLAGS = -fsanitize=address -fno-omit-frame-pointer
INCS = inc
SRCS = src

CLIENT_DIR = client
SERVER_DIR = server

OBJS = obj

CLIENT_TARGET = client_test
SERVER_TARGET = server_test

all: client_release server_release

client_release: 
	@$(CC) $(CLIENT_DIR)/$(SRCS)/*.c $(CLIENT_DIR)/$(INCS)/*.h $(FLAGS) $(CLIENT_TARGET)
	@echo Client created

server_release:
	@$(CC) $(SERVER_DIR)/$(SRCS)/*.c $(SERVER_DIR)/$(INCS)/*.h $(FLAGS) $(SERVER_TARGET)
	@echo Server created

debug: client_debug server_debug

client_debug:
	@$(CC) $(CLIENT_DIR)/$(SRCS)/*.c $(CLIENT_DIR)/$(INCS)/*.h $(DEBUG_FLAGS) $(FLAGS) $(CLIENT_TARGET)_debug 
	@echo client_debug created

server_debug:
	@$(CC) $(SERVER_DIR)/$(SRCS)/*.c $(SERVER_DIR)/$(INCS)/*.h $(DEBUG_FLAGS) $(FLAGS) $(SERVER_TARGET)_debug
	@echo server_debug created
