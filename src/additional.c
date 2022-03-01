/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:36:29 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/01 12:43:57 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

void	init_struct_piece(t_piece *f)
{
	f->pc = NULL;
	f->w = 0;
	f->h = 0;
	f->star = 0;
}

void	ft_free_tab_char(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i] != NULL)
		free((*tab)[i++]);
	free(*tab);
}

void	ft_free2d(void **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

int	free_data_error(t_map *board, t_piece *piece, char *string)
{
	if (piece)
		if (piece->pc)
			ft_free2d((void **)piece->pc);
	if(board)
	{
		if (board->map)
			ft_free2d((void **)board->map);
		if (board->heat_map)
			ft_free2d((void **)board->heat_map);
	}
	ft_putstr_fd(string, 2);
	return (0);
}

void	free_data(t_map *board, t_piece *piece)
{
	ft_free2d((void **)board->map);
	ft_free2d((void **)board->heat_map);
	ft_free2d((void **)piece->pc);
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
