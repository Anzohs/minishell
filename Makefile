NAME = minishell

CC = gcc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -g -I. -Isrc/libf  -Imini_struct
CCFLAGS = -lreadline
SRC_MS = create_pwd.c m_copy_env.c mini.c ft_cmdlst_new.c ft_cmdlstadd_back.c create_oldpwd.c \
		ft_cmdlstclear.c ft_cmdlstdelone.c ft_cmdlst_len.c get_var.c matrix_len.c ft_cmdsize.c \
		ft_fd_del.c ft_fd_new.c ft_fdadd_back.c change_fd.c
SRC_LIBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c ft_lstdup.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lsthas.c ft_lstgetlst.c ft_lstsort.c ft_lsttomatrix.c \
			get_next_line.c get_next_line_utils.c ft_lstpop.c
SRC_PRS = parse_input.c closed_quotes.c is_valid.c expantions.c clean_content.c is_expantion.c sub_expantion.c split_value.c \
			take_quotes.c free_matrix.c split_need.c is_builtin.c parse_redirects.c create_matrix.c
SRC_EXE = execute.c cd_execute.c pwd_execute.c export_print.c export_built.c env_execute.c unset_execute.c echo_exec.c execute_builtin.c exit_execute.c
SRC_SIG = load_signals.c
SRC_BLT = cd_biltin.c is_biltin.c
SRC_SRC = copy_env.c create_env.c ft_free_strs.c
SRC_ENV = get_index.c update_oldpwd.c update_pwd.c get_pwd.c get_export.c get_unset.c get_utils.c get_env.c get_echo.c get_envvars.c
SRC_PIP = pipex.c pipex_utils.c pipex_utils_2.c pipex_val_cmd.c pipex_close.c pipex_clean.c pipex_here_doc.c pipex_close_files.c pipex_check_cmd.c \
		pipex_last_process.c pipex_open_files.c
SRC_FREE = free_env.c free_node.c free_tmini.c free_singlenode.c
SRC_CLN = clean_command.c closed_quotes.c clean_node.c clean_quotes.c expantions.c parse_node.c expand_args.c has_quotes.c split_value.c \
		expand_cmd.c
SRC_NEWP = matrix_to_cmd.c new_parse.c redirects_parsing.c trim_spaces.c expation_mark.c change_cmd.c

SRCS := main.c
SRCS += $(addprefix mini_struct/, $(SRC_MS))
SRCS += $(addprefix libft/, $(SRC_LIBFT))
SRCS += $(addprefix parse_input/, $(SRC_PRS))
SRCS += $(addprefix execute/, $(SRC_EXE))
SRCS += $(addprefix signals/, $(SRC_SIG))
SRCS += $(addprefix pipes/, $(SRC_PIP))
SRCS += $(addprefix new_parser/, $(SRC_NEWP))

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

v :	$(NAME)
	valgrind --suppressions=read.supp --show-leak-kinds=all --leak-check=full ./minishell

vf : $(NAME)
	valgrind --suppressions=read.supp --show-leak-kinds=all --leak-check=full --trace-children=yes --track-fds=yes ./minishell

.PHONY: all clean fclean re
