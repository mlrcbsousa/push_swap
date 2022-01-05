/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:31:24 by msousa            #+#    #+#             */
/*   Updated: 2022/01/05 18:55:19 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	(void)b;
  if (a->size > 1)
  {
    ft_putendl("sa");
    swap(a);
  }
}

void	sb(t_stack *a, t_stack *b)
{
  (void)a;
  if (b->size > 1)
  {
    ft_putendl("sb");
    swap(b);
  }
}

void	ss(t_stack *a, t_stack *b)
{
  if (a->size > 1 && b->size > 1)
  {
    ft_putendl("ss");
    swap(a);
    swap(b);
  }
  else
  {
    sa(a, b);
    sb(a, b);
  }
}

void	ra(t_stack *a, t_stack *b)
{
	(void)b;
  if (a->size > 1)
  {
    ft_putendl("ra");
    rotate(a);
  }
}

void	rb(t_stack *a, t_stack *b)
{
  (void)a;
  if (b->size > 1)
  {
    ft_putendl("rb");
    rotate(b);
  }
}
