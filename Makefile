# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 18:51:39 by mamuller          #+#    #+#              #
#    Updated: 2021/06/01 18:51:39 by mamuller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SRCD		= ./srcs/
SRC			= ft_printf.c ft_format_handler.c ft_printf_utils.c
# Command to add the source folder prefix (instead of having it added manually to SRC)
SRCF		= $(addprefix $(SRCD),$(SRC))
OBJD		= ./objs/
# for every SRCF file which is an .c file an o file will be created according to the implicit rule (see $(OBJD)%.o: $(SRCD)%.c)
OBJF 		= $(SRCF:$(SRCD)%.c=$(OBJD)%.o)
BUILD 		= $(OBJF:$(OBJD)%.o)

NAME		= libftprintf.a
HEADD		= ./incl/
HEADF		= ft_printf.h

LIBFTD		= ./libft/
LIBFT_OBJD	= objs
LIBFT_SRCD	= srcs/
LIBFTL		= libft.a

LIBFT_OBJF    = ${LIBFTD}${LIBFT_OBJD}/*.o
LIBFT_MAKE    = make -C ${LIBFTD}

#if to the respective c file in the source directory no matching o file in the object
#directory is available, then create it according to the following rules:
#Note: the object directory will only be created if not existing already. -p flag throws no errors when already there
$(OBJD)%.o: $(SRCD)%.c 
	@mkdir -p $(OBJD)
	$(CC) $(CFLAGS) -I ${HEADD} -c -o $@ $<

$(NAME):	${OBJF}
			make libftmake
			ar rcs ${NAME} ${OBJF} ${LIBFT_OBJF}

all:		${NAME}

libftmake:
			${LIBFT_MAKE}

clean:		
			${RM} ${OBJD}*.o
			make -C ${LIBFTD} clean

fclean:		clean
			${RM} ${NAME}
			${RM} a.out
			${RM} ${NAME} ${LIBFTD}${LIBFTL}

re:			fclean all

.PHONY:		all clean fclean re