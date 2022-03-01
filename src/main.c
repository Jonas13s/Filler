#include <filler.h>

/*	counting score first is checking boundaries 
second is checking if the xy space is not taken by me or enemy
last one is counting how effective it would be */
int possible_point(t_map *b, int y, int x, int *score)
{
	if (b->mainy + y - b->tempy < 0 || b->mainy + y - b->tempy >= b->h || b->mainx + x - b->tempx < 0 || b->mainx + x - b->tempx >= b->w)
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
int	result_back(t_map *b, t_piece *piece, int y, int x, int *score)
{
	b->tempy = y;
	b->tempx = x;
	while(y >= 0)
	{
		while(x >= 0)
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

int	result_forward(t_map *b, t_piece *piece, int y, int x, int *score)
{
	b->tempy = y;
	b->tempx = x;
	while(y < piece->h)
	{
		while(x < piece->w)
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
void	score_set(t_map *b, int score)
{
	if (b->moves == 1)
	{
		if ((score <= b->score && score > 0) || (b->score == 0))
		{
			b->score = score;
			b->sy = b->mainy - b->y;
			b->sx = b->mainx - b->x;
		}
	}
	else
	{
		if (score < b->score || b->score == 0)
		{
			b->score = score;
			b->sy = b->mainy - b->y;
			b->sx = b->mainx - b->x;
		}
	}
}

int	scoring(t_map *board, t_piece *piece)
{
	int	score;

	board->y = 0;
	board->x = 0;
	while (piece_search(piece, &board->y, &board->x))
	{
		score = 0;
		if (result_back(board, piece, board->y, board->x, &score) == 0 &&
				result_forward(board, piece, board->y, board->x, &score) == 0)
			score_set(board, score);
	}
	return (1);
}

void	have_moves(t_map *board)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	board->moves = 0;
	while(y < board->h)
	{
		while(x < board->w)
		{
			if (board->heat_map[y][x] > 0)
				board->moves = 1;
			x++;
		}
		x = 0;
		y++;
	}
}

int count_score(t_map *board, t_piece *piece)
{
	board->mainy = 0;
	board->mainx = 0;
	board->score = 0;
	have_moves(board);
	while(board->mainy < board->h)
	{
		while(board->mainx < board->w)
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
/*
if any of these are wrong it's error
which_player == 0 it means it was defined which player it is
*/
int	data(t_map *board, t_piece *piece)
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
	do_heat(board);
	count_score(board,piece);
	return (1);
}

int main()
{
	t_map	board;
	t_piece	piece;

	ft_bzero(&board, sizeof(board));
	ft_bzero(&piece, sizeof(piece));
	while(1)
	{
		if(!data(&board, &piece))
			return (0);
		ft_printf("%d %d\n", board.sy, board.sx);
		free_data(&board, &piece);
	}
	return (0);
}