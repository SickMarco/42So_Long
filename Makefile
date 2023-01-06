NAME = so_long

SRC = main.c map_error.c game_utils.c put_map.c movement.c move_counter.c enemy.c animation.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fPIE

LINK = ../minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm

LIBFT = ./Lib/Libft/libft.a

GNL = ./Lib/GetNextLine/GNL.a

PRINTF = ./Lib/Printf/libftprintf.a

all: lib printf gnl $(NAME)

lib:
	make -s -C Lib/Libft

printf:
	make -s -C Lib/Printf
	
gnl:
	make -s -C Lib/GetNextLine

$(NAME): $(OBJ)
	@echo "\033[32mCompiling $(NAME) 🚀"
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(LINK) -o $(NAME)
	@echo "Compiled ✅\033[0;37m"

clean:
	@echo "\033[0;31mCleaning objects 🧹"
	@rm -rf $(OBJ)
	@make clean -s -C Lib/Libft
	@make clean -s -C Lib/Printf
	@make clean -s -C Lib/GetNextLine

fclean: clean
	@echo "\033[0;31mRemoving $(NAME) 🗑\033[0;37m"
	@rm -rf $(NAME)
	@make fclean -s -C Lib/Libft
	@make fclean -s -C Lib/Printf
	@make fclean -s -C Lib/GetNextLine

re: fclean all

.SILENT: $(OBJ) lib printf gnl
