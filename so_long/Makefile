NAME				= so_long

FOLDER				= src/

SRCS 			=  main.c\
						render/render_map.c\
						map_checker/ft_map_reader.c\
						map_checker/structure_initializer.c\
						player_movement/hooks.c\
						player_movement/player_movement.c

OBJS				= ${SRCS:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror -Ilibft -I../libft -I.

RM					= rm -f

$(NAME):	${OBJS}
			cd libft && make
			cd minilibx && make
			#$(CC) $(CFLAGS) ${OBJ} libft/libft.a -l mlx -framework OpenGL -framework AppKit -o $(NAME)
			$(CC) $(CFLAGS) ${OBJS} libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:		${NAME}

re: 		fclean all

clean:
			${RM} $(OBJS_COMU) $(OBJS_BONUS) $(OBJS)
			cd libft && make clean
			cd minilibx && make clean

fclean:		
			${RM} $(OBJS_COMU) $(OBJS)
			cd libft && make fclean
			cd minilibx && make clean
			${RM} so_long
			${RM} libmlx.dylib

.PHONY: 	all clean fclean re