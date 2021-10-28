NAME		=	a.out

SRC_DIR		=	sources

OBJS_DIR	=	build

SRC_EXT		=	c

SRCS		=	$(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))

OBJS		=	$(patsubst $(SRC_DIR)/%,$(OBJS_DIR)/%,$(SRCS:.$(SRC_EXT)=.o))

RM		=	-rm -rf

ECHO		=	echo

YELLOW		=	"" #"\033[01;33m"

GREEN		=	"" #"\033[01;32m"

DEFAULT		=	"" #"\033[00;39m"

CC		=	gcc

CFLAGS		= -Werror -Wall -Wextra

#LIB		=

INC		=	-I ./include

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@$(ECHO) $(GREEN) "Module files compiled." $(DEFAULT)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB) $(INC)
			@$(ECHO) $(GREEN) "Compilation successfull." $(DEFAULT)


$(OBJS_DIR)/%.o	:	$(SRC_DIR)/%.$(SRC_EXT)
			$(CC) $(CFLAGS) $(INC) -c -o $@ $<


clean		:
			$(RM) $(OBJS)
			@$(ECHO) $(YELLOW) "Module files removed." $(DEFAULT)

fclean		:	clean
			$(RM) $(NAME)
			@$(ECHO) $(YELLOW) "Exec files removed." $(DEFAULT)

re		:	fclean all

.PHONY		:	fclean clean all re
