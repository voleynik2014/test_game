# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voliynik <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 16:30:03 by voliynik          #+#    #+#              #
#    Updated: 2017/05/20 19:51:51 by voliynik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAMELIB = libft.a

SRC	=	main.c	\
		do_fire.c	\
		ft_move.c	\
		player.c

OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC		= gcc
RM 		= rm -f
CFLAGS = -Wall -Werror -Wextra -O3 -I ./includes -I /usr/X11/include
MLXFLAGS = -L/usr/X11/lib -lmlx -lX11 -lXext

LIBDIR  = ./libft/
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@echo "creating dir: obj/"
	@mkdir -p $(LIBDIR)
	@echo "creating dir: libft/"
	@printf "\x1b[33mCreating project:\x1b[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC)  $(CFLAGS) -I $(INCDIR) -c $< -o $@ 
	@printf '\033[0;34m[\033[0;32m✔\033[0;34m]\033[0m' 

$(NAME): $(NAMELIB) $(OBJ)
	@$(CC) $(MLXFLAGS) -o $(NAME) $(OBJ) -L. -lft
	@echo "\n\x1b[32mLem-in has been created\x1b[0m"

$(NAMELIB):
	@cd $(LIBDIR); make; make clean; mv $(NAMELIB) ../;
	@printf '\n'

clean:
	@echo "Delete old obj"
	@rm -rf $(OBJDIR)

fclean: clean
	@$(RM) $(NAME) $(NAMELIB)

re: fclean all
