# COLORS
_RED		=	\e[1;31m
_GREEN		=	\e[1;32m
_YELLOW		=	\e[1;33m
_BLUE		=	\e[1;34m
_END		=	\e[1;0m

# Compilation
CLANG =			clang++

# Compilation flags
CLANGFLAGS =	-Werror -Wall -Wextra


all:			list map vector queue stack

list:			
				@$(CLANG) $(CLANGFLAGS) sources/mainList.cpp -I includes -o testList
				@printf "$(_GREEN)All done for list!$(_END)\n"

map:			
				@$(CLANG) $(CLANGFLAGS) sources/mainMap.cpp -I includes -o testMap
				@printf "$(_GREEN)All done for map!$(_END)\n"

vector:			
				@$(CLANG) $(CLANGFLAGS) sources/mainVector.cpp -I includes -o testVector
				@printf "$(_GREEN)All done vector!$(_END)\n"

queue:			
				@$(CLANG) $(CLANGFLAGS) sources/mainQueue.cpp -I includes -o testQueue
				@printf "$(_GREEN)All done for queue!$(_END)\n"

stack:			
				@$(CLANG) $(CLANGFLAGS) sources/mainStack.cpp -I includes -o testStack
				@printf "$(_GREEN)All done stack!$(_END)\n"

fclean:			clean

clean:
				@rm -rf testList
				@rm -rf testMap
				@rm -rf testVector
				@rm -rf testQueue
				@rm -rf testStack
				@printf "$(_RED)Deleting all tester </3\n$(_END)"

re:				fclean all

.PHONY:			all clean fclean re