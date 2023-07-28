CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft/libft.a
HEADER = ft_printf.h
ARFLAGS = crus
SRCS = ft_printf.c \
	   ft_printf_conv.c \
	   ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT) : 
	cd libft ; $(MAKE) all

clean:
	rm -f $(OBJS) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

$(OBJS) : $(HEADER)

.PHONY : all clean fclean re
.INTERMEDIATE : $(OBJS) $(LIBFT)
