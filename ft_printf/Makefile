FT_PRINTF =		./ft_printf.c \
				./ft_printf_utils.c \
				./ft_check_tags.c \
				./ft_get_c.c \
				./ft_get_di.c \
				./ft_get_p.c \
				./ft_get_per.c \
				./ft_get_s.c \
				./ft_get_u.c \
				./ft_get_x.c

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a
INC = .

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INC)

$(NAME) : $(FT_PRINTF:.c=.o)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rc $(NAME) $(FT_PRINTF:.c=.o)

all : $(NAME)


bonus : $(NAME) $(BONUS:.c=.o)
	ar rc $(NAME) $(BONUS:.c=.o)

clean :
	rm -f $(FT_PRINTF:.c=.o) $(BONUS:.c=.o)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all
