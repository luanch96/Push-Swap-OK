/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:23:46 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 01:20:23 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push2(t_list **destiny, t_list **origin)
{
	t_list	*node;

	if (*origin == NULL)
		return ;
	node = *origin;
	*origin = (*origin)->next;
	if (*origin)
		(*origin)->previous = NULL;
	node->previous = NULL;
	if (*destiny == NULL)
	{
		*destiny = node;
		node->next = NULL;
	}
	else
	{
		node->next = *destiny;
		node->next->previous = node;
		*destiny = node;
	}
}

void	pb(t_list **b, t_list **a)
{
	push2(b, a);
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	push2(a, b);
	write(1, "pa\n", 3);
}
