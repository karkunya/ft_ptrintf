NAME		= libftprintf.a
SRC_DIR		= srcs/
SRCB_DIR		= srcsbonus/
LIBFT_DIR	= libft/
LIBFT		= libft.a
INCLDS		= includes/
INCLDSD	= includesbonus/
SRC			= $(SRC_DIR)ft_printf.c \
			  $(SRC_DIR)treat_flags.c \
			  $(SRC_DIR)treat_char.c	\
			  $(SRC_DIR)treat_s.c		\
			  $(SRC_DIR)treat_persent.c	\
			  $(SRC_DIR)treat_digit.c	\
			  $(SRC_DIR)treat_x.c		\
			  $(SRC_DIR)treat_xupper.c	\
			  $(SRC_DIR)treat_u.c		\
			  $(SRC_DIR)treat_p.c		\
			  $(SRC_DIR)utils.c			\
			  $(SRC_DIR)ft_itoap.c

SRCB		= $(SRCB_DIR)ft_printf_bonus.c \
			  $(SRCB_DIR)treat_flags_bonus.c \
			  $(SRCB_DIR)treat_char_bonus.c	\
			  $(SRCB_DIR)treat_s_bonus.c		\
			  $(SRCB_DIR)treat_persent_bonus.c	\
			  $(SRCB_DIR)treat_digit_bonus.c	\
			  $(SRCB_DIR)treat_x_bonus.c		\
			  $(SRCB_DIR)treat_xupper_bonus.c	\
			  $(SRCB_DIR)treat_u_bonus.c		\
			  $(SRCB_DIR)treat_p_bonus.c		\
			  $(SRCB_DIR)utils_bonus.c			\
			  $(SRCB_DIR)ft_itoap_bonus.c
OBJ			= $(SRC:.c=.o)
OBJB		= $(SRCB:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -I$(INCLDS) -I$(INCLDSD) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)

bonus:	$(OBJB)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJB)
all:	$(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJB)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY:	all clean fclean re
