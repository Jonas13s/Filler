/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:51:06 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/01 13:51:28 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_piece_wh(t_piece *piece)
{
	char	**piece_size;
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (free_data_error(NULL, NULL, "GNL error\n"));
	piece_size = ft_strsplit(line, ' ');
	if (!(piece_size))
		return (free_data_error(NULL, NULL, "strsplit error\n"));
	ft_strdel(&line);
	if (ft_strcmp("Piece", piece_size[0]) || !ft_strisnumeric(piece_size[1])
		|| !ft_isdigit(piece_size[2][0]) || piece_size[3])
	{
		ft_free2d((void **)piece_size);
		return (free_data_error(NULL, NULL, "Wrong piece size\n"));
	}
	piece->h = ft_atoi(piece_size[1]);
	piece->w = ft_atoi(piece_size[2]);
	ft_free2d((void **)piece_size);
	return (1);
}

int	read_piece(t_piece *piece)
{
	int		i;

	if (piece->h == 0 || piece->w == 0)
		return (0);
	i = 0;
	piece->pc = ft_memalloc(sizeof(char *) * (piece->h + 2));
	if (!piece->pc)
		return (0);
	while (i < piece->h)
	{
		if (get_next_line(0, &piece->pc[i]) <= 0)
			return (free_data_error(NULL, NULL, "GNL error\n"));
		if (ft_strlen(piece->pc[i]) != (size_t)piece->w)
			return (free_data_error(NULL, NULL, "Piece size is wrong\n"));
		if (!ft_str_valid(piece->pc[i], ".*"))
			return (free_data_error(NULL, NULL, "Piece has wrong symbols\n"));
		i++;
	}
	return (1);
}

int	get_piece(t_piece *piece)
{
	if (!get_piece_wh(piece))
		return (0);
	if (!read_piece(piece))
		return (0);
	return (1);
}
