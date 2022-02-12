/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlCu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:50:36 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/12 16:09:24 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "libft.h"

# define STR_ERROR "ERROR\n"
# define STR_ELEM1 "| "
# define STR_ELEM2 "|\n"
# define STR_SPACE " "
# define STR_CYAN "{96}"
# define STR_RST "{0}\n"
# define STR_CHOICE "\n{93;4}Please choose between 1 and 3 items.{0}\n\n"
# define STR_CHOICE_INV "{1;96}%s{0} - {31}Invalid choice.{0}\n"
# define STR_HUMAN_LOOSE "{31}The human race has been defeated ! You lost.\n{0}"
# define STR_HUMAN_WIN "{93}Congratulation ! Human race is still clever.\n{0}"
# define STR_EXIT "You're fleeing ! Goodbye...\n"
# define STR_CLR_SCREEN "\033[H\033[J"

typedef enum e_player
{
	AI=0,
	HUMAN=1
}				t_player;

typedef struct s_game
{
	int			*board;
	size_t		board_size;
	t_list		*lines;
	t_bool		exit_game;
	int			fd;
	int			action;
	t_sindex	curr_heap;
	t_player	curr_player;
	t_player	winner;
}				t_game;

/* main.c */

int	throw_error(t_game *game);

/* parsing.c */

int	check_line(const char *str);
int	parse_map(t_game *game, int argc, char **argv);

/* display.c */ 

void	display_board(t_game game);

/* game.c */

void	display_winner(t_player winner);
t_bool	game_loop(t_game *game);
void	free_game(t_game *game);

#endif
