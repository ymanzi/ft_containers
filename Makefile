# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:05:13 by ymanzi            #+#    #+#              #
#    Updated: 2020/11/22 13:49:15 by ymanzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror 

all: stack queue list map vector

stack:
	$(CXX) $(CXXFLAGS) stack/main.cpp -o stack
	./stack

queue:
	$(CXX) $(CXXFLAGS) queue/main.cpp -o queue
	./queue

list:
	$(CXX) $(CXXFLAGS) list/main.cpp -o list
	./list

map:
	$(CXX) $(CXXFLAGS) map/main.cpp -o map
	./map

vector:
	$(CXX) $(CXXFLAGS) vector/main.cpp -o vector
	./vector

clean:
	rm -f stack queue list map vector

fclean: clean

re: fclean all