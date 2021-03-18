# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 12:40:25 by rmartins          #+#    #+#              #
#    Updated: 2021/03/18 15:36:28 by rmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADER = include/ft_cub3d.h

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLX_FLAGS = -lbsd -lmlx -lXext -lX11 -lm
	SYSTEM = -D LINUX_COMPUTER=1
else
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

# MLX_FLAGS = -lbsd -lmlx -lXext -lX11 -lm

LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcsv
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

SRC = cub3d.c \
		utils/check_extension.c \
		utils/print_errors.c \
		utils/get_next_line.c \
		utils/string_validate_characters.c \
		validate_args.c \
		map/open_map_file.c \
		map/parse_map.c \
		game/game.c

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	@echo $(ANSI_B_BGREEN) "compile libft" $(ANSI_RESET)$(ANSI_F_BBLACK)
	$(MAKE) all -C libft
	@echo $(ANSI_RESET) ""
	@echo $(ANSI_B_BGREEN) "compile executable" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo $(ANSI_RESET) ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo $(ANSI_B_BGREEN) "compile ft_printf objects" $(ANSI_RESET)$(ANSI_F_BBLACK)
	gcc $(CFLAGS) $(SYSTEM) -include $(HEADER) -c $< -o $@
	@echo $(ANSI_RESET)

$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
	@echo $(ANSI_B_BGREEN) "create obj folder if needed" $(ANSI_RESET)$(ANSI_F_BBLACK)
	mkdir -p $@
	mkdir -p obj/game
	mkdir -p obj/map
	mkdir -p obj/utils
	@echo $(ANSI_RESET) ""

clean:
	@echo $(ANSI_B_RED) "clean" $(ANSI_RESET)$(ANSI_F_BRED)
	#$(MAKE) clean -C libft
	rm -rf $(OBJ_DIR)
	@echo $(ANSI_RESET) ""

fclean: clean
	@echo $(ANSI_B_RED) "fclean" $(ANSI_RESET)$(ANSI_F_BRED)
	#$(MAKE) fclean -C libft
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
	@norminette $(HEADER) $(addprefix src/,$(SRC))

norm2:
	@echo $(ANSI_B_RED) "norminette v2" $(ANSI_RESET)
	@norminette2 $(HEADER) $(addprefix src/,$(SRC))

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

MAP = maps/romeu.cub

invalid: runs
	./cub3DS test.cub
	./cub3DS test.cub2
	./cub3DS
	./cub3DS test.cub as

	./cub3DS invalid_maps/invalid_res_000.cub
	./cub3DS invalid_maps/invalid_res_001.cub
	./cub3DS invalid_maps/invalid_res_002.cub
	./cub3DS invalid_maps/invalid_res_003.cub
	./cub3DS invalid_maps/invalid_res_004.cub
	./cub3DS invalid_maps/invalid_res_005.cub
	./cub3DS invalid_maps/invalid_res_006.cub
	./cub3DS invalid_maps/invalid_res_007.cub
	./cub3DS invalid_maps/invalid_res_008.cub
	./cub3DS invalid_maps/invalid_res_009.cub
	./cub3DS invalid_maps/invalid_res_010.cub
	./cub3DS invalid_maps/invalid_res_011.cub
	./cub3DS invalid_maps/invalid_res_012.cub
	./cub3DS invalid_maps/invalid_res_013.cub
	./cub3DS invalid_maps/invalid_res_014.cub
	./cub3DS invalid_maps/invalid_res_015.cub
	./cub3DS invalid_maps/invalid_res_016.cub
	./cub3DS invalid_maps/invalid_res_017.cub
	./cub3DS invalid_maps/invalid_res_018.cub
	./cub3DS invalid_maps/invalid_res_019.cub
	./cub3DS invalid_maps/invalid_res_020.cub
	./cub3DS invalid_maps/invalid_res_021.cub
	./cub3DS invalid_maps/invalid_res_022.cub
	./cub3DS invalid_maps/invalid_res_023.cub
	./cub3DS invalid_maps/invalid_res_024.cub
	./cub3DS invalid_maps/invalid_res_025.cub
	./cub3DS invalid_maps/invalid_res_026.cub
	./cub3DS invalid_maps/invalid_res_027.cub
	./cub3DS invalid_maps/invalid_res_028.cub
	./cub3DS invalid_maps/invalid_res_029.cub

	./cub3DS invalid_maps/invalid_tex_EA_000.cub
	./cub3DS invalid_maps/invalid_tex_EA_001.cub
	./cub3DS invalid_maps/invalid_tex_EA_002.cub
	./cub3DS invalid_maps/invalid_tex_EA_003.cub
	./cub3DS invalid_maps/invalid_tex_EA_004.cub
	./cub3DS invalid_maps/invalid_tex_EA_005.cub
	./cub3DS invalid_maps/invalid_tex_EA_006.cub
	./cub3DS invalid_maps/invalid_tex_EA_007.cub
	./cub3DS invalid_maps/invalid_tex_EA_008.cub
	./cub3DS invalid_maps/invalid_tex_EA_009.cub
	./cub3DS invalid_maps/invalid_tex_EA_010.cub
	./cub3DS invalid_maps/invalid_tex_EA_011.cub
	./cub3DS invalid_maps/invalid_tex_EA_012.cub
	./cub3DS invalid_maps/invalid_tex_EA_013.cub
	./cub3DS invalid_maps/invalid_tex_EA_014.cub
	./cub3DS invalid_maps/invalid_tex_EA_015.cub
	./cub3DS invalid_maps/invalid_tex_EA_016.cub
	./cub3DS invalid_maps/invalid_tex_EA_017.cub
	./cub3DS invalid_maps/invalid_tex_EA_018.cub
	./cub3DS invalid_maps/invalid_tex_EA_019.cub
	./cub3DS invalid_maps/invalid_tex_EA_020.cub
	./cub3DS invalid_maps/invalid_tex_EA_021.cub
	./cub3DS invalid_maps/invalid_tex_EA_022.cub