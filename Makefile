NAME = push_swap
CC = cc
RM = rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR = _obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIRS := Includes $(LIBFT_DIR)
SRC_DIRS := src src/parser src/list src/algo
HEADERS = -I $(LIBFT_DIR)/include -I

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

PARSING_FILES := parser.c frees.c utils.c fill_stack.c
PARSING := $(addprefix parser/, $(PARSING_FILES))

LIST_FILES := list.c push.c rev_rotate.c rotate.c swap.c init_stacks.c
LIST := $(addprefix list/, $(LIST_FILES))

ALGO_FILES := algo.c
ALGO := $(addprefix algo/, $(ALGO_FILES))

SRC_FILES := main.c
SRC := $(addprefix src/, $(SRC_FILES) $(PARSING) $(LIST) $(ALGO))

################################################################################
###############               OBJECT FILES & RULES                ##############
################################################################################

OBJS := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags and linking options
CFLAGS := -Wall -Wextra -Werror -g -IIncludes -Ilibft -MMD -MP $(addprefix -I, $(INC_DIRS))
LDFLAGS := -Llibft -lft
CFLAGS_SAN := $(CFLAGS) -fsanitize=address -g
LDFLAGS_SAN := $(LDFLAGS) -fsanitize=address

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "\033[0;32mLinking $(NAME)...\033[0m"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) $(LDFLAGS)
	@echo "\033[0;32mSuccessful Compilation of $(NAME)\033[0m"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "\033[0;32mCompiling $<...\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "\033[0;32mCompiling libft..\033[0m"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@echo "\033[0;32mCleaning object files...\033[0m"
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[0;32mRemoving $(NAME)...\033[0m"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[0;32mRemoved files succesfully \033[0m"

re: fclean all

.PHONY: all clean fclean re