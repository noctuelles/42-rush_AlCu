/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:05:51 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/13 14:42:54 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlCu.h"
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* check_line() checks if the line we're scanning is following the subject
 * rules. */

unsigned int	check_line(const char *str)
{
	unsigned int	nbr;
	t_index			i;
	size_t			line_len;

	line_len = ft_strlen(str);
	if (line_len <= 1 || line_len > 6)
		return (0);
	i = 0;
	while (ft_isdigit(str[i]) || str[i] == '\n')
		i++;
	if (i != line_len)
		return (0);
	nbr = ft_atoi(str);
	if (nbr <= 0 || nbr > 10000)
		return (0);
	else
		return (nbr);
}

static int	fill_board_from_list(t_game *game)
{
	t_list	*elem;
	t_index	i;
	int		nbr;

	game->board_size = ft_lstsize(game->lines);
	if (game->board_size == 0)
		return (0);
	game->board = (unsigned int *) malloc(game->board_size
			* sizeof (unsigned int));
	if (!game->board)
		return (0);
	elem = game->lines;
	i = 0;
	while (elem)
	{
		nbr = check_line((const char *) elem->content);
		if (nbr == 0)
			return (0);
		game->board[i] = nbr;
		elem = elem->next;
		i++;
	}
	return (1);
}

static int	parse_from_stdin(t_game *game)
{
	char	*line;
	t_list	*elem;
	t_bool	is_ok;

	is_ok = FALSE;
	game->fd = STDIN;
	while ((line = get_next_line(game->fd)))
	{
		if (line[0] == '\n' && line[1] == '\0')
		{
			free(line);
			is_ok = TRUE;
			break ;
		}
		elem = ft_lstnew(line);
		if (!elem)
		{
			free(line);
			return (0);
		}
		ft_lstadd_back(&game->lines, elem); 
	}
	close(STDIN);
	game->fd_stdin = open("/dev/tty", O_RDONLY);
	if (game->fd_stdin == -1)
		return (0);
	if (!is_ok || fill_board_from_list(game) == 0)
		return (0);
	else
		return (1);
}

static int	parse_from_file(t_game *game, const char *path)
{
	char	*line;
	t_list	*elem;

	game->fd = open(path, O_RDONLY);
	if (game->fd == -1)
		return (0);
	while ((line = get_next_line(game->fd)))
	{
		elem = ft_lstnew(line);
		if (!elem)
		{
			free(line);
			return (0);
		}
		ft_lstadd_back(&game->lines, elem); 
	}
	game->fd_stdin = STDIN;
	if (fill_board_from_list(game) == 0)
		return (0);
	else
		return (1);
}

int	parse_map(t_game *game, int argc, char **argv)
{
	if (argc == 1)
		return (parse_from_stdin(game));
	else if (argc == 2)
		return (parse_from_file(game, argv[1]));
	else
		return (0);
}
