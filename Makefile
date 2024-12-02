NAME = minishell

CC = cc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -g -I. -Isrc/libf -Ift_search
CCFLAGS = -lreadline
SRC_FT = hash.c hcreate.c hdestroy.c hsearch.c node_len.c
SRC_SRC = copy_env.c create_env.c ft_free_strs.c
SRC_LIBF = ft_bzero.c ft_calloc.c ft_strcat.c ft_strcpy.c ft_strncmp.c ft_strlen.c ft_strrchr.c ft_strcmp.c \
			ft_strdup.c ft_strncpy.c ft_strjoin.c ft_strchr.c get_next_line.c get_next_line_utils.c\
SRC_ENV = get_index.c update_oldpwd.c update_pwd.c get_pwd.c
SRC_PIP = pipex.c pipex_utils.c pipex_utils2.c pipex_val_cmd.c pipex_here_doc.c pipex_close.c pipex_clean.c

SRCS := main.c parsing.c parse_commands.c
SRCS += $(addprefix ft_search/, $(SRC_FT))
SRCS += $(addprefix src/, $(SRC_SRC))
SRCS += $(addprefix src/libft/, $(SRC_LIBF))
SRCS += $(addprefix env_variables/, $(SRC_ENV))

OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o,$(SRCS))

all:	$(NAME)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CCFLAGS)

clean:
	@rm -rf	$(OBJ_DIR)
	@echo "Objects files clean"

fclean: clean
	@rm -rf $(NAME)
	@echo "executable removed: $(NAME)"

re: fclean all
.PHONY: all clean fclean re
