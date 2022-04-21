NAME	=	push_swap
CHECKER	=	checker
CC		=	gcc
RM		=	rm -f
LIBFT	=	libft/libft.a

SRCS	=	srcs/push_swap.c srcs/push_swap_utils.c srcs/push_swap_utils_2.c srcs/operations.c srcs/operations_2.c srcs/sorting_process.c srcs/sorting_process_2.c $(LIBFT)
OBJS	=	$(SRCS:.c=.o)
SRCSBN	=	srcs/checker.c srcs/push_swap_utils.c srcs/push_swap_utils_2.c srcs/operations.c srcs/operations_2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c $(LIBFT)
OBJSBN	=	$(SRCSBN:.c=.o)

define HEADER_M
                    .__                                         
______  __ __  _____|  |__        ________  _  _______  ______  
\____ \|  |  \/  ___/  |  \      /  ___/\ \/ \/ /\__  \ \____ \ 
|  |_> >  |  /\___ \|   Y  \     \___ \  \     /  / __ \|  |_> >
|   __/|____//____  >___|  /____/____  >  \/\_/  (____  /   __/ 
|__|              \/     \/_____/    \/               \/|__|    
endef
export HEADER_M

define HEADER_B
 _________ .__                   __                 
 \_   ___ \|  |__   ____   ____ |  | __ ___________ 
 /    \  \/|  |  \_/ __ \_/ ___\|  |/ // __ \_  __ \ 
 \     \___|   Y  \  ___/\  \___|    <\  ___/|  | \/
  \______  /___|  /\___  >\___  >__|_ \\\___  >__|   
         \/     \/     \/     \/     \/    \/       
endef
export HEADER_B

all: header_m $(NAME)

header_m:
	@echo "\033[0;32m$$HEADER_M\033[0m\n"

header_b:
	@echo "\033[0;32m$$HEADER_B\033[0m\n"

%.o: %.c
	@ $(CC) -Wall -Wextra -Werror -c $< -o $@

$(LIBFT):
	@echo "\033[0;36m</ Compiling libft >\033[0m"
	@make -C libft

$(NAME): $(OBJS) $(LIBFT)
	@echo "\033[0;36m</ Compiling push_swap >\033[0m"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\033[1;32mPush_swap has been compiled!\033[0m\n"

$(CHECKER): $(OBJSBN) $(LIBFT)
	@echo "\033[0;36m</ Compiling checker >\033[0m"
	@$(CC) $(OBJSBN) -o $(CHECKER)
	@echo "\033[1;32mChecker has been compiled!\033[0m\n"

bonus: header_b $(CHECKER)

clean:
	@$(RM) $(OBJS) $(OBJSBN)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME) $(CHECKER)
	@make fclean -C libft
	@echo "\n\033[0;31m</ EVERYTHING HAS BEEN DELETED! >\033[0m\n"

re: fclean all

.PHONY: all clean fclean re bonus