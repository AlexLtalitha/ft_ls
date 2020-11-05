# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoze <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 12:32:37 by gdoze             #+#    #+#              #
#    Updated: 2020/02/21 16:52:33 by ltalitha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libls.a

SRCS= srcs/add_new_file.c \
		srcs/display_all.c \
		srcs/display_detailed_list.c \
	    srcs/display_list.c \
		srcs/display_list_items.c \
		srcs/main.c \
		srcs/misc.c \
		srcs/parsing.c \
		srcs/sort_list.c \

OBJECTS=*.o

INCLUDES=srcs/

all: $(NAME)

$(NAME):
	@make -C libft/ re
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS) libft/*.o
	ranlib $(NAME)

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
