/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:09:14 by msousa            #+#    #+#             */
/*   Updated: 2021/12/05 12:12:27 by msousa           ###   ########.fr       */
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

void	ft_lstiter_if(t_list *list, void (*f)(), void *data, int (*cmp)())
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (!cmp(tmp->content, data))
			f(list, tmp, data);
		tmp = tmp->next;
	}
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

static t_bool	is_different(void *content, void *data)
{
	return (*(int *)content != *(int *)data);
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
		if (stack->head)
			ft_lstiter_if(stack->head, error, content, is_different);
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
	
	ft_lstiter(a.head, print);
	printf("a size: %d\n", a.size);
	ft_lstiter(b.head, print);
	printf("b size: %d\n", b.size);

	ss(&a, &b);
	
	ft_lstiter(a.head, print);
	printf("a size: %d\n", a.size);
	ft_lstiter(b.head, print);
	printf("b size: %d\n", b.size);
	return (0);
}