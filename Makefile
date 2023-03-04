# Main Variables
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
INCLUDE = -I ./include/
RM = rm -rf
OUTPUT_M = push_swap
OUTPUT_B = checker
SUB_DIRS = utils operations stackUtils
BONUS_SUB_DIRS = checker gnl

# Headers
HEADER_M = ./include/push_swap.h ./include/Stack.h
HEADER_B = ./include/get_next_line.h

# Main directories
OBJ_DIR = obj
SRC_DIR = src
BONUS_DIR = bonus

# Making Sub directories
SRCS_DIR = $(foreach dir, $(SUB_DIRS), $(addprefix $(SRC_DIR)/, $(dir)))
OBJS_DIR = $(foreach dir, $(SUB_DIRS), $(addprefix $(OBJ_DIR)/, $(dir)))
SRCS_DIR_B = $(foreach dir, $(BONUS_SUB_DIRS), $(addprefix $(BONUS_DIR)/, $(dir)))
OBJS_DIR_B = $(foreach dir, $(BONUS_SUB_DIRS), $(addprefix $(OBJ_DIR)/, $(dir)))

# c and o files
SRCS = $(foreach dir, $(SRCS_DIR), $(wildcard $(dir)/*.c))
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
# to compile main file in push_swap
MAIN_OBJ_PUSH_SWAP = $(OBJ_DIR)/$(NAME).o
# bonus part
SRCS_B = $(foreach dir, $(SRCS_DIR_B), $(wildcard $(dir)/*.c))
OBJS_B = $(subst $(BONUS_DIR), $(OBJ_DIR), $(SRCS_B:.c=.o))

# RUN PROGRAMS
RUN_M = ./$(OUTPUT_M)
RUN_B = ./$(OUTPUT_B) 

# Colors
RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m

all: $(NAME)

$(NAME): Makefile compilemsg compileutils $(MAIN_OBJ_PUSH_SWAP) $(HEADER_M)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJS) $(MAIN_OBJ_PUSH_SWAP) -o $(OUTPUT_M)
	@echo "$(GREEN)Done!$(RESET)"

bonus: Makefile compilemsg compileutils $(OBJS_B) $(HEADER_M) $(HEADER_B)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJS) $(OBJS_B) -o $(OUTPUT_B)
	@echo "$(GREEN)!DONE BONUS!$(RESET)"

both: all bonus

compileutils: $(OBJS)

compilemsg:
	@echo "$(YELLOW)Compiling files...$(RESET)"
	@echo "$(YELLOW)Please Wait...$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR) $(OBJS_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN)Compiling $^ $(RESET)"

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR) $(OBJS_DIR_B)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN)Compiling $^ $(RESET)"

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing out file...$(RESET)"
	@$(RM) $(RUN_M) $(RUN_B)
	@echo "$(GREEN)Done!$(RESET)"

test: $(NAME) bonus
	$(eval ARG = $(shell jot -r 5 0 2000000))
	$(RUN_M) $(ARG) | $(RUN_B) $(ARG)
	@echo -n "Instructions: "
	@$(RUN_M) $(ARG) | wc -l

re: fclean all

.PHONY: all bonus both clean fclean test re