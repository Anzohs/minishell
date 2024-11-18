NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./src/libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = .

SRC_UTILS_DIR = ./src

SRCS = main.c

SRCS_UTILS = copy_env.c ft_free_strs.c create_env.c

OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)

OBJS_UTILS = $(SRCS_UTILS:%.c=$(SRC_UTILS_DIR)/%.o)

$(NAME): $(LIBFT) $(OBJS_UTILS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS_UTILS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_UTILS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
