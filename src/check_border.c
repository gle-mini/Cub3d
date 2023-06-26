#include "cub3d.h"

static int	is_valid(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'C'\
			|| map[y][x] == 'P' || map[y][x] == 'E')
		return (1);
	return (0);
}

static void	fill_map(char *position, char *tmp_char)
{
	*tmp_char = *position;
	if (*position == '0')
		*position = '2';
	else if (*position == 'C')
		*position = '3';
	else if (*position == 'P')
		*position = '4';
	else
		*position = '5';
}

int	ft_find_exit(char **map, int x, int y)
{
	char	tmp_char;

	if (map[y][x] == 'E')
		return (0);
	if (x < 0 || x == (int)ft_strlen(*map)
		|| y < 0 || y == (int)ft_arrstrlen(map))
		return (1);
	if (is_valid(map, x, y))
	{
		fill_map(&(map[y][x]), &tmp_char);
		if (ft_find_exit(map, x + 1, y)
			|| ft_find_exit(map, x - 1, y)
			|| ft_find_exit(map, x, y + 1)
			|| ft_find_exit(map, x, y - 1))
			return (1);
	}
	return (1);
}


int check_border(char **map)
{
	if (ft_find_border(map, 2, 2) == 0)
	{
		printf("ERROR\n");
	}
	else
	{
		printf("OK\n");
	}
}

