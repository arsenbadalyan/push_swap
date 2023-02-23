CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = $(shell find ./src -name "*.c")
INCLUDE = -I ./include/
RM = rm -rf
OUT_FILE = push_swap

# Colors
RESET  = \033[0
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m


#TODO: remove flag rule and add flags in 
all:
	@echo "$(YELLOW)Compiling all files...$(RESET)"
	@echo "$(YELLOW)Please Wait...$(RESET)"
	@$(CC) $(INCLUDE) $(SRCS) -o $(OUT_FILE)
	@echo "$(GREEN)Done!$(RESET)"
flag:
	@echo "$(GREEN)Compiling all files...$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) $(SRCS) -o $(OUT_FILE)
clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@$(RM) *.o
	@echo "$(GREEN)Done!$(RESET)"
fclean: clean
	@echo "$(RED)Removing out file...$(RESET)"
	@$(RM) $(OUT_FILE)
	@echo "$(GREEN)Done!$(RESET)"

#Test case TODO: delete
run1:
	./$(OUT_FILE) 1
run2:
	./$(OUT_FILE) "5 -002"
run3:
	./$(OUT_FILE) 6 4 "-00"
