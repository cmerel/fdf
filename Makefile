# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/31 14:05:34 by cmerel       #+#   ##    ##    #+#        #
#    Updated: 2018/05/15 13:54:48 by cmerel      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

INC_DIR = ./Includes
SRC_DIR = ./srcs
LIB_DIR = ./libft
MLX_DIR = ./mlx
OBJ_DIR = ./obj
INC_LIST = $(INC_DIR)/fdf.h  $(INC_DIR)/get_next_line.h

LIB_A = $(LIB_DIR)/libft.a
MLX_A = $(MLX_DIR)/libmlx.a

SRC = bresen.c fdf.c get_next_line.c draw.c check.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB_A) $(MLX_A) $(OBJ_DIR) $(OBJ)
	gcc $(FLAG) -framework OpenGL -framework Appkit -I $(INC_DIR) $(LIB_A) $(MLX_A) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB_A):
	@printf "creation libft.a\n"
	@$(MAKE) -C $(LIB_DIR)

$(MLX_A):
	@printf "creation libmlx.a\n"
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_LIST)
	gcc $(FLAG) -I $(INC_DIR) -o $@ -c $<

clean: clean_lib clean_mlx
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean fclean_lib fclean_mlx
	rm -f $(NAME)

re: fclean all

clean_mlx:
	@$(MAKE) -C $(MLX_DIR) clean

fclean_mlx:
	@$(MAKE) -C $(MLX_DIR) fclean

re_mlx:
	@$(MAKE) -C $(MLX_DIR) re

clean_lib:
	@$(MAKE) -C $(LIB_DIR) clean

fclean_lib:
	@$(MAKE) -C $(LIB_DIR) fclean

re_lib:
	@$(MAKE) -C $(LIB_DIR) re

clean_all: clean clean_lib clean_mlx

fclean_all: fclean fclean_lib fclean_mlx

re_all: re re_lib re_mlx
