/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by msousa            #+#    #+#             */
/*   Updated: 2021/12/03 19:37:32 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *stack, void *content)
{
	t_list	*head;

	head = ft_lstnew(content);
	head->next = stack->head;
	stack->head = head;
	stack->size++;
}

t_list	*stack_pop(t_stack *stack)
{
	t_list	*head;
	
	if (!stack->head)
		return (NULL);
	head = stack->head;
	stack->head = head->next;
	stack->size--;
	head->next = NULL;
	return (head);
}