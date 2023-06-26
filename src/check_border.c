#include "cub3d.h"

int	ft_arrstrlen(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int is_border(char **map, int x, int y)
{
	if (x == 0 || y == 0)
		return (1);
	if (x == (int)ft_strlen(map[y]) || y == ft_arrstrlen(map))
		return (1);
	if (map[y + 1][x] == ' ' || map[y - 1][x] == ' ' || map[y][x + 1] == ' ' || map[y][x - 1] == ' ')
		return (1);
	return (0);
}

static int	is_valid(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'P')
		return (0);
	return (1);
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

int	ft_find_border(char **map, int x, int y)
{
	char	tmp_char;

	
	if (is_border(map, x, y) == 1 && map[y][x] != '1')
		return (0);
	if (x < 0 || x == (int)ft_strlen(*map)
		|| y < 0 || y == (int)ft_arrstrlen(map))
		return (1);
	if (is_valid(map, x, y))
	{
		fill_map(&(map[y][x]), &tmp_char);
		if (ft_find_border(map, x + 1, y)
			|| ft_find_border(map, x - 1, y)
			|| ft_find_border(map, x, y + 1)
			|| ft_find_border(map, x, y - 1))
			return (1);
	}
	return (1);
}


int check_border(char **map)
{
	if (ft_find_border(map, 2, 2) == 0)
	{
		printf("ERROR\n");
		return (0);
	}
	else
	{
		printf("OK\n");
		return (1);
	}
}

