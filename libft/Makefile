# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/14 15:21:40 by lvergero          #+#    #+#              #
#    Updated: 2015/01/12 13:19:51 by lvergero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME 	=	libft.a

#General Options
CC		=	gcc
AR 		=	ar
CFLAGS	=	-Wall -Wextra -Werror
ARFLAGS	=	-r -c -s
RM		=	/bin/rm

#Pathways
SRC_P	=	./
OBJ_P	=	./

#Display files
SRCS 	+=	$(SRC_P)ft_putchar.c
SRCS 	+=	$(SRC_P)ft_putcharendl.c
SRCS 	+=	$(SRC_P)ft_putendl.c
SRCS 	+=	$(SRC_P)ft_putnbr.c
SRCS	+=	$(SRC_P)ft_putnbrendl.c
SRCS 	+=	$(SRC_P)ft_putstr.c

#Modify from file descriptor files
SRCS 	+=	$(SRC_P)ft_putchar_fd.c
SRCS 	+=	$(SRC_P)ft_putendl_fd.c
SRCS 	+=	$(SRC_P)ft_putnbr_fd.c
SRCS 	+=	$(SRC_P)ft_putstr_fd.c

#Character analysis and modification files
SRCS 	+=	$(SRC_P)ft_isalnum.c
SRCS 	+=	$(SRC_P)ft_isalpha.c
SRCS 	+=	$(SRC_P)ft_isascii.c
SRCS 	+=	$(SRC_P)ft_isdigit.c
SRCS 	+=	$(SRC_P)ft_isprint.c
SRCS 	+=	$(SRC_P)ft_tolower.c
SRCS 	+=	$(SRC_P)ft_toupper.c

#String analysis and modification files
SRCS 	+=	$(SRC_P)ft_atoi.c
SRCS 	+=	$(SRC_P)ft_itoa.c
SRCS 	+=	$(SRC_P)ft_strcat.c
SRCS 	+=	$(SRC_P)ft_strchr.c
SRCS 	+=	$(SRC_P)ft_strclr.c
SRCS 	+=	$(SRC_P)ft_strcmp.c
SRCS 	+=	$(SRC_P)ft_strcpy.c
SRCS 	+=	$(SRC_P)ft_strdel.c
SRCS 	+=	$(SRC_P)ft_strdup.c
SRCS 	+=	$(SRC_P)ft_strequ.c
SRCS 	+=	$(SRC_P)ft_striter.c
SRCS 	+=	$(SRC_P)ft_striteri.c
SRCS 	+=	$(SRC_P)ft_strjoin.c
SRCS 	+=	$(SRC_P)ft_strlcat.c
SRCS 	+=	$(SRC_P)ft_strlen.c
SRCS 	+=	$(SRC_P)ft_strmap.c
SRCS 	+=	$(SRC_P)ft_strmapi.c
SRCS 	+=	$(SRC_P)ft_strncat.c
SRCS 	+=	$(SRC_P)ft_strncmp.c
SRCS 	+=	$(SRC_P)ft_strncpy.c
SRCS 	+=	$(SRC_P)ft_strnequ.c
SRCS 	+=	$(SRC_P)ft_strnew.c
SRCS 	+=	$(SRC_P)ft_strnstr.c
SRCS 	+=	$(SRC_P)ft_strsplit.c
SRCS 	+=	$(SRC_P)ft_strrchr.c
SRCS 	+=	$(SRC_P)ft_strstr.c
SRCS 	+=	$(SRC_P)ft_strsub.c
SRCS 	+=	$(SRC_P)ft_strtrim.c
SRCS 	+=	$(SRC_P)ft_strtrimchar.c

#Array analysis and modification files
SRCS 	+=	$(SRC_P)ft_arrayjoin.c
SRCS 	+=	$(SRC_P)ft_arraydup.c
SRCS 	+=	$(SRC_P)ft_int_arrayjoin.c
SRCS 	+=	$(SRC_P)ft_int_arraydup.c
SRCS 	+=	$(SRC_P)ft_intptrdup.c

#Memory analysis and modification files
SRCS 	+=	$(SRC_P)ft_bzero.c
SRCS 	+=	$(SRC_P)ft_memalloc.c
SRCS 	+=	$(SRC_P)ft_memchr.c
SRCS 	+=	$(SRC_P)ft_memcmp.c
SRCS 	+=	$(SRC_P)ft_memcpy.c
SRCS 	+=	$(SRC_P)ft_memccpy.c
SRCS 	+=	$(SRC_P)ft_memdel.c
SRCS 	+=	$(SRC_P)ft_memmove.c
SRCS 	+=	$(SRC_P)ft_memset.c

#List analysis and modification files
SRCS 	+=	$(SRC_P)ft_lstadd.c
SRCS 	+=	$(SRC_P)ft_lstdel.c
SRCS 	+=	$(SRC_P)ft_lstdelone.c
SRCS 	+=	$(SRC_P)ft_lstiter.c
SRCS 	+=	$(SRC_P)ft_lstmap.c
SRCS 	+=	$(SRC_P)ft_lstnew.c

#Get Next Line
SRCS	+=	$(SRC_P)get_next_line.c

#Other file definitions
OBJS 	+=	$(subst .c,.o,$(subst $(SRC_P),$(OBJ_P),$(SRCS)))

#Display
MSG_GREEN	=	\033[1;33;32m
MSG_YELLOW	=	\033[1;33;33m
MSG_BOLD	=	\033[1m
MSG_STD 	=	\033[0m
CLEAR		=	\033[2K
UP 			=	\033[A

#Rules
all:			$(NAME)

$(NAME):		$(OBJS)
	@echo "$(MSG_BOLD)\nLinking objects into library$(MSG_STD)"
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "$(MSG_BOLD)SUCCESS$(MSG_STD)"

$(OBJ_P)%.o:	$(SRC_P)%.c
	@echo "$(CLEAR)Currently pre-processing, compiling and assembling $(MSG_YELLOW)$<$(MSG_STD) to $(MSG_GREEN)$@$(MSG_STD)$(UP)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo "$(MSG_BOLD)Removing all previously created objects$(MSG_STD)"
	@$(RM) -f $(OBJS)

fclean:			clean
	@echo "$(MSG_BOLD)Removing previously created library$(MSG_STD)"
	@$(RM) -f $(NAME)

re: 			fclean all
