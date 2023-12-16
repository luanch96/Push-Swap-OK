/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:21:36 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 00:57:55 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	boxlenght(t_list *box)
{
	int	counter;

	if (box == NULL)
		return (0);
	counter = 0;
	while (box)
	{
		counter++;
		box = box->next;
	}
	return (counter);
}

t_list	*sendlow(t_list *box)
{
	if (box == NULL)
	{
		return (NULL);
	}
	while (box)
	{
		if (box->lowest)
			return (box);
		box = box->next;
	}
	return (NULL);
}
