/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:22:49 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/13 14:48:28 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlCu.h"
#include "libft.h"

static unsigned int	change_decision(int nb)
{
	if (nb == 0)
		return (1);
	else
		return (0);
}

static unsigned int	get_rand_action(unsigned int *action)
{
	const char		*str_alea = STR_ALEA;
	static t_index	alea = 23;
	
	if (alea == sizeof(STR_ALEA) - 2)
		alea = 0;
	*action = str_alea[alea++] - '0';
	return (*action);
}

unsigned int	get_ai_input(t_game *game)
{
	t_index			i;
	unsigned int	action;
	unsigned int	decision;
	
	i = 0;
	decision = 1;
	while (i < game->curr_heap)
	{
		if (game->board[i] % 4 == decision)
			decision = change_decision(decision);
		i++;
	}
	action = 1 ;
	while (action < 4)
	{
		if ((game->board[i] - action) % 4 == decision && action <= game->board[i])
			return (action);
		action++;
	}
	while (get_rand_action(&action) > game->board[i])
		;
	return(action);
}
