SRCS_D			= ./srcs/
HEADER_D		= ./include/
LIBFT_D			= ./libft/
SRCS_F			= ft_new_node.c\
					ft_free_stack.c\
					ft_fill_stack.c\
					ft_get_sorted_index.c\
					ft_parse_args.c\
					ft_print_stack.c\
					ft_get_last.c\
					ft_get_size.c\
					ft_is_sorted.c\
					ft_swap.c\
					ft_push.c\
					ft_rotate.c\
					ft_reverse_rotate.c\
					ft_solve.c\
					ft_find_prev.c\
					ft_count_moves.c\
					ft_push_cheapest.c\
					ft_set_moves_to_top.c\
					ft_push_quantiles.c\
					ft_checker.c
SRCS			= $(addprefix $(SRCS_D), $(SRCS_F))
OBJS			= $(SRCS:.c=.o)
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -I$(HEADER_D) -I./libft/include -g 
NAME			= push_swap
LIBFT			= $(addprefix $(LIBFT_D), libft.a)


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_D)

$(NAME): $(LIBFT) $(OBJS) push_swap.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -g push_swap.c -o $(NAME) $(OBJS) -L$(LIBFT_D) -lft

bonus: $(LIBFT) $(OBJS) checker.c
	$(CC) $(CPPFLAGS) $(CFLAGS) checker.c -o checker $(OBJS) -L$(LIBFT_D) -lft

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_D) clean

fclean:
	rm -f $(OBJS) $(NAME)
	make -C $(LIBFT_D) fclean

norme:
	make -C $(LIBFT_D) norme
	norminette -R push_swap.c checker.c $(SRCS)
	norminette -R CheckDefine $(HEADER_D)

re: fclean all

.PHONY: fclean clean all debug bonus
