/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:09:14 by msousa            #+#    #+#             */
/*   Updated: 2021/11/19 20:11:57 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(void)
{
	ft_putendl_fd("Error", STDERR);
	exit(EXIT_FAILURE);
}

static t_bool	valid(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
		if (!ft_isnumber(argv[i++]))
			return (FALSE);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	if (!valid(argc - 1, &argv[1]))
		error();
	// build A with ARGS and empty B
	// decide which sort algorithm to choose
	// sort while printing each operation
	return (0);
}