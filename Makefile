NAME = $(addprefix tests/, ft_test)
STD_NAME = $(addprefix tests/, std_test)

NAME_BONUS = $(addprefix tests/, ft_test_bonus)
STD_NAME_BONUS = $(addprefix tests/, std_test_bonus)

HEADER = ./srcs/utils.hpp \
		 ./srcs/iterators.hpp \
		 ./srcs/vector/vector.hpp \
		 ./srcs/vector/vector_iterator.hpp \
		 ./srcs/vector/vector_reverse_iterator.hpp \
		 ./srcs/stack/stack.hpp \
		 ./srcs/map/map.hpp \
		 ./srcs/map/node_tree.hpp \
		 ./srcs/set/node_tree_set.hpp \
		 ./srcs/set/set.hpp \

FT_FILE = ./tests/ft_diff.txt
STD_FILE = ./tests/std_diff.txt

FT_FILE_BONUS = ./tests/ft_diff_bonus.txt
STD_FILE_BONUS = ./tests/std_diff_bonus.txt

SRCS = ./tests/ft_main.cpp 		 
STD_SRCS = ./tests/std_main.cpp

SRCS_BONUS = ./tests/set/main_test_ft_set.cpp 		 
STD_SRCS_BONUS = ./tests/set/main_test_set.cpp

CLANG = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
DIFF = diff

OBJS = $(SRCS:.cpp=.o)
STD_OBJS = $(STD_SRCS:.cpp=.o)

OBJS_BONUS = $(SRCS_BONUS:.cpp=.o)
STD_OBJS_BONUS = $(STD_SRCS_BONUS:.cpp=.o)

all : $(NAME) $(STD_NAME) bonus

$(NAME) : $(OBJS) $(HEADER) 
	$(CLANG) $(FLAGS) -o $@ $(SRCS)

$(STD_NAME) : $(STD_OBJS) $(HEADER)
	$(CLANG) $(FLAGS) -o $@ $(STD_SRCS)

bonus : $(NAME_BONUS) $(STD_NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(HEADER) 
	$(CLANG) $(FLAGS) -Iincludes -o $@ $(SRCS_BONUS)

$(STD_NAME_BONUS) : $(STD_OBJS_BONUS) $(HEADER)
	$(CLANG) $(FLAGS) -Iincludes -o $@ $(STD_SRCS_BONUS)

test :
	$(RM) $(STD_FILE) $(FT_FILE)
	./$(STD_NAME) >> $(STD_FILE)
	./$(NAME) >> $(FT_FILE)
	DIFF $(FT_FILE) $(STD_FILE)

test_bonus :
	$(RM) $(STD_FILE_BONUS) $(FT_FILE_BONUS)
	./$(STD_NAME_BONUS) >> $(STD_FILE_BONUS)
	./$(NAME_BONUS) >> $(FT_FILE_BONUS)
	DIFF $(FT_FILE_BONUS) $(STD_FILE_BONUS)

clean :	
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(STD_OBJS) $(STD_OBJS_BONUS)
	$(RM) $(FT_FILE) $(STD_FILE)
	$(RM) $(FT_FILE_BONUS) $(STD_FILE_BONUS)

fclean : clean
	$(RM) $(NAME) $(STD_NAME)
	$(RM) $(NAME_BONUS) $(STD_NAME_BONUS)

re : fclean all

.PHONY : clean fclean all re bonus test test_bonus