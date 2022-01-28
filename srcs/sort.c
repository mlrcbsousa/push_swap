/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:06:15 by msousa            #+#    #+#             */
/*   Updated: 2022/01/28 00:21:52 by msousa           ###   ########.fr       */
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

void partition_medium(t_stack *a, t_stack *b)
{
	int	median_value;
	// int	median_index;
	int	middle;

	median_value = stack_median(a);
	print(&median_value);
	printf("Got Here");
	middle = a->size / 2;
	while (middle)
	{
		if (*(int *)a->head->content < median_value)
		{
			middle--;
			pb(a, b);
		}
		// else if (is_median_closer_to_top(*a, median_value))
		// 	ra(a, b);
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

void sort_medium(t_stack *a, t_stack *b)
{
	partition_medium(a, b);
	sort_small(a, b);
	if (ft_islstsorted_int(b->head))
		sb(a, b);
	// merge_b_into_a_ordering(a, b);
}

void sort_large(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}
