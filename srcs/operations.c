/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:31:24 by msousa            #+#    #+#             */
/*   Updated: 2021/12/05 12:18:20 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	void	*first;
	void	*second;

	(void)b;
	if (a->size < 2)
		return ;
	first = stack_pop(a);
	second = stack_pop(a);
	stack_push(a, first);
	stack_push(a, second);
}

void	sb(t_stack *a, t_stack *b)
{
	void	*first;
	void	*second;

	(void)a;
	if (b->size < 2)
		return ;
	first = stack_pop(b);
	second = stack_pop(b);
	stack_push(b, first);
	stack_push(b, second);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size)
		stack_push(a, stack_pop(b));
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size)
		stack_push(b, stack_pop(a));
}