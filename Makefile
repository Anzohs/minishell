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
			take_quotes.c free_matrix.c split_need.c
SRC_EXE = execute.c cd_execute.c pwd_execute.c
SRC_SIG = load_signals.c

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
