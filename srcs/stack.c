/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by msousa            #+#    #+#             */
/*   Updated: 2022/01/05 15:40:55 by msousa           ###   ########.fr       */
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

void	*stack_pop(t_stack *stack)
{
	t_list	*head;
	void	*content;

	if (!stack->head)
		return (NULL);
	head = stack->head;
	content = head->content;
	stack->head = head->next;
	stack->size--;
	free(head);
	return (content);
}

void	stack_shift(t_stack *stack, void *content)
{
	t_list	*tail;

	tail = ft_lstlast(stack->head);
	tail->next = ft_lstnew(content);
	stack->size++;
}

void	*stack_unshift(t_stack *stack)
{
	t_list	*last;
	t_list	*before;
	void	*content;

	if (!stack->head)
		return (NULL);
	last = ft_lstlast(stack->head);
	content = last->content;
	if (stack->size > 1)
	{
		before = ft_lstat(stack->head, stack->size - 2);
		before->next = NULL;
	}
	stack->size--;
	free(last);
	return (content);
}
