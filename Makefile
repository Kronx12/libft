CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=./allocations/ft_bzero.c \
	 ./allocations/ft_calloc.c \
	 ./allocations/ft_memccpy.c \
	 ./allocations/ft_memchr.c \
	 ./allocations/ft_memcmp.c \
	 ./allocations/ft_memcpy.c \
	 ./allocations/ft_memmove.c \
	 ./allocations/ft_memset.c \
	 ./allocations/ft_strdup.c \
	 ./checker/ft_allisascii.c \
	 ./checker/ft_allisalpha.c \
	 ./checker/ft_allisdigit.c \
	 ./checker/ft_allisalnum.c \
	 ./checker/ft_allisprint.c \
	 ./checker/ft_isascii.c \
	 ./checker/ft_isalpha.c \
	 ./checker/ft_isdigit.c \
	 ./checker/ft_isalnum.c \
	 ./checker/ft_isprint.c \
	 ./checker/ft_strchr_chr.c \
	 ./checker/ft_strchr_int.c \
	 ./checker/ft_strrchr_chr.c \
	 ./checker/ft_strrchr_int.c \
	 ./common_functions/ft_additional_functions.c \
	 ./common_functions/ft_apply_flag.c \
	 ./common_functions/ft_fill_struct.c \
	 ./common_functions/ft_functions.c \
	 ./common_functions/ft_init_struct.c \
	 ./common_functions/ft_printf.c \
	 ./common_functions/get_next_line.c \
	 ./common_functions/get_next_line_utils.c \
	 ./converters/ft_atoi.c \
	 ./converters/ft_ctos.c \
	 ./converters/ft_itoa.c \
	 ./list_functions/ft_free_strs.c \
	 ./list_functions/ft_free_strs_tab.c \
	 ./list_functions/ft_lstnew_bonus.c \
	 ./list_functions/ft_lstadd_front_bonus.c \
	 ./list_functions/ft_lstsize_bonus.c \
	 ./list_functions/ft_lstlast_bonus.c \
	 ./list_functions/ft_lstadd_back_bonus.c \
	 ./list_functions/ft_lstdelone_bonus.c \
	 ./list_functions/ft_lstclear_bonus.c \
	 ./list_functions/ft_lstiter_bonus.c \
	 ./list_functions/ft_lstmap_bonus.c \
	 ./printers/ft_putchar_fd.c \
	 ./printers/ft_putstr_fd.c \
	 ./printers/ft_putendl_fd.c \
	 ./printers/ft_putnbr_fd.c \
	 ./printers/ft_putchar.c \
	 ./printers/ft_putstr.c \
	 ./printers/ft_putendl.c \
	 ./printers/ft_putnbr.c \
	 ./str_functions/ft_toupper.c \
	 ./str_functions/ft_tolower.c \
	 ./str_functions/ft_strlen.c \
	 ./str_functions/ft_strnlen.c \
	 ./str_functions/ft_strncmp.c \
	 ./str_functions/ft_strcpy.c \
	 ./str_functions/ft_strlcpy.c \
	 ./str_functions/ft_strlcat.c \
	 ./str_functions/ft_strnstr.c \
	 ./str_functions/ft_substr.c \
	 ./str_functions/ft_strjoin.c \
	 ./str_functions/ft_strtrim.c \
	 ./str_functions/ft_split.c \
	 ./str_functions/ft_strmapi.c \
	 ./str_functions/ft_replace.c \
	 ./str_functions/ft_strfjoin.c \
	 ./str_functions/ft_strcmp.c \
	 ./str_functions/ft_count_char.c
OBJS=$(SRCS:.c=.o)
INC=libft.h
RM=rm -f
	
%.c%.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) -g

all:		$(NAME)

$(OBJS):	$(INC)

$(NAME): 	$(INC) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) libft.ghc.h

fclean: 	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re
