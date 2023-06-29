#include "cub3d.h"

/**
 * @brief Calculate the string array length
 *
 * @param char **array: The array yo
 * @return array length
 * @throws
*/
static int	ft_arrstrlen(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

/**
 * @brief Check if the coordinates (x,y) are borders
 *
 * @param char **map: the map
 * @param int x: the coordinate x 
 * @param int y: the coordinate y 
 * @return boolean 1 if is border, 0 if isn't
 * @throws
*/
static int	is_border(char **map, int x, int y)
{
	if (x == 0 || y == 0 || x == (int)ft_strlen(map[y]) \
			|| y == ft_arrstrlen(map))
		return (1);
	return (0);
}

/**
 * @brief Check if the case is a traversable 
 *
 * @param char **map: the map
 * @param int x: the coordinate x 
 * @param int y: the coordinate y  
 * @return boolean 1 if the case is traversable, 0 if isn't
 * @throws
*/
static int	is_valid(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'P')
		return (1);
	return (0);
}

/**
 * @brief Change character to mark backtracking algorithm passage
 *
 * @param char *original: the original map character
 * @param char *tmp_char: the temporary char to mark the backtraking 
 * algorithm passage
 * @return void
 * @throws
*/
static void	fill_map(char *original, char *tmp_char)
{
	*tmp_char = *original;
	if (*original == '0')
		*original = '2';
	else if (*original == 'C')
		*original = '3';
	else if (*original == 'P')
		*original = '4';
	else
		*original = '5';
}

/**
 * @brief Backtracking algorithm wich croses and marks the passage in 
 * order to check if the map is well closed by walls
 *
 * The algorithm start at the players coordinates
 *
 * @param char **map: the map you want to check
 * @param int x, int y: the (x, y) player coordinates
 * @return boolean 1 if isn't closed, 0 if it is
 * @throws
*/
static int	ft_find_border(char **map, int x, int y)
{
	char	tmp_char;

	if ((is_border(map, x, y) == 1 && map[y][x] != '1' ))
		return (1);
	if (x < 0 || x == (int)ft_strlen(map[y])
		|| y < 0 || y == (int)ft_arrstrlen(map))
		return (0);
	if (is_valid(map, x, y))
	{
		fill_map(&(map[y][x]), &tmp_char);
		if (ft_find_border(map, x + 1, y)
			|| ft_find_border(map, x - 1, y)
			|| ft_find_border(map, x, y + 1)
			|| ft_find_border(map, x, y - 1))
			return (1);
	}
	return (0);
}

/**
 * @brief Function 
 *
 * We who use copy_map to transforme the map into a rectangle malloc map 
 * in order to simplify the backtracking walls checking 
 *
 * @param char **map: the map you want to check
 * @return 1 if the map is closed by walls else 0 if isnt
 * @throws Print on the STDOUT "Map is not closed by wall" if it is
 * @throws Return MALLOC_ERR is there is malloc error
*/
int	check_border(char **map)
{
	char	**new_map;

	new_map = copy_map(map);
	if (new_map == NULL)
		return (MALLOC_ERR);
	if (ft_find_border(new_map, 2, 2) == 1)
	{
		printf("Map is not closed by wall\n");
		return (0);
	}
	return (1);
}
