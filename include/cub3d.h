/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-mini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:34:47 by gle-mini          #+#    #+#             */
/*   Updated: 2023/06/26 15:15:38 by gle-mini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*-------------------------------- Libraries -----------------------------*/
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <sys/stat.h>
# include <fcntl.h>

# define NUMBER_ARG 1
# define DIR_MAP 2
# define EXT_MAP 3
# define OPEN_ERR 4
# define GNL_NULL 5
# define MALLOC_ERR 6
# define ADDRESS_ERR 7

typedef struct s_data {
	char **map;
} t_data;

#endif

