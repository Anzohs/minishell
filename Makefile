NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = .

SRCC_DIR = ./src

SRCS = main.c

SRCSS = copy_env.c ft_strcpy.c ft_strlen.c ft_free_strs.c create_env.c ft_strcat.c ft_strrchr.c

OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)

OBJSS = $(SRCSS:%.c=$(SRCC_DIR)/%.o)

$(NAME): $(OBJSS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJSS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJSS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
