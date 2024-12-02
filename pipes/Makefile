NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
GNL_DIR = ./get_next_line

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a
FT_GNL = $(GNL_DIR)/libftgetnextline.a

SRC_DIR = .
SRC_BONUS_DIR = ./bonus_pipex

SRCS = pipex.c pipex_utils.c pipex_val_cmd.c pipex_clean.c pipex_utils_2.c pipex_close.c pipex_here_doc.c

SRCS_BONUS = pipex_bonus.c pipex_utils_bonus.c pipex_val_cmd_bonus.c pipex_clean_bonus.c \
		pipex_close_bonus.c pipex_utils_2_bonus.c

OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(SRC_BONUS_DIR)/%.o)

$(NAME): $(LIBFT) $(FT_PRINTF) $(FT_GNL) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GNL_DIR) -lftgetnextline -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(FT_PRINTF) $(FT_GNL) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GNL_DIR) -lftgetnextline -o $(NAME_BONUS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(PRINTF_DIR)

$(FT_GNL):
	@make -C $(GNL_DIR)

bonus: $(NAME_BONUS)

all: $(NAME) $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(GNL_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(GNL_DIR)

re: fclean all

.PHONY: bonus all clean fclean re
