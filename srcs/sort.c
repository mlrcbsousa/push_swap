/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:06:15 by msousa            #+#    #+#             */
/*   Updated: 2022/01/07 18:21:34 by msousa           ###   ########.fr       */
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

// int	ft_lst_get_median(t_list *lst)
// {
// 	t_list		*dup;
// 	t_list		*tmp;
// 	int			middle;
// 	int	median;

// 	dup = ft_lstdup(lst);
// 	middle = ft_lstsize(dup) / 2;
// 	ft_lst_sort(&dup, ascending);
// 	tmp = dup;
// 	while (middle--)
// 		tmp = tmp->next;
// 	median = (int)tmp->data;
// 	ft_lstclear(&dup, ft_lstdel_int);
// 	return (median);
// }

// void partition_medium(t_stack *a, t_stack *b)
// {
// 	int	median_value;
// 	// int	median_index;
// 	int	middle;

// 	median_value = 0;//ft_lst_get_median(*a);
// 	middle = a->size / 2;
// 	while (middle)
// 	{
// 		if (*(int *)a->head->content < median_value)
// 		{
// 			middle--;
// 			pb(a, b);
// 		}
// 		// else if (is_median_closer_to_top(*a, median_value))
// 		// 	ra(a, b);
// 		else
// 			rra(a, b);
// 	}
// }

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
	// partition_medium(a, b);
	// sort_small(a, b);
	// if (ft_islstsorted_int(b->head))
	// 	sb(a, b);
	// // merge_b_into_a_ordering(a, b);
	int	popped;

	while (a->size)
	{
		popped = *(int *)a->head->content;
		if (b->size && popped < *(int *)b->head->content)
		{
			ra(a, b);
			while (b->size && popped < *(int *)b->head->content)
				pa(a, b);
			rra(a, b);
		}
		pb(a, b);
	}
	while (b->size)
		pa(a, b);
}

void sort_large(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}
