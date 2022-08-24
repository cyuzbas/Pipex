NAME	=	pipex

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

# DFLAGS	=	-g -fsanitize=address


# ifdef WITH_BONUS
# SRCS	=	pipex_bonus.c \
# 			utils_bonus.c
# else
SRCS	=	pipex.c \
			utils.c
# endif

HEADER	=	pipex.h

OBJS	=	$(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT = libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c  $(HEADER)
	$(CC) -c $< -o $(<:.c=.o)

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:		
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all


.PHONY: all clean fclean re bonus