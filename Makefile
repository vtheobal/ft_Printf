NAME	=	libftprintf.a

HEAD	=	ft_printf.h

CFLAGC	=	-Wall -Wextra -Werror

GCC		=	gcc

AR = ar rcs

SRCS	=	ft_printf.c\
			print_c.c\
			print_i.c\
			print_s.c\
			print_u.c\
			print_u_utils.c\
			print_x.c\
			print_x_utils.c\
			print_p.c\
			print_p_utils.c\

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