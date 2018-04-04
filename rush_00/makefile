SRCS_PATH = ./srcs/
SRCS_FILES = \
	main.cpp\
	AEntity.cpp\
	Shoot.cpp\
	ShootList.cpp\
	ACharacter.cpp\
	Player.cpp\
	Screen.cpp\
	Enemy.cpp\
	Horde.cpp\
	Game.cpp

OBJS_PATH = ./objs/
OBJS_FILES = $(SRCS_FILES:.cpp=.o)

INC_PATH = ./includes/
INC_NAME = $(addprefix $(EXEC_NAME), .h

# LIB_PATH = ./libft/
# LIB_NAME = ./libft/libft.a

EXEC_NAME = ft_retro

CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
CURSESFLAG = -lncurses

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))
# LIB = $(addprefix -L, $(LIB_PATH))
INC = $(addprefix -I, $(INC_PATH))


all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(CURSESFLAG) -o $(EXEC_NAME) $(OBJS) -g
	@echo 'Compilation du $(EXEC_NAME) [OK]'

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@mkdir $(OBJS_PATH) 2> /dev/null || echo '' > /dev/null
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || echo '' > /dev/null

fclean: clean
	@rm -f $(EXEC_NAME)
	@echo 'Suppression du $(EXEC_NAME) [OK]'

re: fclean all

norme:
	norminette $(SRCS)
	norminette $(INC_PATH)$(INC_NAME)
