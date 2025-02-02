NAME = minishell

CC = gcc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -g -I. -Isrc/libf -Ift_search -Imini_struct
CCFLAGS = -lreadline
SRC_SR = hash.c hcreate.c hdestroy.c hsearch.c
SRC_MS = create_pwd.c m_copy_env.c mini.c ft_cmdlst_new.c ft_cmdlstadd_back.c create_oldpwd.c \
		ft_cmdlstclear.c ft_cmdlstdelone.c ft_cmdlst_len.c get_var.c
SRC_LIBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c ft_lstdup.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lsthas.c
SRC_PRS = parse_input.c closed_quotes.c is_valid.c transform_str.c expantions.c clean_content.c is_expantion.c sub_expantion.c split_value.c \
			take_quotes.c free_matrix.c split_need.c is_builtin.c
SRC_EXE = execute.c cd_execute.c pwd_execute.c
SRC_SIG = load_signals.c
SRC_FT = hash.c hcreate.c hdestroy.c hsearch.c node_len.c
SRC_BLT = cd_biltin.c is_biltin.c
SRC_SRC = copy_env.c create_env.c ft_free_strs.c
SRC_LIBF = ft_bzero.c ft_calloc.c ft_strcat.c ft_strcpy.c ft_strncmp.c ft_strlen.c ft_strrchr.c ft_strcmp.c \
			ft_strdup.c ft_strncpy.c ft_strjoin.c ft_strchr.c get_next_line.c get_next_line_utils.c ft_split.c ft_substr.c\
			ft_isupper.c ft_islower.c ft_isalpha.c ft_joinmatrix.c ft_mysplit.c
SRC_ENV = get_index.c update_oldpwd.c update_pwd.c get_pwd.c get_export.c get_unset.c get_utils.c get_env.c get_echo.c get_envvars.c
SRC_PIP = pipex.c pipex_utils.c pipex_utils_2.c pipex_val_cmd.c pipex_here_doc.c pipex_close.c pipex_clean.c pipex_one_arrow.c pipex_two_arrow.c\
			pipex_one_arrow_reverse.c
SRC_FREE = free_env.c free_node.c free_tmini.c free_singlenode.c
SRC_CLN = clean_command.c closed_quotes.c clean_node.c clean_quotes.c expantions.c parse_node.c expand_args.c has_quotes.c split_value.c\
		expand_cmd.c

SRCS := main.c
SRCS += $(addprefix ft_search/, $(SRC_SR))
SRCS += $(addprefix mini_struct/, $(SRC_MS))
SRCS += $(addprefix libft/, $(SRC_LIBFT))
SRCS += $(addprefix parse_input/, $(SRC_PRS))
SRCS += $(addprefix execute/, $(SRC_EXE))
SRCS += $(addprefix signals/, $(SRC_SIG))

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
