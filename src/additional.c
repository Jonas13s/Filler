/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:36:29 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/07 01:06:28 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_tab_char(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i] != NULL)
		free((*tab)[i++]);
	free(*tab);
}

void	score_set(t_map *b, int score)
{
	if (b->moves == 1)
	{
		if ((score <= b->score && score > 0) || (score > 0 && b->score == 0))
		{
			b->score = score;
			b->sy = b->mainy - b->y;
			b->sx = b->mainx - b->x;
		}
		else
		{
			b->score0 = score;
			b->sy0 = b->mainy - b->y;
			b->sx0 = b->mainx - b->x;
		}
	}
	else
	{
		if (score < b->score || b->score == 0)
		{
			b->score = score;
			b->score0 = score;
			b->sy0 = b->mainy - b->y;
			b->sx0 = b->mainx - b->x;
		}
	}
}

void	have_moves(t_map *board)
{
	board->moves = 0;
	while (board->mainy < board->h)
	{
		while (board->mainx < board->w)
		{
			if (board->heat_map[board->mainy][board->mainx] > 0)
				board->moves = 1;
			board->mainx++;
		}
		board->mainx = 0;
		board->mainy++;
	}
	board->mainx = 0;
	board->mainy = 0;
}
