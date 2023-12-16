/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:21:13 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 00:55:09 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*look_lastnode(t_list *firstnum)
{
	if (firstnum == NULL)
		return (NULL);
	while (firstnum->next)
		firstnum = firstnum->next;
	return (firstnum);
}

void	putnode(t_list **box, int number)
{
	t_list	*node;
	t_list	*lastnode;

	if (box == NULL)
		return ;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->number = number;
	if (*box == NULL)
	{
		*box = node;
		node->previous = NULL;
	}
	else
	{
		lastnode = look_lastnode(*box);
		lastnode->next = node;
		node->previous = lastnode;
	}
}

void	call_box(t_list **a, char **argv, bool flag2)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (testnumber(argv[i]))
			free_argv(a, argv, flag2);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_argv(a, argv, flag2);
		if (test_content(*a, (int)number))
			free_argv(a, argv, flag2);
		putnode(a, (int)number);
		i++;
	}
	if (flag2)
		free_arg(argv);
}
