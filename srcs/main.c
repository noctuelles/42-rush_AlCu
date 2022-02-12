/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:50:45 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/12 16:09:22 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlCu.h"
#include "libft.h"

int	throw_error(t_game *game)
{
	ft_putstr_fd(STR_ERROR, STDERR);
	free_game(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (parse_map(&game, argc, argv) == 0) 
		return (throw_error(&game));
	//printf("werwer %zu\n", game.board_size);
	game.curr_player = AI;
	game.curr_heap = game.board_size - 1;
	while (game_loop(&game))
		;
	if (game.exit_game == FALSE)
		display_winner(game.winner);
	//display_board(game);
	return (0);
}
