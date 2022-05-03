NAME			=	push_swap
BONUS_NAME		=	checker
CC			=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM			=	rm -rf

HEADER_DIR		=	include
HEADER			=	pushswap
HEADERS			=	$(addprefix $(HEADER_DIR)/, $(addsuffix .h, $(HEADER)))

SRC_DIR			=	src
SRC			=	pushswap ps_sa_sb_ss ps_rra_rrb_rrr ps_ra_rb_rr \
					ps_pa_pb ps_is_sorted ps_exit ps_deter_algo \
					ps_deepcopy ps_checkvalid ps_radix_sort ps_smallsort \
					ps_my_sort ps_ss_rr_rrr

BONUS_H			=	include/checker.h
BONUS_DIR		=	bonus
BONUSS			=	checker ch_checkvalid ch_exit ch_instruction ch_is_sorted \
					ch_pa_pb ch_ra_rb_rr ch_rra_rrb_rrr ch_sa_sb_ss

BONUSSS 		=	$(addprefix $(BONUS_DIR)/, $(addsuffix .c, $(BONUSS)))

OBJ_B_DIR		=	obj_b
OBJ_B			=	$(addprefix $(OBJ_B_DIR)/, $(addsuffix .o, $(BONUSS)))

SRCS 			=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

OBJ_DIR			=	obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

GNL_PATH		=	./gnl
GNL_HEADER		=	$(GNL_PATH)/get_next_line.h
GNL			=	$(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m
SALMON = \033[38;5;174m
HOTPINK = \033[38;5;168m


all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) $(CFLAGS) $(LIBFT) $(OBJ) $< -o $(NAME)

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c $(HEADERS)
					@mkdir -p $(OBJ_DIR)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) -c $< -o $@ 

$(OBJ_B_DIR)/%.o:		$(BONUS_DIR)/%.c $(BONUS_H)
					@mkdir -p $(OBJ_B_DIR)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) -c $< -o $@ 			
					
$(LIBFT):
					@make -C $(LIBFT_PATH) all

clean:
					@make -C $(LIBFT_PATH) clean
					@$(RM) $(NAME) $(BONUS_NAME)
					@$(RM) tester tester2 *.log log_error
					@$(RM) push_swap_visualizer
fclean:				clean
					@make -C $(LIBFT_PATH) fclean
					@$(RM) -rf $(OBJ) $(OBJ_DIR) $(OBJ_B) $(OBJ_B_DIR)
					@make pig

re:					fclean all

bonus:				$(BONUS_NAME)

load:
				curl -O https://projects.intra.42.fr/uploads/document/document/8341/checker_Mac

test:				all bonus
					@./tester/tester.sh ./ 3 10
					@./tester/tester.sh ./ 5 10
					@./tester/tester.sh ./ 100 10
					@./tester/tester.sh ./ 500 10
					
test2:				all bonus
					@cp push_swap ./tester2/
					@./tester2/tester.sh

viz:				
					@git clone https://github.com/o-reo/push_swap_visualizer.git

clone:
					@git clone https://github.com/lmalki-h/push_swap_tester.git tester
					@git clone https://github.com/laisarena/push_swap_tester.git tester2

$(BONUS_NAME):			$(LIBFT) $(OBJ_B) $(GNL) $(GNL_HEADER)
					@echo "$(GREEN)Compiling Bonus:$(NORMAL)"
					$(CC) $(CFLAGS) $(LIBFT) $(OBJ_B) $(GNL) $< -o $(BONUS_NAME)

.PHONY:				all clean fclean re bonus test viz clone load

pig:				
					@echo "$(SALMON)                         .....            :!????7!^:\n\
                   .^!J5PGGBGG5::~!77?77~:G&&&&&&&&#GY!.\n\
                 .?G#&&&&&&&&&B^G&&&&&&&B^G&&&&&&&&&&&#^\n\
                 .P&&&&&&&&&&#!?&&&&&&&&&J~B&&&&&&&&#Y^\n\
                  .JB&&&&&&&G!J&&&&&&&&&&&Y!YB###B5J??^\n\
                   ~??5GGG5?7P&&&&&&&&&&&&&#5JJJJJ5G&&#5^\n\
                 .J&&BPYYY5G&&&&&&&&&&&&&&&&&&&#&&&&&&&&#~\n\
                .Y&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&B^\n\
                !&&&&&&&&&&&&BG#&&&&&&&&&BJY#&&&&&&&&&&&&&P.\n\
               .5&&&&&&&&&&&#^ ?&&&&&&&&&5:^B&&&&&&&&&&&&&&Y.\n\
               ^#&&&&&&&&&&&&BPB$(HOTPINK)#BGGGGGGGBB$(SALMON)#&&&&&&&&&&&&&&&&J.\n\
              .5&&&&&&&&&&&&&$(HOTPINK)#BPPPP5PP55PPPPB$(SALMON)&&&&&&&&&&&&&&&&!\n\
              7&&&&&&&&&&&&&&$(HOTPINK)#PPPP?^5P!~PPPPG&$(SALMON)&&&#######&&&&&5.\n\
             .Y&&&&&#######&&&$(HOTPINK)BGPP55PPP5PPGB#$(SALMON)&&&#BBGBGBB##&&&B:\n\
              J&&&##BBBBBB##&&&&$(HOTPINK)#BBBBBB#PB$(SALMON)&&&&&##BGGPPGBB#&&&P.\n\
              :B&&#BBGPPGGB##&&&&#JYPPPJ?B&&&&&&#BBGGGBB##&&#!\n\
               ^G&&#BBGGGBB#&&&&&&#BPPGB&&&&&&&&########BBP!.\n\
                .?G########&&&&&&&&&&&&&&&&&&&&&&&&#G5YJJJYY5PY!.\n\
                   ^7J5GB#&&&&&&&&&&&&&&&&&&&&&&&&#YJPG##&&&&&@P.\n\
               :~!!777777?B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GJ:\n\
             .J#&&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBP5?!^.\n\
             .7B#&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&Y^.\n\
               .^~!777777Y#&&&&&&&&&&&&&&&&&&&&&&&&&&&?\n\
                        ~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&P.\n\
                        ^#&&&&&&&&&&&&&&&&&&&&&&&&&&&&G.\n\
                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~^\n\
					  push_swap$(NORMAL)"