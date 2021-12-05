/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:31:24 by msousa            #+#    #+#             */
/*   Updated: 2021/12/05 12:03:36 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	int	*first;
	int	*second;

	(void)b;
	if (a->size < 2)
		return ;
	first = (int *)stack_pop(a);
	second = (int *)stack_pop(a);

	printf("%d, %d\n", *first, *second);
	ft_lstiter(a->head, print);
	printf("size: %d\n", a->size);
	
	stack_push(a, first);

	ft_lstiter(a->head, print);
	printf("size: %d\n", a->size);

	stack_push(a, second);
}