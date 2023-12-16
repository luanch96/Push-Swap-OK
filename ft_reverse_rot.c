/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:23:57 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 01:29:21 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rot(t_list **box)
{
	t_list	*lastnode;
	int		lenght;

	lenght = boxlenght(*box);
	if ((box == NULL || *box == NULL || lenght == 1))
		return ;
	lastnode = look_lastnode(*box);
	lastnode->previous->next = NULL;
	lastnode->next = *box;
	lastnode->previous = NULL;
	*box = lastnode;
	lastnode->next->previous = lastnode;
}

void	rrb(t_list **b)
{
	rev_rot(b);
	write(1, "rrb\n", 4);
}

void	rra(t_list **a)
{
	rev_rot(a);
	write(1, "rra\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rot(a);
	rev_rot(b);
	write(1, "rrr\n", 4);
}
