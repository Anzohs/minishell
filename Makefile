NAME = minishell

CC = cc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -g -I. -Isrc/libf -Ift_search
CCFLAGS = -lreadline
SRC_FT = hash.c hcreate.c hdestroy.c hsearch.c
SRC_SRC = copy_env.c create_env.c ft_free_strs.c
SRC_LIBF = ft_bzero.c ft_calloc.c ft_strcat.c ft_strcpy.c ft_strlen.c ft_strrchr.c

SRCS := main.c parsing.c
SRCS += $(addprefix ft_search/, $(SRC_FT))
SRCS += $(addprefix src/, $(SRC_SRC))
SRCS += $(addprefix src/libft/, $(SRC_LIBF))

OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o,$(SRCS))

all:	$(NAME)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf	$(OBJ_DIR)
	@echo "Objects files clean"

fclean: clean
	@rm -rf $(NAME)
	@echo "executable removed: $(NAME)"

re: fclean all
.PHONY: all clean fclean re
