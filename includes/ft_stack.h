/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:27:46 by msousa            #+#    #+#             */
/*   Updated: 2022/01/26 19:47:37 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef struct s_stack
{
	t_list	*head;
	int		size;
}	t_stack;

void	stack_push(t_stack *stack, void *content);
void	stack_shift(t_stack *stack, void *content);
void	*stack_pop(t_stack *stack);
void	*stack_unshift(t_stack *stack);
int		stack_median(t_stack *stack);

#endif