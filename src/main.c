#include <filler.h>
/*
in which player when else it should kill whole filler because player is invalid
*/
char	which_player(void)
{
	char	*line;
	char	*pos;
	char 	c;

	get_next_line(0, &line);
	pos = ft_strchr(line, 'p');
	pos++;
	c = *pos;
	if (c == '1')
		return ('o');
	else if (c == '2')
		return ('x');
	else
		return (0);
	return (0);
}

/*
if any of these are wrong it's error
which_player == 0 it means it was defined which player it is
*/

int	data(t_map *board)
{
	board->player = which_player();
	return (0);
}

int main()
{
	t_map	*board;

	board = (t_map *) malloc(sizeof(t_map));
	data(board);
	while(1)
	{

	}
	return (0);
}