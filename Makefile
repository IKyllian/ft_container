VECTOR = ./tests/vector/ft_vector
STACK = ./tests/stack/ft_stack
MAP = ./tests/map/ft_map
SET = ./tests/set/ft_set

STD_VECTOR = ./tests/vector/std_vector
STD_STACK = ./tests/stack/std_stack
STD_MAP = ./tests/map/std_map
STD_SET = ./tests/set/std_set

VECTOR_FILE = ./tests/vector/ft_vector.txt
STACK_FILE = ./tests/stack/ft_stack.txt
MAP_FILE = ./tests/map/ft_map.txt
SET_FILE = ./tests/set/ft_set.txt

STD_VECTOR_FILE = ./tests/vector/real_vector.txt
STD_STACK_FILE = ./tests/stack/real_stack.txt
STD_MAP_FILE = ./tests/map/real_map.txt
STD_SET_FILE = ./tests/set/real_set.txt

HEADER = ./srcs/utils.hpp \
		 ./srcs/iterators.hpp \
		 ./srcs/vector/vector.hpp \
		 ./srcs/vector/vector_iterator.hpp \
		 ./srcs/vector/vector_reverse_iterator.hpp \
		 ./srcs/stack/stack.hpp \
		 ./srcs/map/map.hpp \
		 ./srcs/map/node_tree.hpp \
		 ./srcs/set/node_tree.hpp \
		 ./srcs/set/set.hpp \

VECTOR_SRCS = ./tests/vector/main_test_ft_vector.cpp
STACK_SRCS = ./tests/stack/main_test_ft_stack.cpp
MAP_SRCS = ./tests/map/main_test_ft_map.cpp
SET_SRCS = ./tests/set/main_test_ft_set.cpp

STD_VECTOR_SRCS = ./tests/vector/main_test_vector.cpp
STD_STACK_SRCS = ./tests/stack/main_test_stack.cpp
STD_MAP_SRCS = ./tests/map/main_test_map.cpp
STD_SET_SRCS = ./tests/set/main_test_set.cpp

VECTOR_OBJS = $(VECTOR_SRCS:.cpp=.o)
STACK_OBJS = $(STACK_SRCS:.cpp=.o)
MAP_OBJS = $(MAP_SRCS:.cpp=.o)
SET_OBJS = $(SET_SRCS:.cpp=.o)

STD_VECTOR_OBJS = $(STD_VECTOR_SRCS:.cpp=.o)
STD_STACK_OBJS = $(STD_STACK_SRCS:.cpp=.o)
STD_MAP_OBJS = $(STD_MAP_SRCS:.cpp=.o)
STD_SET_OBJS = $(STD_SET_SRCS:.cpp=.o)

CLANG = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
DIFF = diff
%.o : %.cpp $(HEADER)
	$(CLANG) $(FLAGS) -c $< -o $@

$(VECTOR) : $(VECTOR_OBJS) $(STACK_OBJS) $(MAP_OBJS) $(SET_OBJS) $(STD_VECTOR_OBJS) $(STD_STACK_OBJS) $(STD_MAP_OBJS) $(STD_SET_OBJS) $(HEADER) 
	$(CLANG) $(FLAGS) -o $(VECTOR) $(VECTOR_OBJS)
	$(CLANG) $(FLAGS) -o $(STACK) $(STACK_OBJS)
	$(CLANG) $(FLAGS) -o $(MAP) $(MAP_OBJS)
	$(CLANG) $(FLAGS) -o $(SET) $(SET_OBJS)
	$(CLANG) $(FLAGS) -o $(STD_VECTOR) $(STD_VECTOR_OBJS)
	$(CLANG) $(FLAGS) -o $(STD_STACK) $(STD_STACK_OBJS)
	$(CLANG) $(FLAGS) -o $(STD_MAP) $(STD_MAP_OBJS)
	$(CLANG) $(FLAGS) -o $(STD_SET) $(STD_SET_OBJS)

all : $(VECTOR)

vector :
	$(RM) $(STD_VECTOR_FILE) $(VECTOR_FILE)
	$(STD_VECTOR) >> $(STD_VECTOR_FILE)
	$(VECTOR) >> $(VECTOR_FILE)
	DIFF $(VECTOR_FILE) $(STD_VECTOR_FILE)

stack :
	$(RM) $(STD_STACK_FILE) $(STACK_FILE)
	$(STD_STACK) >> $(STD_STACK_FILE)
	$(STACK) >> $(STACK_FILE)
	DIFF $(STACK_FILE) $(STD_STACK_FILE)

map :
	$(RM) $(STD_MAP_FILE) $(MAP_FILE)
	$(STD_MAP) >> $(STD_MAP_FILE)
	$(MAP) >> $(MAP_FILE)
	DIFF $(MAP_FILE) $(STD_MAP_FILE)

set :
	$(RM) $(STD_SET_FILE) $(SET_FILE)
	$(STD_SET) >> $(STD_SET_FILE)
	$(SET) >> $(SET_FILE)
	DIFF $(SET_FILE) $(STD_SET_FILE)

clean :	
	$(RM) $(VECTOR_OBJS) $(STACK_OBJS) $(MAP_OBJS) $(SET_OBJS)
	$(RM) $(STD_VECTOR_OBJS) $(STD_STACK_OBJS) $(STD_MAP_OBJS) $(STD_SET_OBJS)

fclean : clean
	$(RM) $(VECTOR) $(STACK) $(MAP) $(SET) $(STD_VECTOR) $(STD_STACK) $(STD_MAP) $(STD_SET)
	$(RM) $(VECTOR_FILE) $(STD_VECTOR_FILE)
	$(RM) $(STACK_FILE) $(STD_STACK_FILE)
	$(RM) $(MAP_FILE) $(STD_MAP_FILE)
	$(RM) $(SET_FILE) $(STD_SET_FILE)

re : fclean all

.PHONY : clean fclean all re