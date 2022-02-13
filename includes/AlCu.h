/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlCu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:50:36 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/13 15:16:43 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "libft.h"

# define STR_ALEA "133232121312132123123122312132132132133213212321323122131312332132121321332132133122311323213213123122132132321233122312311321231312312321231132131321312131221321313312312131213121312131213321322131231221312321321312323213121312"
# define STR_ERROR "ERROR\n"
# define STR_ELEM1 "| "
# define STR_ELEM2 "|\n"
# define STR_SPACE " "
# define STR_CYAN "{96}"
# define STR_RST "{0}\n"
# define STR_CHOICE "\n{93;4}Please choose between 1 and 3 items.{0}\n\n"
# define STR_CHOICE_INV "{1;96}%s{0} - {31}Invalid choice.{0}\n"
# define STR_HUMAN_LOOSE "{31;1;4}The human race has been defeated ! You lost.\n\n{0}"
# define STR_HUMAN_WIN "\n{93;1;4}Congratulation ! Human race is still clever.\n\n{0}"
# define STR_EXIT "{31}You're fleeing ! Goodbye...{0}\n"
# define STR_CLR_SCREEN "\033[H\033[J"
# define STR_AI_PLAY "\n{1;35}AI took %d.{0}\n"
# define STR_NWL "\n"

typedef enum e_player
{
	AI=0,
	HUMAN=1
}				t_player;

typedef struct s_game
{
	unsigned int	*board;
	size_t			board_size;
	t_list			*lines;
	t_bool			exit_game;
	int				fd;
	int				fd_stdin;
	int				action;
	t_index			curr_heap;
	t_player		curr_player;
	t_player		winner;
}				t_game;

/* main.c */

int				throw_error(t_game *game);

/* parsing.c */

unsigned int	check_line(const char *str);
int				parse_map(t_game *game, int argc, char **argv);

/* display.c */ 

void			display_board(t_game game);

/* game.c */

void			display_winner(t_player winner);
t_bool			game_loop(t_game *game);
void			free_game(t_game *game);

/* algo.c */

unsigned int	get_ai_input(t_game *game);

#endif
