NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = src/push_swap.c \
		src/operation_rotate.c \
		src/operation_r_rotate.c \
		src/operation_swap_push.c \
		src/list_func.c \
		src/a_to_b.c \
		src/b_to_a.c \
		src/sort_stack.c \
		src/sort_stack_2.c \
		src/helper.c \
		src/helper_2.c \
		src/error_free.c \
		src/checks.c \
		src/parsing.c
OBJS = $(SRCS:.c=.o)
LIBFT = lib/libft
PRINTF = lib/printf
INLIBFT = -L $(LIBFT) -lft
INPRINF = -L $(PRINTF) -lftprintf

TESTER_GET	=	https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER		=	./ps_tester.pl

BBlue="\033[1;34m"
BPurple="\033[1;35m"
BRed='\033[1;31m'
BGreen='\033[1;32m'
DEF_COLOR = '\033[0;39m'

$(NAME):		$(OBJS)
				@echo $(BBlue)"Compiling printf..."$(DEF_COLOR)
				@cd $(PRINTF) && $(MAKE) all
				@echo $(BPurple)"Compiling libft..."$(DEF_COLOR)
				@cd $(LIBFT) && $(MAKE) all
				@echo $(BPurple)"Compiling libft bonus..."$(DEF_COLOR)
				@cd $(LIBFT) && $(MAKE) bonus
				@echo $(BGreen)"Compiling $(NAME)..."$(DEF_COLOR)
				@cc $(OBJS) $(INLIBFT) $(INPRINF) -o $(NAME) $(CFLAGS)

all:		$(NAME)

$(TESTER):
	curl $(TESTER_GET) -o $(TESTER)

3: $(NAME) $(TESTER)
	perl $(TESTER) 3 100

5: $(NAME) $(TESTER)
	perl $(TESTER) 5 100

100: $(NAME) $(TESTER)
	perl $(TESTER) 100 100

500: $(NAME) $(TESTER)
	perl $(TESTER) 500 100

%.o:%.c
				@cc ${CFLAGS} -c $< -o $@

clean:
				@echo $(BRed)"Cleaning object files..."$(DEF_COLOR)
				@rm -f $(OBJS)
				@cd $(LIBFT) && $(MAKE) clean
				@cd $(PRINTF) && $(MAKE) clean

fclean:			clean
				@echo $(BRed)"Cleaning executable files..."$(DEF_COLOR)
				@rm -f $(NAME)
				@cd $(LIBFT) && $(MAKE) fclean
				@cd $(PRINTF) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re