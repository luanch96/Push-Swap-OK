/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:24:41 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/13 17:56:36 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_maxnum(t_list *box)
{
	int		maxnum;
	t_list	*maxnode;

	if (box == NULL)
		return (NULL);
	maxnum = INT_MIN;
	while (box)
	{
		if (box->number > maxnum)
		{
			maxnum = box->number;
			maxnode = box;
		}
		box = box->next;
	}
	return (maxnode);
}

t_list	*find_minnum(t_list *box)
{
	long	minnum;
	t_list	*minnode;

	if (box == NULL)
		return (NULL);
	minnum = LONG_MAX;
	while (box)
	{
		if (box->number < minnum)
		{
			minnum = box->number;
			minnode = box;
		}
		box = box->next;
	}
	return (minnode);
}

bool	num_order(t_list *box)
{
	if (box == NULL)
		return (1);
	while (box->next)
	{
		if (box->number > box->next->number)
			return (false);
		box = box->next;
	}
	return (true);
}

void	first_boxnum(t_list **a)
{
	t_list	*maxnode;

	maxnode = find_maxnum(*a);
	if ((*a) == maxnode)
		ra(a);
	else if ((*a)->next == maxnode)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

void	inbox_ordering(t_list **a, t_list **b)
{
	while (boxlenght(*a) > 3)
	{
		start_nodes(*a, *b);
		stop_rotation(a, find_minnum(*a), 'a');
		pb(b, a);
	}
}
