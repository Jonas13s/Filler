/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:09:44 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/06 23:52:32 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_heat_map(t_map *b, int x, int y)
{
	if (x + 1 < b->w && b->heat_map[y][x + 1] == ENEM)
		b->heat_map[y][x] = 1;
	if (y + 1 < b->h && b->heat_map[y + 1][x] == ENEM)
		b->heat_map[y][x] = 1;
	if (y + 1 < b->h && x + 1 < b->w && b->heat_map[y + 1][x + 1] == ENEM)
		b->heat_map[y][x] = 1;
	if (y - 1 >= 0 && x + 1 < b->w && b->heat_map[y - 1][x + 1] == ENEM)
		b->heat_map[y][x] = 1;
	if (y + 1 < b->h && x - 1 >= 0 && b->heat_map[y + 1][x - 1] == ENEM)
		b->heat_map[y][x] = 1;
	if (y - 1 >= 0 && x - 1 >= 0 && b->heat_map[y - 1][x - 1] == ENEM)
		b->heat_map[y][x] = 1;
	if (y - 1 >= 0 && b->heat_map[y - 1][x] == ENEM)
		b->heat_map[y][x] = 1;
	if (x - 1 >= 0 && b->heat_map[y][x - 1] == ENEM)
		b->heat_map[y][x] = 1;
}

void	init_heat(t_map *board)
{
	int	x;
	int	y;

	y = -1;
	while (++y < board->h)
	{
		x = -1;
		while (++x < board->w)
		{
			if (board->heat_map[y][x] == DE)
				init_heat_map(board, x, y);
		}
	}
}

/* Getting info for which player I'm it's gonna be ran
only once at the start of the game when the VM is called */
int	which_player(t_map *board)
{
	char	*line;
	char	*pos;
	char	c;

	if (get_next_line(0, &line) <= 0)
		return (free_data_error(NULL, NULL, "Allocation failed\n"));
	pos = ft_strchr(line, 'p') + 1;
	c = *pos;
	ft_strdel(&line);
	if (c == '1')
	{
		board->my_letter = 'O';
		board->enem_letter = 'X';
		return (1);
	}
	else if (c == '2')
	{
		board->my_letter = 'X';
		board->enem_letter = 'O';
		return (1);
	}
	else
		return (free_data_error(NULL, NULL, "No player detected\n"));
	return (1);
}
