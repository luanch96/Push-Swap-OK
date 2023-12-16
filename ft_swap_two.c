/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:24:55 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 01:23:37 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **firstnum)
{
	int	lenght;

	lenght = boxlenght(*firstnum);
	if (firstnum == NULL || *firstnum == NULL || lenght == 1)
		return ;
	*firstnum = (*firstnum)->next;
	(*firstnum)->previous->previous = *firstnum;
	(*firstnum)->previous->next = (*firstnum)->next;
	if ((*firstnum)->next)
	{
		(*firstnum)->next->previous = (*firstnum)->previous;
	}
	(*firstnum)->next = (*firstnum)->previous;
	(*firstnum)->previous = NULL;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
