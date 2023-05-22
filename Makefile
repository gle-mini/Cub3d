# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-mini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 15:12:26 by gle-mini          #+#    #+#              #
#    Updated: 2023/05/22 20:43:33 by gle-mini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#---------------------------Files---------------------------

C_MAIN	=	main


#---------------------Sources and objects-------------------

SRCS	=	$(addprefix src/, $(addsuffix .c, $(C_MAIN)))

OBJS	=	$(SRCS:.c=.o)

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
LIBCOMP			=	$(MSG_LIBCOMP) \
					make --silent -C libft \
					$(MSG_LIBREADY)
	

HEADER		=	./include/
HEADER_FILE	=	./include/cub3d.h

#-------------------Constant strings------------------------

COMPILER	=	cc

FLAGS		=	-Wall -Wextra -Werror -g3 -I $(HEADER)

#LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

LIBS		=	-lmlx -framework OpenGL -framework AppKit

INCLUDE		=	-Iinclude -Ilibft

NAME		=	cub3d

#-----------------------Messages----------------------------

MSG_READY		=	echo "Cub3D is ready !"
MSG_LIBCOMP		=	echo "compiling libft ..."
MSG_LIBREADY	=	echo "libft is compiled"

#-----------------------Rules-------------------------------

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILE) $(MLX)
		@$(LIBCOMP)
		$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBS) -v

$(MLX):	
		@$(MAKE) -C minilibx-linux

.c.o:
	$(COMPILER) $(FLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

clean:
		@$(MAKE) -C minilibx-linux clean
		rm -rf $(OBJS) $(BONUS_OBJS)

fclean:	clean
		rm -rf $(NAME)

re:	fclean
	$(NAME)

.PHONY:		all clean fclean re
