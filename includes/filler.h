/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 03:59:59 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/01 12:15:41 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <libft.h>

# define DE 0
# define ME -4
# define ENEM -2

typedef struct s_map
{
	char	**map;
	char	**heat_map;
	char	my_letter;
	char	enem_letter;
	int		w;
	int		h;
	int		sy;
	int		sx;
	int		y;
	int		x;
	int		tempy;
	int		tempx;
	int		mainy;
	int		mainx;
	int		score;
	int		moves;
}				t_map;

typedef struct s_piece
{
	char	**pc;
	int		w;
	int		h;
	int		star;
}				t_piece;

/*Additional.c*/
int		ft_str_valid(char *str, char *sym);
void	ft_free2d(void **str);
void	init_struct_piece(t_piece *f);
void	init_struct_map(t_map *f);
void	free_piece(t_piece *f);
void	free_heat_map(t_map *f);
void	free_map(t_map *f);
void	ft_free_tab_char(char ***tab);
void	free_data(t_map *board, t_piece *piece);
int		free_data_error(t_map *board, t_piece *piece, char *string);
/*Board.c*/
int		get_board_size(t_map *board);
int		get_board(t_map *board);
int		get_piece(t_piece *piece);
/*main.c*/
int		which_player(t_map *board);
/*piece.c*/
int		get_piece(t_piece *piece);
/*heat_map.c*/
int		create_heat_map(t_map *board);
void	init_heat(t_map *board);
void	do_heat(t_map *board);
#endif