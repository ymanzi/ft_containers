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


COLOR_RESET						= \x1b[0m
COLOR_LIGHT_GREEN				= \x1b[92m
COLOR_LIGHT_YELLOW				= \x1b[93m
COLOR_LIGHT_MAGENTA				= \x1b[95m
COLOR_WHITE						= \x1b[97m

MAKE_B						=  " $(COLOR_LIGHT_MAGENTA)\n[$(COLOR_LIGHT_GREEN) MAKE TEST $(COLOR_LIGHT_MAGENTA)] "
MAKE_C						=  " $(COLOR_LIGHT_MAGENTA)[ FCLEAN ]"

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror
S_SRCS = utils/stack.cpp
L_SRCS = utils/list.cpp
V_SRCS = utils/vector.cpp
Q_SRCS = utils/queue.cpp
M_SRCS = utils/map.cpp
STACK = stack_t
QUEUE = queue_t
LIST = list_t
VECTOR = vector_t
MAP = map_t

all: stack queue list map vector

stack: $(STACK)

$(STACK):
	@echo $(MAKE_B) "$(COLOR_WHITE) $(COLOR_LIGHT_YELLOW) STACK $(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) $(S_SRCS) -o $(STACK)
	@./$(STACK)

queue: $(QUEUE)

$(QUEUE):
	@echo $(MAKE_B) "$(COLOR_WHITE) $(COLOR_LIGHT_YELLOW) QUEUE $(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) $(Q_SRCS) -o $(QUEUE)
	@./$(QUEUE)

list: $(LIST)

$(LIST):
	@echo $(MAKE_B) "$(COLOR_WHITE) $(COLOR_LIGHT_YELLOW) LIST $(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) $(L_SRCS) -o $(LIST)
	@./$(LIST)

map: $(MAP)

$(MAP):
	@echo $(MAKE_B) "$(COLOR_WHITE) $(COLOR_LIGHT_YELLOW) MAP $(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) $(M_SRCS) -o $(MAP)
	@./$(MAP)

vector: $(VECTOR)

$(VECTOR):
	@echo $(MAKE_B) "$(COLOR_WHITE) $(COLOR_LIGHT_YELLOW) VECTOR $(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) $(V_SRCS) -o $(VECTOR)
	@./$(VECTOR)

clean:
	@echo $(MAKE_C)  "$(COLOR_RESET)"
	@rm -f $(LIST) $(QUEUE) $(STACK) $(VECTOR) $(MAP)

fclean: clean

re: fclean all