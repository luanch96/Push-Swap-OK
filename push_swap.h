/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:23:29 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/19 19:52:20 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				number;
	int				position;
	int				number2;
	bool			under_median;
	bool			lowest;
	struct s_list	*node;
	struct s_list	*previous;
	struct s_list	*next;
}				t_list;

void	pb(t_list **b, t_list **a);
void	pa(t_list **a, t_list **b);
int		boxlenght(t_list *box);
t_list	*sendlow(t_list *box);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
t_list	*look_lastnode(t_list *firstnum);
void	putnode(t_list **box, int num);
void	call_box(t_list **a, char **argv, bool flag2);
void	free_arg(char **argv);
void	free_boxes(t_list **box);
void	free_argv(t_list **a, char **argv, bool flag_argc_2);
int		testnumber(char *the_number);
int		test_content(t_list *a, int num);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rrb(t_list **b);
void	rra(t_list **a);
void	rrr(t_list **a, t_list **b);
bool	num_order(t_list *box);
void	first_boxnum(t_list **a);
void	inbox_ordering(t_list **a, t_list **b);
void	conf_pos(t_list *box);
void	size_number(t_list *a, t_list *b);
void	box_longest(t_list *b);
void	start_nodes(t_list *a, t_list *b);
void	stop_rotation(t_list **box, t_list *firstnumber, char box_desript);
void	push_swap(t_list **a, t_list **b);
t_list	*find_minnum(t_list *box);
void	first_boxnum(t_list **a);
void	inbox_ordering(t_list **a, t_list **b);
long	ft_atoi(char *str);
char	*ft_strncpy(char *s1, char *s2, int n);
char	**ft_split(const char *str, char c);
size_t	ft_strlen(const char *s);

#endif
