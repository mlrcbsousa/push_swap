/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:31:24 by msousa            #+#    #+#             */
/*   Updated: 2022/01/05 18:58:26 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
  if (a->size > 1 && b->size > 1)
  {
    ft_putendl("rr");
    rotate(a);
    rotate(b);
  }
  else
  {
    ra(a, b);
    rb(a, b);
  }
}

void	rra(t_stack *a, t_stack *b)
{
  (void)b;
  if (a->size > 1)
  {
    ft_putendl("rra");
    reverse_rotate(a);
  }
}

void	rrb(t_stack *a, t_stack *b)
{
  (void)a;
  if (b->size > 1)
  {
    ft_putendl("rrb");
    reverse_rotate(b);
  }
}

void	rrr(t_stack *a, t_stack *b)
{
  if (a->size > 1 && b->size > 1)
  {
    ft_putendl("rrr");
    reverse_rotate(a);
    reverse_rotate(b);
  }
  else
  {
    rra(a, b);
    rrb(a, b);
  }
}
