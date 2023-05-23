# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-mini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 15:12:26 by gle-mini          #+#    #+#              #
#    Updated: 2023/05/23 21:28:30 by gle-mini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#---------------------------Files---------------------------

C_MAIN	=	main


#---------------------Sources and objects-------------------

SRCS	=	$(addprefix src/, $(addsuffix .c, $(C_MAIN)))

OBJS	=	$(addprefix obj/, $(patsubst src/%,%,$(SRCS:.c=.o)))

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
LIBCOMP		=	$(MSG_LIBCOMP) \
				make --silent -C libft \
				$(MSG_LIBREADY)
	
MLX_COMP	=	make -C minilibx-linux
MLX			=	libmlx.a

#-------------------Constant strings------------------------

COMPILER	=	cc

FLAGS		=	-Wall -Wextra -Werror -g3 -I $(HEADER)

#LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

#LIBS		=	-lmlx -framework OpenGL -framework AppKit

LIBS		=	-lXext -lX11 -lm

INCLUDE		=	-Iinclude -Ilibft

NAME		=	cub3d

HEADER		=	./include/
HEADER_FILE	=	./include/cub3d.h


#-----------------------Messages----------------------------

MSG_READY		=	echo "Cub3D is ready !"
MSG_LIBCOMP		=	echo "compiling libft ..."
MSG_LIBREADY	=	echo "libft is compiled"

#-----------------------Rules-------------------------------

# make pour a compilation multithread
# all: @$(MAKE) -j $(NAME)

all: $(NAME)

cub3d: $(OBJS) $(HEADER_FILE)
	@$(LIBCOMP)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) -L minilibx-linux $(LIBS) -v


.c.o:
	$(COMPILER) $(FLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

obj/%.o: src/%.c
	@mkdir -p obj
	$(COMPILER) $(FLAGS) -I $(HEADER) -I minilibx-linux -I libft -c $< -o $@

clean:
	@make -C minilibx-linux clean
	@make -C libft clean
	rm -rf obj

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:		all, clean, fclean, re
