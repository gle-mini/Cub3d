#include "cub3d.h"

int	ft_arrstrlen(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}


int min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_max_x(char **map)
{
	int max_x;
	int	y;

	max_x = 0;
	y = 0;
	while (map[y])
	{
		max_x = max(max_x, ft_strlen(map[y]) - 1);
		y++;
	}
	return (max_x);
}

int	find_max_y(char **map)
{
	int max_y;

	max_y = ft_arrstrlen(map);
	return (max_y);
}

char **alloc_copy_map(char **map)
{
	char	**new_map;
	int		max_x;
	int		max_y;
	int	i;

	max_x = find_max_x(map);
	max_y = find_max_y(map);
	new_map = malloc(sizeof(char *) * (max_y + 1));
	if (new_map == NULL)
		return (NULL);
	i =  0;
	while (i < max_y)
	{
		new_map[i] = malloc(sizeof(char) * (max_x));
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

char	**copy_map(char **map)
{
	char	**new_map;
	int		x;
	int		y;

	new_map = alloc_copy_map(map);
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '\n')
				new_map[y][x] = '\0';
			else
				new_map[y][x] = map[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	int		max_x;
	int		max_y;

	max_x = find_max_x(map);
	max_y = find_max_y(map);
	x = 0;
	y = 0;
	while (y < max_y)
	{
		while (x < max_x)
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'P')
			{
				new_map[y][x] = 'X';
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (new_map);
}
