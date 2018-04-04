CC =	/usr/bin/clang++
RM =	/bin/rm
MAKE =	/usr/bin/make
MKDIR =	/bin/mkdir

NAME = eval_expr

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/objs
CPATH =		$(ROOT)/srcs
HPATH =		$(ROOT)/includes

CFLAGS = -Wall -Werror -Wextra -std=c++98 -I $(HPATH) -g

SRC = Fixed.class.cpp \
	  main.cpp

OFILES = $(patsubst %.cpp, $(OPATH)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@echo "Creating OBJ files"
	@echo "Building $@"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "\033[36mAll is done!\033[0m"

$(OPATH)/%.o: $(CPATH)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "Creating OBJ directory"
	@$(MKDIR) $@

clean:
	@echo "Deleting OBJ files"
	@$(RM) -rf $(OPATH)

fclean: clean
	@echo "Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\033[36mAll clear!\033[0m"

re: fclean all

# lil memo
# $@ = rule's name
# $^ = all the rule dependecies
# $< = only the first dependence
# -j 8 => pour que la lib complie en multi thread ;)


# Color for c
#   reset	"\033[0m"
#   RED  	"\033[31m"
#   GRN  	"\033[32m"
#   YEL  	"\033[33m"
#   BLU  	"\033[34m"
#   MAG  	"\033[35m"
#   CYN  	"\033[36m"
#   WHT  	"\033[37m"
