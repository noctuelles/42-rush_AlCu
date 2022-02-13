/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:23:27 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/13 14:37:38 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "AlCu.h"
#include <unistd.h>

static unsigned int	find_biggest(t_game game)
{
	t_index			i;
	unsigned int	biggest;

	i = 0;
	biggest = game.board[i++];
	while (i <= game.curr_heap)
	{
		if (game.board[i] > biggest)
			biggest = game.board[i];
		i++;
	}
	return (biggest);
}

static void	put_elem(unsigned int nbr)
{
	t_index	i;

	i = 0;
	while (i < nbr - 1)
	{
		write(STDOUT, STR_ELEM1, sizeof(STR_ELEM1) - 1);
		i++;
	}
	write(STDOUT, STR_ELEM2, sizeof(STR_ELEM2) - 1);
}

void	display_board(t_game game)
{
	t_index	i;
	int		biggest;
	int		value;
	size_t	nbr_space;

	i = 0;
	biggest = find_biggest(game);
	while (i <= game.curr_heap)
	{
		value = game.board[i];
		nbr_space = biggest - value;
		while (nbr_space-- != 0) 
			write(STDOUT, STR_SPACE, 1);
		put_elem(value);
		i++;
	}
}
