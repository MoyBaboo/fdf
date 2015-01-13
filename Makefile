# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvergero <lvergero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/30 17:12:12 by lvergero          #+#    #+#              #
#    Updated: 2015/01/13 15:01:21 by lvergero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME 		=	fdf

# General Options
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
IFLAGS		=	-I $(P_INC)
CLIBFLAGS	=	-L$(P_LIB) -lft
MLXFLAGS	=	-L/usr/X11/lib -lmlx -lXext -lX11
RM			=	/bin/rm

# Directories
P_SRC	=	./srcs/
P_OBJ	=	./objs/
P_INC	=	./includes/
P_LIB	=	./libft/

# Files
SRCS 	+=	$(P_SRC)main.c
SRCS 	+=	$(P_SRC)get_map.c
SRCS 	+=	$(P_SRC)struct_init.c
SRCS 	+=	$(P_SRC)start_mlx.c
SRCS 	+=	$(P_SRC)draw_horiz.c
SRCS 	+=	$(P_SRC)draw_vert.c
SRCS 	+=	$(P_SRC)hooks.c

# Other definitions
OBJS 	=	$(subst .c,.o,$(subst $(P_SRC),$(P_OBJ),$(SRCS)))
LIB		=	$(P_LIB)libft.a

# Display
MSG_GREEN	=	\033[1;33;32m
MSG_YELLOW	=	\033[1;33;33m
MSG_BOLD	=	\033[1m
MSG_STD 	=	\033[0m
CLEAR		=	\033[2K
UP 			=	\033[A

#Rules
all:			$(NAME)

$(NAME):		$(OBJS) $(LIB)
	@echo "$(MSG_BOLD)\nLinking to binary$(MSG_STD)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(IFLAGS) $(CLIBFLAGS) $(MLXFLAGS) $(GDBFLAGS)
	@echo "$(MSG_BOLD)SUCCESS$(MSG_STD)"

$(P_OBJ)%.o:	$(P_SRC)%.c
	@echo "$(CLEAR)Currently pre-processing, compiling and assembling $(MSG_YELLOW)$<$(MSG_STD) to $(MSG_GREEN)$@$(MSG_STD)$(UP)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

clean:
	@echo "$(MSG_BOLD)Removing .o$(MSG_STD)"
	@$(RM) -f $(OBJS)

fclean:			clean
	@echo "$(MSG_BOLD)Removing all$(MSG_STD)"
	@$(RM) -f $(NAME)
	@make -C $(P_LIB) fclean

$(LIB):
	@echo "$(MSG_BOLD)\nMaking library$(MSG_STD)"
	@make -C $(P_LIB)

re: 			fclean all

