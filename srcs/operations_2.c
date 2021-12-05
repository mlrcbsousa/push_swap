/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:31:24 by msousa            #+#    #+#             */
/*   Updated: 2021/12/05 12:35:37 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_stack *b)
{
	void	*content;

	(void)b;
	content = stack_pop(a);
	ft_lstadd_back(&a->head, ft_lstnew(content));
	a->size++;
	

	// first = stack_pop(b);
	// second = stack_pop(b);
	// stack_push(b, first);
	// stack_push(b, second);
	

	// t_list	*ft_lstnew(void *content);
	// void	ft_lstadd_back(t_list **lst, t_list *new);

	
}

// void	rb(t_stack *a, t_stack *b)
// {
	
// }

// void	rr(t_stack *a, t_stack *b)
// {
	
// }
