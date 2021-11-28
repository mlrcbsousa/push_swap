/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:09:14 by msousa            #+#    #+#             */
/*   Updated: 2021/11/29 00:04:20 by msousa           ###   ########.fr       */
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

void	ft_lstiter_if(t_list *lst, void (*f)(void *), void *data, int (*cmp)())
{
	while (lst)
	{
		if (!cmp(lst->content, data))
			f(lst->content);
		lst = lst->next;
	}
}

static void	error(void *content)
{
	(void)content;
	ft_putendl_fd("Error", STDERR);
	exit(EXIT_FAILURE);
}

#include <stdio.h>

void	print(void *content)
{
	printf("%d\n", *(int *)content);
}

t_bool	is_different(void *content, void *data)
{
	print(content);
	print(data);
	return (*(int *)content != *(int *)data);
}

static t_bool	valid(int argc, char *argv[], t_stack *stack)
{
	int	i;
	long	tmp;
	int	content;

	i = 0;
	if (!argc)
		return (FALSE);
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (FALSE);
		tmp = ft_atol(argv[i++]);
		if (tmp > INT_MAX)
			return (FALSE);
		content = (int)tmp;
		printf("bf stack->head %d\n", content);
		if (stack->head)
		{
			printf("stack->head %d %d\n", content, *(int *)(stack->head->content));
			ft_lstiter_if(stack->head, error, &content, is_different);
		}
		stack_push(stack, &content);
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	// t_stack	b;

	a = (t_stack) {.head = NULL, .size = 0};
	// b = (t_stack) {.head = 0, .size = 0};
	
	// printf("%d\n", INT_MAX);
	// printf("%ld\n", 2147483649);
	// printf("%ld\n", ft_atol("2147483649"));
	// printf("%d\n", ft_atoi("21474836409"));
	if (!valid(argc - 1, &argv[1], &a))
		error(0);
	ft_lstiter(a.head, print);
	printf("size: %d\n", a.size);
	return (0);
}