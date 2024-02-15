/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:31:22 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 09:35:07 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# define RTO_RFROM 0
# define RTO_RRFROM 1
# define RRTO_RFROM 2
# define RRTO_RRFROM 3
# define A 0
# define B 1
# define ASC 0
# define DESC 1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	int				top;
	int				rr;
	int				r;
	int				quantile;
	struct s_stack	*next;
}	t_stack;

typedef struct s_move
{
	int	rto;
	int	rfrom;
	int	rrto;
	int	rrfrom;
	int	rr;
	int	rrr;
	int	min;
	int	seq;
}	t_move;

t_stack	*ft_new_node(int value, int index, int top);
int		*ft_get_sorted_index(int *vec, int size);
t_stack	*ft_parse_args(int ac, char **av);
void	ft_fill_stack(int ac, char **av, t_stack *stacks[2]);
t_stack	*ft_free_stack(t_stack *stack);
void	ft_free_stacks(t_stack *stack[2]);
t_stack	*ft_get_last(t_stack *stack);
int		ft_get_size(t_stack *stack);
int		ft_is_sorted_asc(t_stack *stack);
int		ft_is_sorted_desc(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
void	ft_print_stacks(t_stack *stack[2]);
void	ft_sa(t_stack *stacks[2], int n, int print);
void	ft_sb(t_stack *stacks[2], int n, int print);
void	ft_ss(t_stack *stacks[2], int n, int print);
void	ft_pb(t_stack *stacks[2], int n, int print);
void	ft_pa(t_stack *stacks[2], int n, int print);
void	ft_ra(t_stack *stacks[2], int n, int print);
void	ft_rb(t_stack *stacks[2], int n, int print);
void	ft_rr(t_stack *stacks[2], int n, int print);
void	ft_rra(t_stack *stacks[2], int n, int print);
void	ft_rrb(t_stack *stacks[2], int n, int print);
void	ft_rrr(t_stack *stacks[2], int n, int print);
void	ft_solve(t_stack *stacks[2]);
t_stack	*ft_find_prev(int index, t_stack *stack, int asc);
t_move	ft_count_moves(t_stack *node, t_stack *prev);
void	ft_set_moves_to_top(t_stack *stack);
void	ft_push_cheapest(int to, t_stack *stacks[2]);
void	ft_push_quantiles(t_stack *stacks[2], int n);
void	ft_checker(t_stack *stacks[2]);

#endif