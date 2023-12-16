/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:21:57 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 01:03:53 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arg(char **argv)
{
	int	j;

	j = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[j])
		free(argv[j++]);
	free(argv - 1);
}

void	free_boxes(t_list **box)
{
	t_list	*temporal;
	t_list	*current;

	if (box == NULL)
		return ;
	current = *box;
	while (current)
	{
		temporal = current->next;
		free(current);
		current = temporal;
	}
	*box = NULL;
}

void	free_argv(t_list **a, char **argv, bool flag2)
{
	free_boxes(a);
	if (flag2)
		free_arg(argv);
	write(2, "Error\n", 6);
	exit (1);
}

int	testnumber(char *the_number)
{
	if (!(*the_number == '-' || *the_number == '+'
			|| (*the_number >= '0' && *the_number <= '9')))
		return (1);
	if ((*the_number == '-' || *the_number == '+')
		&& !(the_number[1] >= '0' && the_number[1] <= '9'))
		return (1);
	the_number++;
	while (*the_number)
	{
		if (!(*the_number >= '0' && *the_number <= '9'))
			return (1);
		the_number++;
	}
	return (0);
}

int	test_content(t_list *a, int num)
{
	if (a == NULL)
	{
		return (0);
	}
	while (a)
	{
		if (a->number == num)
		{
			return (1);
		}
		a = a->next;
	}
	return (0);
}
