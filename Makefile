NAME	=	push_swap
CHECKER	=	checker
CC		=	gcc
RM		=	rm -f
LIBFT	=	libft/libft.a

SRCS	=	push_swap.c push_swap_utils.c push_swap_utils_2.c operations.c operations_2.c sorting_process.c sorting_process_2.c $(LIBFT)
SRCSBN	=	checker.c push_swap_utils.c push_swap_utils_2.c operations.c operations_2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c $(LIBFT)
OBJS	=	$(SRCS:.c=.o)
OBJSBN	=	$(SRCSBN:.c=.o)

NC		=	\033[0m
GREEN	=	\033[0;32m

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

%.o: %.c
		$(CC) -Wall -Wextra -Werror -c $< -o $@

$(LIBFT):
		make -C libft

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(OBJS) -o $(NAME)

$(CHECKER): $(OBJSBN) $(LIBFT)
		$(CC) $(OBJSBN) -o $(CHECKER)

bonus:	$(CHECKER)

clean:
		$(RM) $(OBJS) $(OBJSBN)
		make clean -C libft

fclean:	clean
		$(RM) $(NAME) $(CHECKER)
		make fclean -C libft

re:		fclean all

.PHONY:	all clean fclean re