/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:51:06 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/07 01:03:21 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*	Gathering piece width and height from stdout
Has one flaw that if width has at the end has symbols it wont register them
and it will be considered as good piece
Using 'ft_strsplit' I split given data and then I just pass
numbers to 'ft_atoi' which assigns numbers to struct	*/
static int	get_piece_wh(t_piece *piece, t_map *board)
{
	char	**piece_size;
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (free_data_error(board, NULL, "GNL error\n"));
	piece_size = ft_strsplit(line, ' ');
	if (!(piece_size))
		return (free_data_error(board, NULL, "strsplit error\n"));
	ft_strdel(&line);
	if (ft_strcmp("Piece", piece_size[0]) || !ft_strisnumeric(piece_size[1])
		|| !ft_isdigit(piece_size[2][0]) || piece_size[3])
	{
		ft_free2d((void **)piece_size);
		return (free_data_error(board, NULL, "Wrong piece size\n"));
	}
	piece->h = ft_atoi(piece_size[1]);
	piece->w = ft_atoi(piece_size[2]);
	ft_free2d((void **)piece_size);
	return (1);
}

/*	After succesfully reading first line which has width and height
I read stdout same amount of time that was piece height was given
if piece is wrong I call it as wrong piece considering:'width, symbols'	*/
static int	read_piece(t_piece *piece, t_map *board)
{
	int		i;

	if (piece->h == 0 || piece->w == 0)
		return (free_data_error(board, NULL, "Piece has invalid W or H\n"));
	i = 0;
	if (!piece->pc)
		piece->pc = ft_memalloc(sizeof(char *) * (piece->h + 2));
	if (!piece->pc)
		return (free_data_error(board, NULL, "Allocation failed\n"));
	while (i < piece->h)
	{
		if (get_next_line(0, &piece->pc[i]) <= 0)
			return (free_data_error(board, piece, "GNL error\n"));
		if (ft_strlen(piece->pc[i]) != (size_t)piece->w)
			return (free_data_error(board, piece, "Piece size is wrong\n"));
		if (!ft_str_valid(piece->pc[i], ".*"))
			return (free_data_error(board, piece, "Piece has wrong symbols\n"));
		i++;
	}
	return (1);
}

/*	Function which calls two additional functions, if any of these malfunction
Filler is stopped and all data is wiped in previous functions	*/
int	get_piece(t_piece *piece, t_map *board)
{
	if (!get_piece_wh(piece, board))
		return (0);
	if (!read_piece(piece, board))
		return (0);
	return (1);
}

/*	Checking boundaries and moving it up once so either x or y	*/
static int	piece_start(t_piece *piece, int *y, int *x)
{
	if (piece->star == 1)
	{
		piece->star = 0;
		if (*x + 1 < piece->w)
			(*x)++;
		else if (*y + 1 < piece->h)
		{
			(*y)++;
			*x = 0;
		}
		else
			return (0);
	}
	return (1);
}

/*	seraching if piece has still stars in if and if so returns their cords	*/
int	piece_search(t_piece *piece, int *y, int *x)
{
	if (piece_start(piece, y, x) == 0)
		return (0);
	if (*x == 0 && *y == 0 && piece->pc && piece->pc[*y][*x] == '*')
	{
		piece->star = 1;
		return (1);
	}
	else
	{
		while (*y < piece->h)
		{
			while (*x < piece->w)
			{
				if (piece->pc && piece->pc[*y][*x] == '*')
				{
					piece->star = 1;
					return (1);
				}
				(*x)++;
			}
			*x = 0;
			(*y)++;
		}
	}
	return (0);
}
