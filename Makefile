# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 12:40:25 by rmartins          #+#    #+#              #
#    Updated: 2021/03/23 23:20:00 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLX_FLAGS = -lbsd -lmlx -lXext -lX11 -lm
	SYSTEM = -D LINUX_COMPUTER=1
else
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcsv
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

HEADER = ft_ansi.h \
		ft_cub3d.h \
		ft_structs.h \
		ft_linux_keys.h \
		ft_mac_keys.h \
		ft_utils.h \
		ft_map.h \
		ft_game.h \
		get_next_line.h
		
SRC = cub3d.c \
		utils/check_extension.c \
		utils/get_next_line.c \
		utils/count_specific_char.c \
		utils/validate_args.c \
		utils/init_structures.c \
		map/open_map_file.c \
		map/parse_map.c \
		map/validate_map_line.c \
		map/save_map_line.c \
		map/check_map_errors.c \
		map/print_map_errors.c \
		map/sqare_matrix.c \
		map/check_RGB.c \
		game/game.c \
		game/close_game.c \
		game/hooks.c \
		game/draw_world2d.c \
		game/draw_shapes.c \
		game/utils.c \
		game/check_wall_collision.c

all: $(NAME)


printcompile:
	@echo $(ANSI_B_BGREEN) "compile cub3d objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
resetprint:
	@echo $(ANSI_RESET)

$(NAME): printcompile $(OBJ) resetprint
	@echo $(ANSI_B_BGREEN) "compile libft" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) all -C libft
	@echo $(ANSI_RESET) ""
	@echo $(ANSI_B_BGREEN) "compile executable" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix inc/,$(HEADER))
	mkdir -p $(dir $@)
	gcc $(CFLAGS) $(SYSTEM) -Iinc -c $< -o $@


clean:
	@echo $(ANSI_B_RED) "clean" $(ANSI_RESET)$(ANSI_F_BRED)
	$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)
	@echo $(ANSI_RESET) ""

fclean: clean
	@echo $(ANSI_B_RED) "fclean" $(ANSI_RESET)$(ANSI_F_BRED)
	$(MAKE) fclean -C libft
	rm -f cub3DS
	rm -f $(NAME)
	@echo $(ANSI_RESET) ""

re: fclean all

bonus: all
	
.PHONY: all clean fclean

# colors
ANSI_RESET = "\033[0m"
ANSI_B_RED = "\033[41m"
ANSI_B_BGREEN = "\033[42;1m"
ANSI_F_BRED = "\033[31;1m"
ANSI_F_BBLACK = "\033[30;1m"


lib:
	$(MAKE) -C libft

norm:
	@echo $(ANSI_B_RED) "norminette v3" $(ANSI_RESET)
	@norminette $(addprefix inc/,$(HEADER)) $(addprefix src/,$(SRC))

norm2:
	@echo $(ANSI_B_RED) "norminette v2" $(ANSI_RESET)
	@norminette2 $(addprefix inc/,$(HEADER)) $(addprefix src/,$(SRC))

libnorm:
	@echo $(ANSI_B_RED) "libft norminette" $(ANSI_RESET)
	$(MAKE) norm -C libft

libnorm2:
	@echo $(ANSI_B_RED) "libft norminette v2" $(ANSI_RESET)
	$(MAKE) norm2 -C libft

run: all
	@echo $(ANSI_B_RED) "Running for debbuger without sanitize" $(ANSI_RESET)
	./$(NAME) $(MAP)

runv: all
	@echo $(ANSI_B_RED) "Valgrind RESULT" $(ANSI_RESET)
	# valgrind -q --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) $(MAP)
	valgrind ./$(NAME) $(MAP)

runs: all
	@echo $(ANSI_B_RED) "Running with sanitize" $(ANSI_RESET)
	gcc $(CFLAGS) -fsanitize=address $(OBJ) $(LIBFT) $(MLX_FLAGS) -o cub3DS
	./cub3DS $(MAP)

MAP = resources/maps/romeu.cub
#MAP = resources/maps/test5.cub
#MAP = resources/maps/invalid_map_area_010.cub