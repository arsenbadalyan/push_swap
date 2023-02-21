CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
OUT_FILE = push_swap
all:
	$(CC) *.c -o $(OUT_FILE)
flag:
	$(CC) $(FLAGS) *.c -o $(OUT_FILE)
run:
	./$(OUT_FILE)
clean:
	@echo "Removing object files..."
	@$(RM) *.o
fclean: clean
	@echo "Removing out file..."
	@$(RM) $(OUT_FILE)