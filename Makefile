LIBFT = ./Libft/libft.a

MLX = ./mlx_linux/libmlx.a

NAME = fdf

CC =  gcc

CFLAGS = -Wall -g3 #-Wextra -Werror

SRC = main.c verif_arg.c read_file.c initialize.c starting.c utils.c iso_map.c destroy_malloc.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L./Libft -lft -L./mlx_linux -lmlx -lXext -lX11 -lm

$(LIBFT) :
	make -C Libft

$(MLX) :
	make -C mlx_linux

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I . -I Libft -I mlx_linux

clean : 
	rm -f $(OBJ)
	make clean -C Libft

fclean : clean
	rm -f $(NAME)
	make fclean -C Libft

re : fclean all

.PHONY : all clean fclean re
