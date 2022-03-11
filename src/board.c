/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:35:26 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/07 14:20:37 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_board_size(t_map *board)
{
	char	**board_size;
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (0);
	board_size = ft_strsplit(line, ' ');
	if (!board_size)
		return (free_data_error(NULL, NULL, "strsplit error\n"));
	ft_strdel(&line);
	if (ft_strcmp("Plateau", board_size[0]) || !ft_strisnumeric(board_size[1])
		|| !ft_isdigit(board_size[2][0]) || board_size[3])
	{
		ft_free2d((void *)board_size);
		return (free_data_error(board, NULL, "Wrong board size\n"));
	}
	board->h = ft_atoi(board_size[1]);
	board->w = ft_atoi(board_size[2]);
	ft_free2d((void *)board_size);
	return (1);
}

int	get_board(t_map *board)
{
	char	*line;
	int		i;

	if (!get_board_size(board))
		return (0);
	if (get_next_line(0, &line) <= 0)
		return (0);
	ft_strdel(&line);
	if (!board->map)
		board->map = ft_memalloc(sizeof(char *) * (board->h + 1));
	if (!board->map)
		return (free_data_error(board, NULL, "Allocation failed\n"));
	i = -1;
	while (++i < board->h)
	{
		if (get_next_line(0, &line) <= 0)
			return (free_data_error(board, NULL, "GNL failed\n"));
		board->map[i] = ft_strsub(line, 4, board->w);
		ft_strdel(&line);
		if (ft_strlen(board->map[i]) != (size_t)(board->w))
			return (free_data_error(board, NULL, "Board lines not right\n"));
		if (!ft_str_valid(board->map[i], ".oOxX"))
			return (free_data_error(board, NULL, "Wrong symbols in map\n"));
	}
	return (1);
}
