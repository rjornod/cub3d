
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = -rcs

SRCS =  ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_strlcpy.c ft_tolower.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_strtrim.c ft_toupper.c \
		ft_calloc.c  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c\
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_substr.c\
		ft_strmapi.c  ft_strncmp.c ft_strcmp.c ft_strnstr.c ft_strrchr.c ft_split.c\

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = libft.a

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

$(OBJS): %.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

$(OBJS_BONUS): %.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

bonus: ${OBJS} ${OBJS_BONUS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS} ${OBJS_BONUS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY:  all clean fclean re