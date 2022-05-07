SRCS	= ft_bzero.c\
		ft_strlen.c\
		ft_memccpy.c\
		ft_memcpy.c\
		ft_memchr.c\
		ft_memset.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_strchr.c\
		ft_strlcpy.c\
		ft_strncmp.c\
		ft_strrchr.c\
		ft_atoi.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_isprint.c\
		ft_isascii.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_strlcat.c\
		ft_strnstr.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_lstadd_front.c\
		ft_lstlast.c\
		ft_lstadd_back.c\

OBJC	= ${SRCS:.c=.o}

NAME	= libft.a

GCC 	= gcc
AR		= ar rcs
RM		= rm -f

FLAGS	= -Wall -Wextra -Werror

.c.o:
			${GCC} ${FLAGS} -c $< -o ${<:.c=.o}


$(NAME):	${OBJC}
			@${AR} ${NAME} ${OBJC} libft.h

all:		${NAME}

clean:		
			@${RM} ${OBJC}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re