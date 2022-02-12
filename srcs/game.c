/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:04:47 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/12 19:16:30 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlCu.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

void	free_game(t_game *game)
{
	game->exit_game = TRUE;
	ft_lstclear(&game->lines, free);
	free(game->board);
	close(game->fd);
	if (game->fd_stdin != 0)
		close(game->fd_stdin);
}

static t_bool	continue_game(t_game *game)
{
	if (game->action != 0)
	{
		game->board[game->curr_heap] -= game->action; 
		if (game->board[game->curr_heap] == 0)
			game->curr_heap--;
	}
	if (game->curr_heap == -1)
	{
		game->winner = game->curr_player;
		return (FALSE);
	}
	else
		return (TRUE);
}

static int	get_user_input(t_game *game)
{
	const char	*line;
	char		*nw;
	int			nbr;

	ft_printf(STR_CHOICE);
	ft_printf(STR_CYAN);
	line = (const char *) get_next_line(game->fd_stdin);
	ft_printf(STR_RST);
	if (!line)
		return (0);
	nbr = check_line(line);
	if (nbr == 0 || nbr > 3 || nbr > game->board[game->curr_heap])
	{
		nw = ft_strchr(line, '\n');
		*nw = '\0';
		ft_printf(STR_CHOICE_INV, (char *) line);
		free((void *) line);
		return (get_user_input(game));
	}
	else
	{
		free((void *) line);
		return (nbr);
	}
}

t_bool	game_loop(t_game *game)
{
	write(STDOUT, STR_NWL, 1);
	display_board(*game);
	if (game->curr_player == AI)
	{
		game->action = get_ai_input(game);
		ft_printf(STR_AI_PLAY, game->action);
		game->curr_player = HUMAN; 
	}
	else if (game->curr_player == HUMAN)
	{
		game->action = get_user_input(game);
		if (game->action == 0)
		{
			ft_putstr(STR_EXIT);
			free_game(game);
			return (FALSE);
		}
		game->curr_player = AI;
	}
	return(continue_game(game));
}

void	display_winner(t_player winner)
{
	if (winner == AI)
		ft_printf(STR_HUMAN_LOOSE);
	else if (winner == HUMAN)
		ft_printf(STR_HUMAN_WIN);
}
