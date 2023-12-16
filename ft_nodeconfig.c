/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeconfig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:23:06 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 01:07:30 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conf_pos(t_list *box)
{
	int	i;
	int	half;

	i = 0;
	if (box == NULL)
		return ;
	half = boxlenght(box) / 2;
	while (box)
	{
		box->position = i;
		if (i <= half)
			box->under_median = true;
		else
			box->under_median = false;
		box = box->next;
		i++;
	}
}

static void	target_node(t_list *a, t_list *b)
{
	t_list	*node_a;
	t_list	*node_after;
	long	highest_num;

	while (b)
	{
		highest_num = LONG_MAX;
		node_a = a;
		while (node_a)
		{
			if (node_a->number > b->number && node_a->number < highest_num)
			{
				highest_num = node_a->number;
				node_after = node_a;
			}
			node_a = node_a->next;
		}
		if (LONG_MAX == highest_num)
			b->node = find_minnum(a);
		else
			b->node = node_after;
		b = b->next;
	}
}

void	size_number(t_list *a, t_list *b)
{
	int	a_lenght;
	int	b_lenght;

	a_lenght = boxlenght(a);
	b_lenght = boxlenght(b);
	while (b)
	{
		b->number2 = b->position;
		if (!(b->under_median))
			b->number2 = b_lenght - (b->position);
		if (b->node->under_median)
			b->number2 += b ->node->position;
		else
			b->number2 += a_lenght - (b->node->position);
		b = b->next;
	}
}

void	box_longest(t_list *b)
{
	t_list	*longest_node;
	long	longest_number;

	if (b == NULL)
		return ;
	longest_number = LONG_MAX;
	longest_node = NULL;
	while (b)
	{
		if (b->number2 < longest_number)
		{
			longest_number = b->number2;
			longest_node = b;
		}
		b = b->next;
	}
	longest_node->lowest = true;
}

void	start_nodes(t_list *a, t_list *b)
{
	conf_pos(a);
	conf_pos(b);
	target_node(a, b);
	size_number(a, b);
	box_longest(b);
}
