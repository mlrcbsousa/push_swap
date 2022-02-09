/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:06:15 by msousa            #+#    #+#             */
/*   Updated: 2022/02/09 20:19:16 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_medium(t_stack *a, t_stack *b)
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

void	sort_small(t_stack *a, t_stack *b)
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

void	sort_medium(t_stack *a, t_stack *b)
{
	partition_medium(a, b);
	sort_small(a, b);
	if (ft_islstsorted_int(b->head))
		sb(a, b);
	while (b->size)
		pa(a, b);
}

static void	transform_stack_contents_to_index(t_stack *stack)
{
	int		i;
	t_list	*list;
	t_list	*sorted;
	t_list	*sorted_tmp;

	sorted = ft_lstdup_int(stack->head);
	ft_lstsort(sorted, 0, stack->size - 1);
	list = stack->head;
	while (list)
	{
		sorted_tmp = sorted;
		i = 0;
		while (i < stack->size)
		{
			if (*(int *)list->content == *(int *)sorted_tmp->content)
			{
				*(int *)list->content = i;
				break ;
			}
			sorted_tmp = sorted_tmp->next;
			i++;
		}
		list = list->next;
	}
	ft_lstclear(&sorted, free);
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	num;
	int	size;

	transform_stack_contents_to_index(a);
	size = a->size;
	i = 0;
	while (!ft_islstsorted_int(a->head))
	{
		j = 0;
		while (j < size)
		{
			num = *(int *)a->head->content;
			if ((num >> i) & 1)
				ra(a, b);
			else
				pb(a, b);
			j++;
		}
		while (b->size)
			pa(a, b);
		i++;
	}
}
