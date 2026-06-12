NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

SRCS        = parsing.c push_swap.c error.c push.c \
              rev-rotate.c rotate.c swap.c \
			  sort.c bench.c small_sort.c simple.c \
			  complex.c medium.c sort_utils.c sort_five.c

CHECKER_SRCS = checker_gopi/push_checker.c \
               checker_gopi/rev-rotate_checker.c checker_gopi/rotate_checker.c checker_gopi/swap_checker.c \
               checker_gopi/checker_checker.c

SRC_OBJS    = $(SRCS:.c=.o)

PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

.c.o:
	$(CC) $(CFLAGS) -I. -I$(PRINTF_DIR) -c $< -o ${<:.c=.o}

all: $(PRINTF) $(NAME)

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

bonus: $(PRINTF) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) parsing.o error.o push.o rev-rotate.o rotate.o swap.o \
	sort.o bench.o small_sort.o simple.o complex.o medium.o sort_utils.o \
	$(CHECKER_OBJS) $(PRINTF) -o checker
	@echo "Checker - Done!"

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(SRC_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC_OBJS) $(PRINTF) -o $(NAME)
	@echo "Push_Swap - Done!"

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(SRC_OBJS) $(CHECKER_OBJS)
	@echo "CLEAN - Done!"

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME) "checker" $(CHECKER_OBJS)
	@echo "FCLEAN - Done!"

re: fclean all

.PHONY: all clean fclean re bonus