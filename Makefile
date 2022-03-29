NAME = 	push_swap
CC =	gcc
RM =	rm -f
LIBFT	=	libft/libft.a

SRCS =	push_swap.c push_swap_utils.c $(LIBFT)
OBJS =	$(SRCS:.c=.o)

NC=\033[0m
GREEN=\033[0;32m

define HEADER_M
			                    .__                                         
			______  __ __  _____|  |__        ________  _  _______  ______  
			\____ \|  |  \/  ___/  |  \      /  ___/\ \/ \/ /\__  \ \____ \ 
			|  |_> >  |  /\___ \|   Y  \     \___ \  \     /  / __ \|  |_> >
			|   __/|____//____  >___|  /____/____  >  \/\_/  (____  /   __/ 
			|__|              \/     \/_____/    \/               \/|__|    

endef
export HEADER_M

all:	header $(NAME)

header:
	@echo " ${GREEN}$$HEADER_M${NC} "

%.o:	%.c
		$(CC) -Wall -Wextra -Werror -c $< -o $@

$(LIBFT) :
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C libft

fclean:	clean
		$(RM) $(NAME)
		make fclean -C libft

re:		fclean all

.PHONY:	all clean fclean re