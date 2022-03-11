/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:58:05 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/07 14:12:03 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*	counting score first is checking boundaries 
second is checking if the xy space is not taken by me or enemy
last one is counting how effective it would be */
int	possible_point(t_map *b, int y, int x, int *score)
{
	if (b->mainy + y - b->tempy < 0 || b->mainy + y - b->tempy >= b->h || \
		b->mainx + x - b->tempx < 0 || b->mainx + x - b->tempx >= b->w)
		return (1);
	if (b->heat_map[b->mainy + y - b->tempy][b->mainx + x - b->tempx] == ENEM ||
			b->heat_map[b->mainy + y - b->tempy][b->mainx + x - b->tempx] == ME)
	{
		if (y != b->tempy || x != b->tempx)
			return (1);
	}
	if (b->heat_map[b->mainy + y - b->tempy][b->mainx + x - b->tempx] != ME)
	{
		*score += b->heat_map[b->mainy + y - b->tempy][b->mainx + x - b->tempx];
	}
	return (0);
}

/* counting score going backwards */
int	result_back(t_map *b, t_piece *piece, int *score)
{
	int	y;
	int	x;

	y = b->y;
	x = b->x;
	b->tempy = y;
	b->tempx = x;
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (piece->pc[y][x] == '*')
			{
				if (possible_point(b, y, x, score) == 1)
					return (1);
			}
			x--;
		}
		y--;
		x = piece->w - 1;
	}
	return (0);
}

/* counting score going forward */
int	result_forward(t_map *b, t_piece *piece, int *score)
{
	int	y;
	int	x;

	y = b->y;
	x = b->x;
	b->tempy = y;
	b->tempx = x;
	while (y < piece->h)
	{
		while (x < piece->w)
		{
			if (piece->pc[y][x] == '*')
			{
				if (possible_point(b, y, x, score) == 1)
					return (1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

/* if counted score is less than current score
we assign it because less score means it's closer to enemy*/
int	scoring(t_map *board, t_piece *piece)
{
	int	score;

	board->y = 0;
	board->x = 0;
	while (piece_search(piece, &board->y, &board->x) == 1)
	{
		score = 0;
		if (result_back(board, piece, &score) == 0 && \
				result_forward(board, piece, &score) == 0)
			score_set(board, score);
	}
	if (board->score == 0)
	{
		board->score = board->score0;
		board->sy = board->sy0;
		board->sx = board->sx0;
	}
	return (1);
}

int	count_score(t_map *board, t_piece *piece)
{
	board->mainy = 0;
	board->mainx = 0;
	board->sy = 0;
	board->sx = 0;
	board->sy0 = 0;
	board->sx0 = 0;
	board->score0 = 0;
	board->score = 0;
	have_moves(board);
	while (board->mainy < board->h)
	{
		while (board->mainx < board->w)
		{
			if (board->heat_map[board->mainy][board->mainx] == ME)
				scoring(board, piece);
			board->mainx++;
		}
		board->mainx = 0;
		board->mainy++;
	}
	return (1);
}
