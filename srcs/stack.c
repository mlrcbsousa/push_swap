/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by msousa            #+#    #+#             */
/*   Updated: 2022/01/26 19:55:30 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Stack#push is same as Array#shift
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

int	stack_median(t_stack *stack)
{
	t_list		*dup;
	t_list		*tmp;
	int		middle;
	int		median;

	dup = ft_lstdup(stack->head);
	middle = stack->size / 2;
	ft_lstsort(dup, 0, stack->size - 1);
	tmp = dup;
	while (middle--)
		tmp = tmp->next;
	median = *(int *)tmp->content;
	ft_lstclear(&dup, free);
	return (median);
}
