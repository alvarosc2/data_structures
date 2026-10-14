CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -g
BUILD_DIR ?= build

APP := $(BUILD_DIR)/main
TEST := $(BUILD_DIR)/test_linked_list

.PHONY: all test clean

all: $(APP)

$(BUILD_DIR):
	mkdir -p $@

$(APP): main.c linkedList.c linkedList.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) main.c linkedList.c -o $@

$(TEST): tests/test_linked_list.c linkedList.c linkedList.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I. tests/test_linked_list.c linkedList.c -o $@

test: $(TEST)
	./$(TEST)

clean:
	rm -rf $(BUILD_DIR)
