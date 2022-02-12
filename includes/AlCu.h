/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlCu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:50:36 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/12 12:28:24 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "libft.h"

# define STR_ERROR "ERROR\n"

typedef struct s_game
{
	int		*board;
	size_t	board_size;
	t_list	*lines;
	int		fd;
	t_bool	err_set;
	t_index	curr_heap;
}				t_game;

int	throw_error(t_game *game);
int	parse_map(t_game *game, int argc, char **argv);

#endif
