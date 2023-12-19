/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:22:26 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/19 19:51:51 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		call_box(&a, argv, false);
	}
	else if (argc > 2)
		call_box(&a, argv + 1, argc == 2);
	if (!num_order(a))
	{
		if (boxlenght(a) == 2)
			sa(&a);
		else if (boxlenght(a) == 3)
			first_boxnum(&a);
		else
			push_swap(&a, &b);
	}
	free_boxes(&a);
}
