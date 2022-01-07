/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:09:14 by msousa            #+#    #+#             */
/*   Updated: 2022/01/07 14:51:05 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// LIBFT


// LIBFT

static void	error(t_list *list)
{
	if (list)
		ft_lstclear(&list, free);
	ft_putendl_fd("Error", STDERR);
	exit(EXIT_FAILURE);
}

void	print(void *content)
{
	printf("%d, ", *(int *)content);
}

static t_bool	is_equal(void *content, void *data)
{
	return (*(int *)content == *(int *)data);
}

static t_bool	valid(int argc, char *argv[], t_stack *stack)
{
	long	tmp;
	int	*content;

	if (!argc)
		return (FALSE);
	while (argc)
	{
		if (!ft_isnumber(argv[argc - 1]))
			return (FALSE);
		tmp = ft_atol(argv[argc-- - 1]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (FALSE);
		content = (int *)malloc(sizeof(*content));
		if (!content)
			return (FALSE);
		*content = (int)tmp;
		if (stack->head && ft_lstfind(stack->head, content, is_equal))
			error(stack->head);
		stack_push(stack, content);
	}
	return (TRUE);
}

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

// void partition_medium(t_stack *a, t_stack *b)
// {
// 	int	median_value;
// 	// int	median_index;
// 	int	half_length;

// 	median_value = ft_lst_get_median(*a);
// 	half_length = a->size / 2;
// 	while (half_length)
// 	{
// 		if (*(int *)a->head->content < median_value)
// 		{
// 			half_length--;
// 			pb(a, b);
// 		}
// 		else if (is_median_closer_to_top(*a, median_value))
// 			ra(a, b);
// 		else
// 			rra(a, b);
// 	}
// }

// void sort_medium(t_stack *a, t_stack *b)
// {
// 	partition_medium(a, b);
// 	sort_small(a, b);
// 	if (ft_islstsorted_int(b->head))
// 		sb(a, b);
// 	// merge_b_into_a_ordering(a, b);
// }

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = (t_stack) {NULL, 0};
	b = (t_stack) {NULL, 0};

	if (!valid(argc - 1, &argv[1], &a))
		error(NULL);

	// ft_lstiter(a.head, print);
	// printf("\na size: %d\n\n", a.size);
	// ft_lstiter(b.head, print);
	// printf("\nb size: %d\n\n", b.size);

  if (!ft_islstsorted_int(a.head))
  {
    if (a.size < 4)
      sort_small(&a, &b);
		else if (a.size < 6)
			;
			// sort_medium(&a, &b);
		// else
		// 	sort_large(&a, &b);
	}
  // else
  //   ft_putendl("sorted");


  // ft_lstiter(a.head, print);
	// printf("\na size: %d\n\n", a.size);
	// ft_lstiter(b.head, print);
	// printf("\nb size: %d\n\n", b.size);

  ft_lstclear(&a.head, free);
  return (0);
}
