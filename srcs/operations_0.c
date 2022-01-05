/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:39:45 by msousa            #+#    #+#             */
/*   Updated: 2022/01/05 18:25:50 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	void	*first;
	void	*second;

	if (stack->size < 2)
		return ;
	first = stack_pop(stack);
	second = stack_pop(stack);
	stack_push(stack, first);
	stack_push(stack, second);
}

void	rotate(t_stack *stack)
{
	void	*content;

	content = stack_pop(stack);
	if (content)
		stack_shift(stack, content);
}

void	reverse_rotate(t_stack *stack)
{
	void	*content;

	content = stack_unshift(stack);
	if (content)
		stack_push(stack, content);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size)
  {
    ft_putendl("pa");
    stack_push(a, stack_pop(b));
  }
}

void	pb(t_stack *a, t_stack *b)
{
  if (a->size)
  {
    ft_putendl("pb");
    stack_push(b, stack_pop(a));
  }
}
