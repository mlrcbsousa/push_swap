/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:06:15 by msousa            #+#    #+#             */
/*   Updated: 2022/02/09 16:19:53 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_small(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = *(int *)ft_lstmin_int(a->head);
  max = *(int *)ft_lstmax_int(a->head);
  while (!ft_islstsorted_int(a->head))
	{
		if (*(int *)a->head->content == max
			&& *(int *)a->head->next->content == min)
			ra(a, b);
		else if ((*(int *)a->head->content == min
			&& *(int *)a->head->next->content == max)
			|| (*(int *)a->head->content > *(int *)a->head->next->content))
			sa(a, b);
		else
			rra(a, b);
	}
}

void print(void *content)
{
	printf("%d, ", *(int *)content);
}

// ft_lstiter(a.head, print);
// printf("\na size: %d\n\n", a.size);
// ft_lstiter(b.head, print);
// printf("\nb size: %d\n\n", b.size);

void partition_medium(t_stack *a, t_stack *b)
{
	int	median;
	int	middle;

	median = stack_median(a);
	middle = a->size / 2;
	while (middle)
	{
		if (*(int *)a->head->content < median)
		{
			middle--;
			pb(a, b);
		}
		else
			ra(a, b);
	}
}

void sort_medium(t_stack *a, t_stack *b)
{
	int b_size;

	partition_medium(a, b);
	sort_small(a, b);
	if (ft_islstsorted_int(b->head))
		sb(a, b);
	b_size = b->size;
	while (b_size--)
		pa(a, b);
}

void sort_large(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}
