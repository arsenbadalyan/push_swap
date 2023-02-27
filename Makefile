CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = $(shell find ./src -name "*.c")
SRCS_BONUS = $(shell find ./bonus -name "*.c")
INCLUDE = -I ./include/
RM = rm -rf
OUT_FILE = push_swap
OUT_FILE_BONUS = checker

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
bonus: Makefile
	@echo "$(YELLOW)Compiling all files...$(RESET)"
	@echo "$(YELLOW)Please Wait...$(RESET)"
	@$(CC) $(INCLUDE) $(SRCS_BONUS) -o $(OUT_FILE_BONUS)
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

test: $(NAME)
	$(eval ARG = $(shell jot -r 14 0 2000000))
	./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
#                ./push_swap $(ARG)

test_my: $(NAME) $(BONUS_NAME)
	$(eval ARG = $(shell jot -r 100 0 2000000))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
#                ./push_swap $(ARG)

#Test case TODO: delete
run1:
	./$(OUT_FILE) 1
run2:
	./$(OUT_FILE) "5 -002"
run3:
	./$(OUT_FILE) 6 4 "-00"
