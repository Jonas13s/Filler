/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:16:21 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/01 17:57:51 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_data(t_map *board, t_piece *piece)
{
	ft_free2d((void **)board->map);
	ft_free2d((void **)board->heat_map);
	ft_free2d((void **)piece->pc);
}

int	free_data_error(t_map *board, t_piece *piece, char *string)
{
	if (piece)
		if (piece->pc)
			ft_free2d((void **)piece->pc);
	if (board)
	{
		if (board->map)
			ft_free2d((void **)board->map);
		if (board->heat_map)
			ft_free2d((void **)board->heat_map);
	}
	ft_putstr_fd(string, 2);
	return (0);
}

void	free_heat_map(t_map *f)
{
	int	i;

	i = 0;
	while (i < f->h)
	{
		if (f->heat_map[i])
			free(f->heat_map[i]);
		i++;
	}
	if (f->heat_map)
		free(f->heat_map);
}

void	free_map(t_map *f)
{
	int	i;

	i = 0;
	while (i < f->h)
	{
		if (f->map[i])
			free(f->map[i]);
		i++;
	}
	if (f->map)
		free(f->map);
}

void	free_piece(t_piece *f)
{
	int	i;

	i = 0;
	while (i < f->h)
	{
		if (f->pc[i])
			free(f->pc[i]);
		i++;
	}
	if (f->pc)
		free(f->pc);
}
