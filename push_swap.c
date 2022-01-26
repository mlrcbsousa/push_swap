/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:09:14 by msousa            #+#    #+#             */
/*   Updated: 2022/01/25 21:25:15 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(t_list *list)
{
	if (list)
		ft_lstclear(&list, free);
	ft_putendl_fd("Error", STDERR);
	exit(EXIT_FAILURE);
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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a = (t_stack) {NULL, 0};
	b = (t_stack) {NULL, 0};
	if (!valid(argc - 1, &argv[1], &a))
		error(NULL);
  if (!ft_islstsorted_int(a.head))
  {
    if (a.size < 4)
      sort_small(&a, &b);
		else if (a.size < 6)
			sort_medium(&a, &b);
		else
			sort_large(&a, &b);
	}
  ft_lstclear(&a.head, free);
  return (0);
}
