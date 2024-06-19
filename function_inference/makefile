CC = gcc
CFLAGS = -I./onnxruntime-linux-x64-1.18.0/include
LDFLAGS = -L./onnxruntime-linux-x64-1.18.0/lib
LDLIBS = -lonnxruntime

BUILD_DIR = build
SRCS = main.c
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
EXEC = $(BUILD_DIR)/function_inference

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)