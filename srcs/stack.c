/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by msousa            #+#    #+#             */
/*   Updated: 2021/11/28 23:59:07 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// procedure push(stk : stack, x : item):
//     newhead ← new frame
//     newhead.data ← x
//     newhead.next ← stk.head
//     stk.head ← newhead
//     stk.size ← stk.size + 1

void	stack_push(t_stack *stack, void *content)
{
	t_list	*head;

	printf("stack_push %d\n", *(int *)content);
	head = ft_lstnew(content);
	head->next = stack->head;
	stack->head = head;
	stack->size++;
}