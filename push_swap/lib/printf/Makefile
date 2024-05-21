CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --silent
RM = rm -rf
NAME = libftprintf.a
SRCS = ft_printf.c \
		putfunctions.c \
		putnbrfunctions.c \
		putnbr_x.c \
		whattoprint.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re