/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:00:42 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/07 14:20:53 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

/*
if any of these are wrong it's error
which_player == 0 it means it was defined which player it is
*/
static int	data(t_map *board, t_piece *piece)
{
	if (!board->my_letter)
		which_player(board);
	if (!board->my_letter)
		return (0);
	if (!get_board(board))
		return (0);
	if (!get_piece(piece, board))
		return (0);
	if (!create_heat_map(board, piece))
		return (0);
	init_heat(board);
	return (1);
}

int	main(void)
{
	t_map	board;
	t_piece	piece;

	ft_bzero(&board, sizeof(board));
	ft_bzero(&piece, sizeof(piece));
	while (1)
	{
		if (!data(&board, &piece))
			return (0);
		do_heat(&board);
		count_score(&board, &piece);
		ft_printf("%d %d\n", board.sy, board.sx);
		free_data(&board, &piece);
	}
	return (0);
}
