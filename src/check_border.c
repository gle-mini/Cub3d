#include "cub3d.h"

int	ft_arrstrlen(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int is_border(char **map, int x, int y)
{
	if (x == 0 || y == 0 || x == my_strlen(map[y]) || y == ft_arrstrlen(map))
		return (1);
	return (0);
}

static int	is_valid(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'P')
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

int	ft_find_border(char **map, int x, int y)
{
	char	tmp_char;

	
	print_map(map);
	ft_putstr_fd("\n\n\n----------------------------\n\n\n", 1);

	if (is_border(map, x, y) == 1 && map[y][x] != '1')
		return (1);
	if (is_border(map, x, y))
		return (0);
	/*
	if (x < 0 || x == (int)ft_strlen(map[y])
		|| y < 0 || y == (int)ft_arrstrlen(map))
		return (0);
		*/

	if (is_valid(map, x, y))
	{
		fill_map(&(map[y][x]), &tmp_char);
		if (ft_find_border(map, x + 1, y)
			|| ft_find_border(map, x - 1, y)
			|| ft_find_border(map, x, y + 1)
			|| ft_find_border(map, x, y - 1))
			return (1);
	}
	ft_putstr_fd("TEST\n", 1);
	return (0);
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
		max_x = max(max_x, ft_strlen(map[y]));
		y++;
	}
	return (max_x);
}

int	find_max_y(char **map)
{
	int max_y;

	max_y = ft_arrstrlen(map)
	return (max_y);
}

char **alloc_copy_map(char **map, int max_x, int max_y)
{
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
		new_map[i] = malloc(sizeof(char) * (max_x + 1));
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

char	**copy_map(char **map)
{
	char	**new_map;

	new_map = alloc_copy_map(map, max_x, max_y);
	return (new_map);
}


int check_border(char **map)
{
	char	**new_map;

	new_map = copy_map(map);
	if (copy_map == NULL)
		return (MALLOC_ERR);
	/*
	if (ft_find_border(map, 2, 2) == 1)
	{
		printf("ERROR\n");
		return (0);
	}
	else
	{
		printf("OK\n");
		return (1);
	}*/
	return (1);
}

