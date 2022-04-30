NAME			=	push_swap
BONUS_NAME		=	checker
LEAKS			=	-fsanitize=address
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

leaks:				$(LIBFT) $(OBJ) 
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) $(CFLAGS) $(LEAKS) $(LIBFT) $(OBJ) $< -o $(NAME)

clean:
					@make -C $(LIBFT_PATH) clean
					@$(RM) $(NAME) $(BONUS_NAME)
fclean:				clean
					@make -C $(LIBFT_PATH) fclean
					@$(RM) -rf $(OBJ) $(OBJ_DIR) $(OBJ_B) $(OBJ_B_DIR)
					@make pig

re:					fclean all

bonus:				$(BONUS_NAME) 

$(BONUS_NAME):			$(LIBFT) $(OBJ_B) $(GNL) $(GNL_HEADER)
					@echo "$(GREEN)Compiling Bonus:$(NORMAL)"
					$(CC) $(CFLAGS) $(LIBFT) $(OBJ_B) $(GNL) $< -o $(BONUS_NAME)

.PHONY:				all clean fclean re bonus

pig:				
					@echo "                    *                                             .                       \n\
                                                                                          \n\
                       °oO#@@@@@@@@#*   ..°°°°°°.  *@@@@@@@@@#O*.                         \n\
                   O@@@@@@@@@@@@@@@@@  @@@@@@@@@@  @@@@@@@@@@@@@@@@o.                     \n\
                  @@@@@@@@@@@@@@@@@@* O@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@                    \n\
                  o@@@@@@@@@@@@@@@@o *@@@@@@@@@@@o O@@@@@@@@@@@@@@@@@°                    \n\
                   .@@@@@@@@@@@@@@  O@@@@@@@@@@@@@° O@@@@@@@@@@@@@#°                      \n\
                @    .O@@@@@@@@@° .@@@@@@@@@@@@@@@@o  #@@@@@@@@o°  °@@o                   \n\
                  O@@*  .*oo*°  °@@@@@@@@@@@@@@@@@@@@*  .°°°.  .o@@@@@@@*  @              \n\
                °@@@@@@@#oo*oO@@@@@@@@@@@@@@@@@@@@@@@@@@#OO##@@@@@@@@@@@@#                \n\
               o@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               \n\
              °@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@              \n\
           @  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @          \n\
             o@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@o            \n\
             @@@@@@@@@@@@@@@°  #@@@@@@@@@@@@*  o@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  °         \n\
            @@@@@@@@@@@@@@@@O.°@@@@@@@@@@@@@#°*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*           \n\
           #@@@@@@@@@@@@@@@@@@@#OOOOOOOOOOO##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#           \n\
          *@@@@@@@@@@@@@@@@@OOOO##OO###OO##OOOO#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           \n\
          @@@@@@@@@@@@@@@@@@O##O#o  O#O  *#O###O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           \n\
          @@@@@@@@@@@@@@@@@@@#OOOOooO##ooOOOOO#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           \n\
          @@@@@@@@@#@@@@@@@@@@@@##@##OO#####@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@°           \n\
          °@@@@@@###@@@@@@@@@@@@@@°#@@@@#.o@@@@@@@@@@@@@@@@@@###@@@@@@@@@@@@@@            \n\
           o@@@@@@@@@@@@@@@@@@@@@@o°°°°°°o@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             \n\
            °@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#              \n\
              o@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*  @            \n\
                .O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*                 \n\
                   .O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@####@@@@#o                    \n\
                        °*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#°..      °  .o@#°                \n\
                   *  °oO* °@@@@@@@@@@@@@@@@@@@@@@@@@@@. ..  ...    @@@@@@O               \n\
                  .  @@@@@° @@@@@@@@@@@@@@@@@@@@@#°...     O@@@@@@  @@@@@@@@              \n\
                     @@@@O .@@@@@@@@@@@@@@@@@@@@* *@@@@@@@@@@@@@@@o o@@@@@@@#             \n\
                      .°  *@@@@@@@@@@@@@@@@@@@@@* o@@@@@@@@@@@@* #@  @@@@@@@@*            \n\
                        @@@@@@@@@@@@@@@@@@@@@@@@@#  .*O#@@@#O*   oo  @@@@@@@@O            \n\
                     . .@@@@@@@@@@@@@@@@@@@@@@@@@@@@O*°....    ....  #@@@@@@@#            \n\
                       °@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O**°°  #@@@@@@@*            \n\
                       .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@° #@@@@@@*             \n\
                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@##o°               \n\
                        O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@o                       \n\
                      °  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#                        \n\
                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      °                  \n\
					pipex compile completed"