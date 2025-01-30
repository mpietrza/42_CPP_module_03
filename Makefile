# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:29:38 by mpietrza          #+#    #+#              #
#    Updated: 2025/01/30 17:19:05 by mpietrza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror #-g -O0
STD = -std=c++98
RM = rm -rf

#DIRECTIORIES
DIR_OBJS = ./objs/

#COLORS
DEF_COLOR = "\033[39m"
GRAY = "\033[30m"
R = "\033[31m"
G = "\033[32m"
Y = "\033[33m"
B = "\033[34m"
M = "\033[35m"
C = "\033[36m"
W = "\033[37m"

#SOURCES
SRC		= Fixed.cpp \
		  ClapTrap.cpp \
		  main.cpp 

OBJS	= $(addprefix $(DIR_OBJS), $(SRC:.cpp=.o))

DEPS	= $(OBJS:.o=.d)

all:	$(DIR_OBJS) $(NAME)

-include $(DEPS)

$(DIR_OBJS)%.o : %.cpp
	@echo $(B)Compiling [$<]... $(DEF_COLOR)
	@printf $(Y) 
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $< 
	@echo $(DEF_COLOR)

$(DIR_OBJS):
	@echo $(B)Creating directory: $(DIR_OBJS)
	@printf $(Y)
	mkdir -p $(DIR_OBJS)
	@echo Directory 'objs' generated succesfully! $(DEF_COLOR)


$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(G)ClapTrap compiled successfully! $(DEF_COLOR)

clean:
	@echo $(GRAY)
	$(RM) $(OBJS) $(DEPS) $(DIR_OBJS)
	@echo $(G)ClapTrap object files erased successfully! $(DEF_COLOR)

fclean: clean
	@echo $(GRAY)
	$(RM) $(NAME)
	@echo $(G)ClapTrap executable files erased succesfully! $(DEF_COLOR)

re: fclean all
	@echo $(G)Erased and recompiled every file of ClapTrap successfully! $(DEF_COLOR)

.PHONY: all clean fclean re
