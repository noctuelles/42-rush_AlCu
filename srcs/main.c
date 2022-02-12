/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:50:45 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/12 12:50:04 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlCu.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	throw_error(t_game *game)
{
	ft_putstr_fd(STR_ERROR, STDERR);
	ft_lstclear(&game->lines, free);
	free(game->board);
	if (game->fd != 0)
		close(game->fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (parse_map(&game, argc, argv) == 0) 
		return (throw_error(&game));
	for (t_index i = 0; i < game.board_size; i++)
		printf("%d\n", game.board[i]);
	return (0);
}
