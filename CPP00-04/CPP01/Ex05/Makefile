#   NAME
NAME = Client_Aigri

#---------------#
#	includes
#---------------#
UTILS =		utils
INCLUDES =	includes

#--------------------------------------#
#		Commande
#-----------------------#
RM = rm -fr
CC = c++
FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)
FLAG_CPP = -std=c++98
# FLAG_READLINE = -lreadline
# FLAG_PHILO = -lpthread -D_REENTRANT

#--------------------------------------#
#       directory
#-----------------------#
SRCS = srcs
OBJS = objs

#--------------------------------------#
#       Colors
#-----------------------#
C_B = \033[0;30m
C_R = \033[1;31m
C_G = \033[1;32m
C_Y = \033[0;33m
C_BU = \033[0;34m
C_M = \033[0;35m
C_C = \033[0;36m
C_W = \033[0;37m
RESET = \033[0m

#--------------------------------------#
#		File
#-----------------------#
FILE_CPP =	

SRC = $(addprefix $(SRCS)/, $(FILE_CPP))
OBJ = $(patsubst %.cpp, $(OBJS)/%.o, $(FILE_CPP))

#--------------------------------------#
#		Rules
#-----------------------#
all : $(NAME)
	@echo "$(C_G)Compilation $(NAME) STATUS [OK]$(RESET)"

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(FLAG_CPP) -o $(NAME) main.cpp $(OBJ)

$(OBJS)/%.o : $(SRCS)/%.cpp
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) $(FLAG_CPP) -c $< -o $@
	@echo "$(C_B)loading : $(RESET)$< $(C_G)[OK]$(RESET)"

clean :
	@$(RM) $(OBJS)
	@echo "$(C_R)FILE '*.o' for $(NAME) deleted$(RESET)"

fclean :
	@$(RM) $(NAME)
	@$(RM) $(OBJS)
	@echo "$(C_W)FILE '*.o' for $(C_R)$(NAME) deleted$(RESET)"
	@echo "Projet $(C_R)$(NAME) deleted$(RESET)"

re : fclean all

.PHONY : re clean fclean all
