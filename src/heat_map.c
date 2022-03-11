/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:41:48 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/07 13:42:42 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*	Filling map in basically checking everything around and
just making it bigger if it's more far away from the enemy	*/
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

/*	Filling heat_map if it's dot its gonna be DE(empty)
or ME(mine) also ENEM(taken) this is only for one row	*/
static int	filling_heat_map(t_map *board, int y)
{
	int	x;

	x = -1;
	while (++x < board->w)
	{
		if (board->map[y][x] == '.')
			board->heat_map[y][x] = DE;
		if (board->map[y][x] == board->my_letter ||
				board->map[y][x] == ft_tolower(board->my_letter))
			board->heat_map[y][x] = ME;
		if (board->map[y][x] == board->enem_letter)
			board->heat_map[y][x] = ENEM;
	}
	return (1);
}

/*	Checking map row by row and increasing
their value by using fill_heat()
DE = empty box	*/

void	do_heat(t_map *board)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (++i < board->w)
	{
		y = -1;
		while (++y < board->h)
		{
			x = -1;
			while (++x < board->w)
			{
				if (board->heat_map[y][x] == DE)
					fill_heat(board, x, y, i);
			}
		}
	}
}

/*	allocating also filling heat map
this passes row to filling_heat_map() which then assigns data
using map that was given from VM	*/
int	create_heat_map(t_map *board, t_piece *piece)
{
	int	y;

	if (!board->heat_map)
		board->heat_map = ft_memalloc(sizeof(char *) * (board->h + 1));
	if (!board)
		return (free_data_error(board, piece, "Allocation failed\n"));
	y = -1;
	while (++y < board->h)
	{
		board->heat_map[y] = ft_memalloc(sizeof(char *) * (board->w + 1));
		if (!board->heat_map[y])
			return (free_data_error(board, piece, "Allocation failed\n"));
		filling_heat_map(board, y);
	}
	return (1);
}
