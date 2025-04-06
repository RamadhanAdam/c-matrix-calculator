CC = gcc
CFLAGS = -Wall -std=c99

# Output file
TARGET = matrix_calculator

# Source files
SRCS = matrix_operations.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Compile C files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<
