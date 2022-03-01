/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:09:44 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/01 17:24:23 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_struct_piece(t_piece *f)
{
	f->pc = NULL;
	f->w = 0;
	f->h = 0;
	f->star = 0;
}

void	init_struct_map(t_map *f)
{
	f->map = NULL;
	f->heat_map = NULL;
	f->my_letter = 0;
	f->enem_letter = 0;
	f->w = 0;
	f->h = 0;
	f->sy = 0;
	f->sx = 0;
	f->y = 0;
	f->x = 0;
	f->tempy = 0;
	f->tempx = 0;
	f->mainy = 0;
	f->mainx = 0;
	f->score = 0;
	f->moves = 0;
}

int	ft_str_valid(char *str, char *symbols)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(symbols, str[i]))
			return (0);
		i++;
	}
	return (1);
}

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

	x = 0;
	y = 0;
	while (y < board->h)
	{
		while (x < board->w)
		{
			if (board->heat_map[y][x] == DE)
				init_heat_map(board, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
