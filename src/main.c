#include <filler.h>
/*
in which player when else it should kill whole filler because player is invalid
*/
int	which_player(t_map *board)
{
	char	*line;
	char	*pos;
	char 	c;

	if(get_next_line(0, &line) <= 0)
		return (0);
	pos = ft_strchr(line, 'p');
	pos++;
	c = *pos;
	ft_strdel(&line);
	if (c == '1')
	{
		board->my_letter = 'O';
		board->enem_letter = 'X';
		return (1);
	}
	else if (c == '2')
	{
		board->my_letter = 'X';
		board->enem_letter = 'O';
		return (1);
	}
	else
		return (0); // kill here
	return (1);
}

int result(t_map *board, t_piece *piece, int y, int x, int i, int j)
{
	int score;
	int tempy;
	int	tempx;

	tempy = 0;
	tempx = 0;
	score = 0;
	(void)x;
	(void)y;
	(void)board;
	//printf("start:%d %d\n", i, j);
	while(tempy < piece->h)
	{
		while(tempx < piece->w)
		{
			if (piece->pc[tempy][tempx] == '*' && (i != tempy || j != tempx))
			{
				//printf("%d %d\n", tempy, tempx);
				score += board->heat_map[y - i + tempy][x - j + tempx];
			}
			tempx++;
		}
		tempx = 0;
		tempy++;
	}
	//printf("score: %d\n\n", score);
	return (score);
}

int	scoring(t_map *board, t_piece *piece, int y, int x)
{
	int	i;
	int	j;
	int	score;
	int	best[4];

	best[0] = 0; // x
	best[1] = 0; // y
	best[2] = 0; // score
	score = 0;
	i = 0;
	j = 0;
	while(i < piece->h)
	{
		while(j < piece->w)
		{
			if (piece->pc[i][j] == '*')
			{
				score = result(board,piece, y, x, i , j);
				if (best[2] == 0)
				{
					best[0] = x;
					best[1] = y;
					best[2] = score;
				}
				if (best[2] > score)
				{
					best[0] = x;
					best[1] = y;
					best[2] = score;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_putnbr(best[1]);
	ft_putchar(' ');
	ft_putnbr(best[0]);
	ft_putchar('\n');
	//printf("x:%d y:%d score:%d\n", best[0], best[1], best[2]);
	return (1);
}

int count_score(t_map *board, t_piece *piece)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(y < board->h)
	{
		while(x < board->w)
		{
			if (board->heat_map[y][x] == ME)
				scoring(board, piece, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
/*
if any of these are wrong it's error
which_player == 0 it means it was defined which player it is
*/
int	data(t_map *board, t_piece *piece)
{
	if (!board->my_letter)
		which_player(board);
	get_board(board);
	create_heat_map(board);
	init_heat(board);
	get_piece(piece);
	do_heat(board);
	count_score(board,piece);
	return (0);
}

int main()
{
	t_map	*board;
	t_piece	*piece;

	piece = (t_piece *) malloc(sizeof(t_piece));
	board = (t_map *) malloc(sizeof(t_map));
	while(1)
	{
		data(board, piece);
		ft_free2d(board->map);
		ft_free2d(board->heat_map);
		ft_free2d(piece->pc);
	}
	/*int y = 0;
	while(y < board->h)
	{
		printf("%s\n", board->heat_map[y]);
		y++;
	}*/
	return (0);
}