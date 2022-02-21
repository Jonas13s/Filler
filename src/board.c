/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:35:26 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/20 23:51:23 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_board_size(t_map *board)
{
	char **board_size;
	char *line;

	if(get_next_line(0, &line) <= 0)
		return (0); // kill here
	if(!(board_size = ft_strsplit(line, ' ')))
		return (0); // kill here
	ft_strdel(&line);
	if (ft_strcmp("Plateau", board_size[0]) || !ft_strisnumeric(board_size[1])
	|| !ft_isdigit(board_size[2][0]) || board_size[3])
	{
		ft_free2d(board_size);
		return (0); // kill here
	}
	board->h = ft_atoi(board_size[1]);
	board->w = ft_atoi(board_size[2]);
	ft_free2d(board_size);
	return (1);
}

int	get_board(t_map *board)
{
	char	*line;
	int		i;

	if (!get_board_size(board))
		return (0); // kill here
	if (get_next_line(0, &line) <= 0)
		return (0); // kill here
	ft_strdel(&line);
	board->map = ft_memalloc(sizeof(char *) * (board->h + 1));
	if (!board->map)
		return (0); // kill here
	i = 0;
	while(i < board->h)
	{
		if (get_next_line(0, &line) <= 0)
			return (0); // kill here
		board->map[i] = ft_strsub(line, 4, board->w);
		if (ft_strlen(board->map[i]) != (size_t)(board->w))
			return (0); // kill here
		if (!ft_str_valid(board->map[i], ".oOxX"))
			return (0); // kill here
		ft_strdel(&line);
		i++;
	}
	return (1);
}