/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:31:24 by msousa            #+#    #+#             */
/*   Updated: 2021/12/05 12:44:43 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	(void)b;
	swap(a);
}

void	sb(t_stack *a, t_stack *b)
{
	(void)a;
	swap(b);
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
	pa(b, a);
}