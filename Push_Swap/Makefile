GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m

SRC =	ps_main.c \
		ps_input_control.c \
		ps_check_num_len.c \
		ps_arr_list.c \
		ps_s_movements.c \
		ps_p_movements.c \
		ps_r_movements.c \
		ps_rr_movements.c \
		ps_sorter.c \
		ps_finder.c \
		ps_ksort.c \

B_SRC =	ps_input_control.c \
		ps_check_num_len.c \
		ps_arr_list.c \
		ps_s_movements.c \
		ps_p_movements.c \
		ps_r_movements.c \
		ps_rr_movements.c \
		ps_main_bonus.c \
		ps_decoder_bonus.c \

NAME = push_swap

B_NAME = checker

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize="address"

LIBFT = ./Libft/libft.a

all: $(NAME)
	@echo "$(GREEN)--------------------------------------------$(NC)"
	@echo "$(GREEN)------------ Push Swap Is Ready ------------$(NC)"
	@echo "$(GREEN)--------------------------------------------$(NC)"

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(YELLOW)----------- Compiling Push Swap ------------$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)------- Push Swap Finished Compiling -------$(NC)\n"

bonus: $(B_NAME)
	@echo "$(GREEN)--------------------------------------------$(NC)"
	@echo "$(GREEN)------------- Checker Is Ready -------------$(NC)"
	@echo "$(GREEN)--------------------------------------------$(NC)"

$(B_NAME): $(B_OBJ) $(LIBFT)
	@echo "$(YELLOW)------------ Compiling Checker -------------$(NC)"
	@$(CC) $(CFLAGS) $(B_OBJ) $(LIBFT) -o $(B_NAME)
	@echo "$(GREEN)-------- Checker Finished Compiling --------$(NC)\n"

$(LIBFT):
	@make -sC ./Libft bonus

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make -sC ./Libft fclean
	@rm -f $(OBJ) $(B_OBJ)
	@echo "$(RED)------------- Objects Cleaned --------------$(NC)"

fclean: clean
	@rm -f $(NAME) $(B_NAME)
	@echo "$(RED)------------ Push_Swap Cleaned -------------$(NC)"

re: fclean all

.PHONY: all clean fclean re bonus
