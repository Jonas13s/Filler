/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:41:48 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/01 18:00:34 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fill_heat(t_map *b, int x, int y, int i)
{
	if (x + 1 < b->w && b->heat_map[y][x + 1] == i)
		b->heat_map[y][x] = i + 1;
	if (y + 1 < b->h && b->heat_map[y + 1][x] == i)
		b->heat_map[y][x] = i + 1;
	if (y + 1 < b->h && x + 1 < b->w && b->heat_map[y + 1][x + 1] == i)
		b->heat_map[y][x] = i + 1;
	if (y - 1 >= 0 && x + 1 < b->w && b->heat_map[y - 1][x + 1] == i)
		b->heat_map[y][x] = i + 1;
	if (y + 1 < b->h && x - 1 >= 0 && b->heat_map[y + 1][x - 1] == i)
		b->heat_map[y][x] = i + 1;
	if (y - 1 >= 0 && x - 1 >= 0 && b->heat_map[y - 1][x - 1] == i)
		b->heat_map[y][x] = i + 1;
	if (y - 1 >= 0 && b->heat_map[y - 1][x] == i)
		b->heat_map[y][x] = i + 1;
	if (x - 1 >= 0 && b->heat_map[y][x - 1] == i)
		b->heat_map[y][x] = i + 1;
}

void	do_heat(t_map *board)
{
	int	x;
	int	y;
	int	i;

	i = 1;
	while (i < board->w)
	{
		y = 0;
		x = 0;
		while (y < board->h)
		{
			while (x < board->w)
			{
				if (board->heat_map[y][x] == DE)
					fill_heat(board, x, y, i);
				x++;
			}
			x = 0;
			y++;
		}
		i++;
	}
}

static int	filling_heat_map(t_map *board, int y)
{
	int	x;

	x = 0;
	while (x < board->w)
	{
		if (board->map[y][x] == '.')
			board->heat_map[y][x] = DE;
		if (board->map[y][x] == board->my_letter ||
			board->map[y][x] == ft_tolower(board->my_letter))
		board->heat_map[y][x] = ME;
		if (board->map[y][x] == board->enem_letter)
			board->heat_map[y][x] = ENEM;
		x++;
	}
	return (1);
}

int	create_heat_map(t_map *board, t_piece *piece)
{
	int	y;

	y = 0;
	board->heat_map = ft_memalloc(sizeof(char *) * (board->h + 1));
	if (!board)
		return (free_data_error(board, piece, "Allocation failed\n"));
	while (y < board->h)
	{
		board->heat_map[y] = ft_memalloc(sizeof(char *) * (board->w + 1));
		if (!board->heat_map[y])
			return (free_data_error(board, piece, "Allocation failed\n"));
		filling_heat_map(board, y);
		y++;
	}
	return (1);
}
