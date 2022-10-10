NAME = libft.a

CC =  gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memchr.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_memcmp.c\
	ft_strchr.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_atoi.c\
	ft_strlcat.c\
	ft_strdup.c\
	ft_calloc.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putstr_fd.c\
	ft_putnbr_fd.c\
	ft_split.c\
	ft_striteri.c\
	ft_itoa.c\
	ft_strjoin.c\
	ft_strmapi.c\
	ft_substr.c\
	ft_strtrim.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_printf.c\
	pointer_printf.c\
	putchar_printf.c\
	puthexa_printf.c\
	putnbr_printf.c\
	putnbr_unsigned_printf.c\
	putstr_printf.c\
	gnl.c\
	gnl_utils.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean : 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY : all clean fclean re
