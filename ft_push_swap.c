/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:22:13 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 01:32:43 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_all(t_list **a, t_list **b, t_list *lowest_node)
{
	while (*a != lowest_node->node && *b != lowest_node)
	{
		rr(a, b);
	}
	conf_pos(*a);
	conf_pos(*b);
}

static void	reverse_rotate_all(t_list **a, t_list **b, t_list *lowest_node)
{
	while (*a != lowest_node->node && *b != lowest_node)
	{
		rrr(a, b);
	}
	conf_pos(*a);
	conf_pos(*b);
}

void	stop_rotation(t_list **box, t_list *firstnumber, char box_desript)
{
	while (*box != firstnumber)
	{
		if (box_desript == 'a')
		{
			if (firstnumber->under_median)
				ra(box);
			else
				rra(box);
		}
		else if (box_desript == 'b')
		{
			if (firstnumber->under_median)
				rb(box);
			else
				rrb(box);
		}
	}
}

static void	move_numbers(t_list **a, t_list **b)
{
	t_list	*lowest_node;

	lowest_node = sendlow(*b);
	if (lowest_node->under_median && lowest_node->node->under_median)
	{
		rotate_all(a, b, lowest_node);
	}
	else if (!(lowest_node->under_median && lowest_node->node->under_median))
	{
		reverse_rotate_all(a, b, lowest_node);
	}
	stop_rotation(b, lowest_node, 'b');
	stop_rotation(a, lowest_node->node, 'a');
	pa(a, b);
}

void	push_swap(t_list **a, t_list **b)
{
	t_list	*lowest_node;
	int		a_lenght;

	a_lenght = boxlenght(*a);
	if (a_lenght == 5)
		inbox_ordering(a, b);
	else
	{
		while (a_lenght-- > 3)
			pb(b, a);
	}
	first_boxnum(a);
	while (*b)
	{
		start_nodes(*a, *b);
		move_numbers(a, b);
	}
	conf_pos(*a);
	lowest_node = find_minnum(*a);
	if (lowest_node->under_median)
		while (*a != lowest_node)
			ra(a);
	else
		while (*a != lowest_node)
			rra(a);
}
