NAME = minishell

CC = cc
OBJ_DIR = obj
CFLAGS =  -g -I. -Isrc/libf -Ift_search -Ienv_variables -Ipipes
CCFLAGS = -lreadline
SRC_FT = hash.c hcreate.c hdestroy.c hsearch.c node_len.c
SRC_BLT = cd_biltin.c is_biltin.c
SRC_SRC = copy_env.c create_env.c ft_free_strs.c
SRC_LIBF = ft_bzero.c ft_calloc.c ft_strcat.c ft_strcpy.c ft_strncmp.c ft_strlen.c ft_strrchr.c ft_strcmp.c \
			ft_strdup.c ft_strncpy.c ft_strjoin.c ft_strchr.c get_next_line.c get_next_line_utils.c ft_split.c ft_substr.c\
			ft_isupper.c ft_islower.c ft_isalpha.c ft_joinmatrix.c ft_mysplit.c
SRC_ENV = get_index.c update_oldpwd.c update_pwd.c get_pwd.c get_export.c get_unset.c get_utils.c get_env.c get_echo.c get_envvars.c
SRC_PIP = pipex.c pipex_utils.c pipex_utils_2.c pipex_val_cmd.c pipex_here_doc.c pipex_close.c pipex_clean.c pipex_one_arrow.c pipex_two_arrow.c
SRC_FREE = free_env.c free_node.c free_tmini.c free_singlenode.c
SRC_CLN = clean_command.c closed_quotes.c clean_node.c clean_quotes.c expantions.c parse_node.c expand_args.c has_quotes.c split_value.c\
		expand_cmd.c

SRCS := main.c parsing.c parse_commands.c mini.c
SRCS += $(addprefix ft_search/, $(SRC_FT))
SRCS += $(addprefix src/, $(SRC_SRC))
SRCS += $(addprefix env_variables/, $(SRC_ENV))
SRCS += $(addprefix src/libft/, $(SRC_LIBF))
SRCS += $(addprefix ft_clean/, $(SRC_FREE))
SRCS += $(addprefix valid_str/, $(SRC_CLN))
SRCS += $(addprefix bilt_in/, $(SRC_BLT))
SRCS += $(addprefix pipes/, $(SRC_PIP))

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
