/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:24:29 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 01:30:01 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotator(t_list **box)
{
	t_list	*lastnode;
	int		lenght;

	lenght = boxlenght(*box);
	if (box == NULL || *box == NULL || lenght == 1)
		return ;
	lastnode = look_lastnode(*box);
	lastnode->next = *box;
	*box = (*box)->next;
	(*box)->previous = NULL;
	lastnode->next->previous = lastnode;
	lastnode->next->next = NULL;
}

void	ra(t_list **a)
{
	rotator(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotator(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotator(a);
	rotator(b);
	write(1, "rr\n", 3);
}
