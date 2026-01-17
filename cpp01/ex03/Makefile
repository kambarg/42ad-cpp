# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 10:13:49 by gkambarb          #+#    #+#              #
#    Updated: 2026/01/17 15:27:49 by gkambarb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         ./$(NAME)

.PHONY: all clean fclean re valgrind