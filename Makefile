NAME	=	libftprintf.a

HEAD	=	src/ft_printf.h

CFLAGC	=	-Wall -Wextra -Werror

GCC		=	gcc

AR = ar rcs

SRCS	=	src/ft_printf.c\
			src/print_c.c\
			src/print_i.c\
			src/print_s.c\
			src/print_u.c\
			src/print_u_utils.c\
			src/print_x.c\
			src/print_x_utils.c\
			src/print_p.c\
			src/print_p_utils.c\

OBJS 	= $(SRCS:%.c=%.o)

.c.o:
	$(GCC) $(CFLAGC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@ $(AR) $(NAME) $(OBJS) $(HEAD)
	@make -C ./libft
	@cp ./libft/libft.a $(NAME)
	@ar rcs $(NAME)  $?

all: $(NAME)

bonus: $(NAME)

clean:
	@make -C ./libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -C ./libft fclean 
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re