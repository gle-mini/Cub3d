/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-mini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:32:09 by gle-mini          #+#    #+#             */
/*   Updated: 2023/06/27 15:41:01 by gle-mini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_directory(const char *path)
{
	int	fd;

	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

static char	*find_extension(const char *path)
{
	char	*dot;

	dot = NULL;
	dot = ft_strrchr(path, '.');
	if (!dot || dot == path)
		return (NULL);
	return (dot + 1);
}

static int	check_file(const char *path)
{
	if (is_directory(path))
		return (DIR_MAP);
	if (find_extension(path) == NULL)
		return (EXT_MAP);
	if (ft_strncmp(find_extension(path), "cub", 4))
		return (EXT_MAP);
	return (0);
}

int	read_map(char *map_path, t_list **map_list)
{
	int		error_handle;
	int		fd;
	char	*line;

	line = NULL;
	error_handle = check_file(map_path);
	if (error_handle != 0)
		return (error_handle);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (OPEN_ERR);
	line = get_next_line(fd);
	if (line == NULL)
		return (GNL_NULL);
	while (line != NULL)
	{
		ft_lstadd_back(map_list, ft_lstnew(ft_strdup(line)));
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (0);
}

int	ft_list_to_array_str(t_list *list, char ***array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (ADDRESS_ERR);
	*array = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (*array == NULL)
		return (MALLOC_ERR);
	while (list)
	{
		(*array)[i] = ft_strdup((char *)list->content);
		if ((*array)[i] == NULL)
			return (MALLOC_ERR);
		list = list->next;
		i++;
	}
	(*array)[i] = NULL;
	return (0);
}

void print_map(char **map)
{
	int y;

	y = 0;
	if (map == NULL)
		return ;
	while (map[y])
	{
		ft_putstr_fd(map[y], 1);
		y++;
	}
}

int	parse_map(char *map_path, t_data *data)
{	
	int		error_handle;
	t_list	*map_list;		

	map_list = NULL;
	error_handle = read_map(map_path, &map_list);
	if (error_handle != 0)
		return (error_handle);
	error_handle = ft_list_to_array_str(map_list, &(data->map));
	if (error_handle != 0)
		return (error_handle);
	print_map(data->map);	
	return (0);
}

void ft_init_data(t_data *data)
{
	data->map = NULL;
}

int main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (MALLOC_ERR);
	ft_init_data(data);
	if (argc != 2)
		return (NUMBER_ARG);
	parse_map(argv[1], data);
	check_border(data->map);
	return (EXIT_SUCCESS);
}
