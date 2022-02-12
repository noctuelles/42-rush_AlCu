/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:22:49 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/12 19:01:02 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlCu.h"
#include "libft.h"
#include <assert.h>

static int change_decision(int nb)
{
	if (nb == 0)
		return (1);
	else
		return (0);
}

static int	get_rand_action(int *action)
{
	const char	*str_alea = STR_ALEA;
	static int	alea = 23;
	
	if (alea == sizeof(STR_ALEA) - 1)
		alea = 0;
	*action = str_alea[alea++] - '0';
	return (*action);
}

int get_ai_input(t_game *game)
{
	int			i;
	int			action;
	int			decision;
	
	i = 0;
	decision = 1;
	while (i < game->curr_heap - 1)
	{
		if (game->board[i] % 4 == decision)
			decision = change_decision(decision);
		i++;
	}
	i = game->curr_heap;
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
