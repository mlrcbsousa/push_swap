/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:09:14 by msousa            #+#    #+#             */
/*   Updated: 2022/01/05 22:03:44 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// LIBFT
long	ft_atol(const char *str)
{
	int				sign;
	long long	number;

	sign = 1;
	number = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str++ - '0';
		if (number < 0)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
	}
	return ((long)(number * sign));
}

// void	ft_lstiter_if(t_list *list, void (*f)(), void *data, int (*cmp)())
// {
// 	t_list	*tmp;

// 	tmp = list;
// 	while (tmp)
// 	{
// 		if (!cmp(tmp->content, data))
// 			f(list, tmp, data);
// 		tmp = tmp->next;
// 	}
// }

t_list	*ft_lstfind(t_list *list, void *data, int (*cmp)())
{
	while (list)
	{
		if (cmp(list->content, data))
			break ;
		list = list->next;
	}
	return (list);
}

t_list	*ft_lstat(t_list *list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i++ < nbr)
	{
		if (!list)
			break ;
		list = list->next;
	}
	return (list);
}

void *ft_lstmin_int(t_list *list)
{
  void *min;

  if (!list)
    return (NULL);
  min = list->content;
  while (list)
  {
    if (*(int *)list->content < *(int *)min)
      min = list->content;
    list = list->next;
  }
  return (min);
}

void *ft_lstmax_int(t_list *list)
{
  void *max;

  if (!list)
    return (NULL);
  max = list->content;
  while (list)
  {
    if (*(int *)list->content > *(int *)max)
      max = list->content;
    list = list->next;
  }
  return (max);
}

t_bool is_lstsorted_int(t_list *list)
{
  if (!list)
    return (FALSE);
  while (list->next)
  {
    if (*(int *)list->content > *(int *)list->next->content)
      return (FALSE);
    list = list->next;
  }
  return (TRUE);
}
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
  while (!is_lstsorted_int(a->head))
	{
		if (*(int *)a->head->content == max
			&& *(int *)a->head->next->content == min)
			ra(a, b);
		// else
		// 	sa(a, b);
	}
}

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

  if (!is_lstsorted_int(a.head))
  {
    if (a.size <= 3)
      sort_small(&a, &b);
  }
  else
    ft_putendl("sorted");


  // ft_lstiter(a.head, print);
	// printf("\na size: %d\n\n", a.size);
	// ft_lstiter(b.head, print);
	// printf("\nb size: %d\n\n", b.size);

  ft_lstclear(&a.head, free);
  return (0);
}
