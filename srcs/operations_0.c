/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:39:45 by msousa            #+#    #+#             */
/*   Updated: 2021/12/05 12:47:57 by msousa           ###   ########.fr       */
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
	if (!content)
		return ;
	ft_lstadd_back(&stack->head, ft_lstnew(content));
	stack->size++;
}

// void	reverse_rotate(t_stack *stack)
// {

// }