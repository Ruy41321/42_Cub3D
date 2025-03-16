NAME = cub3D
CC = gcc
CFLAGS = -I$(MLXDIR) -Iincludes -I$(LIBFTDIR) -gdwarf-2 -Wall -Wextra -Werror #-fsanitize=address 

MAP_PATH = res/maps/subject.cub
EXE = $(NAME) $(MAP_PATH)


LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFT_FLAGS = -L$(LIBFTDIR) -lft

MLXDIR = ./minilibx-linux
MLXLIB = $(MLXDIR)/libmlx.a
INCLUDES = -I/usr/include -I$(MLXDIR) -I$(LIBFTDIR) 
MLX_FLAGS = -L$(MLXDIR) -lmlx -L/usr/lib/X11 -lXext -lX11

SRCS = 	srcs/main.c \
		srcs/utils/closing.c srcs/utils/3d_calculations.c srcs/utils/utils.c srcs/utils/testing.c \
		srcs/utils/initializing/initializing.c srcs/utils/initializing/initializing2.c \
		srcs/moving/mov_update_all.c srcs/moving/mov_key_press.c srcs/moving/mov_key_release.c srcs/moving/mov_update_only_position.c \
		srcs/moving/utils/moving_main_direction.c srcs/moving/utils/moving_oblq_direction.c srcs/moving/utils/mov_collision.c \
		srcs/drawing/drawing_2d_map.c srcs/drawing/drawing_player.c srcs/drawing/drawing_utils.c srcs/drawing/resizing.c\
		srcs/drawing/drawing_3d/3d_fov.c srcs/drawing/drawing_3d/3d_scene.c \
		srcs/drawing/map_building/build_map.c srcs/drawing/map_building/get_map_from_file.c srcs/drawing/map_building/build_map_utils.c\
		srcs/dda/dda.c srcs/dda/delta_path_point.c srcs/dda/sidePoint.c srcs/dda/end_point.c srcs/dda/utils/end_point_utils.c \
		srcs/dda/utils/dda_utils.c srcs/dda/utils/dda_checks.c srcs/dda/utils/direction.c \
		srcs/drawing/map_building/check_map_closed.c srcs/drawing/map_building/check_map_closed2.c \
		srcs/drawing/map_building/check_utils.c srcs/drawing/map_building/check_utils2.c 
		
OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(MLXLIB) $(NAME) 

$(LIBFT):
	$(MAKE) all -C $(LIBFTDIR)

$(MLXLIB):
	make -C $(MLXDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -lm -lz 

test: all
	./$(EXE)

norm:
	norminette libft includes $(SRCS)

invalid_test: all
	./$(NAME) res/maps/invalid/empty_line.cub
	./$(NAME) res/maps/invalid/empty.cub
	./$(NAME) res/maps/invalid/foo.txt
	./$(NAME) res/maps/invalid/invalid_rgb.cub
	./$(NAME) res/maps/invalid/invalid_rgb2.cub
	./$(NAME) res/maps/invalid/invalid_textures.cub
	./$(NAME) res/maps/invalid/missing_texture.cub
	./$(NAME) res/maps/invalid/no_ceiling_rgb.cub
	./$(NAME) res/maps/invalid/no_ceiling.cub
	./$(NAME) res/maps/invalid/no_floor_rgb.cub
	./$(NAME) res/maps/invalid/no_floor.cub
	./$(NAME) res/maps/invalid/no_player.cub
	./$(NAME) res/maps/invalid/out_of_map_elements.cub
	./$(NAME) res/maps/invalid/player_on_borders.cub
	./$(NAME) res/maps/invalid/unclosed_map.cub
	./$(NAME) res/maps/invalid/unknown_char.cub
	./$(NAME) res/maps/invalid/duplicate_player.cub

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/empty_line.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/empty.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/foo.txt
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/invalid_rgb.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/invalid_rgb2.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/invalid_textures.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/missing_texture.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/no_ceiling_rgb.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/no_ceiling.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/no_floor_rgb.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/no_floor.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/no_player.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/out_of_map_elements.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/player_on_borders.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/unclosed_map.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/unknown_char.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) res/maps/invalid/duplicate_player.cub
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXE)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean 
	make -C $(MLXDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTDIR) fclean
	
re: fclean all
