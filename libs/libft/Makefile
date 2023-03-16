SYSTEM		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_itoa.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c \
				ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c 	\
				ft_strchr.c ft_strdup.c ft_striteri.c \
				ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_substr.c \
				ft_strtrim.c ft_tolower.c ft_toupper.c \
				ft_lstadd_back.c ft_lstadd_front.c \
				ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
				ft_lstlast.c ft_lstmap.c ft_lstnew.c \
				ft_lstsize.c ft_gnl.c ft_strcmp.c \
				ft_atof.c ft_array_size.c

NAME				=	libft.a

LIB 				=	ar -rcs

RM					=	rm -fr

INC 				=	libft.h

OBJ_DIR				=	./obj
OBJS				=	$(SRC:%.c=$(OBJ_DIR)/%.o)

SRC					=	$(SYSTEM)									

DIRS				=	. 
CFLAGS				=	-Wall -Wextra -Werror

VPATH				=	$(addprefix ./srcs/, $(DIRS))
VPATH				+=	$(HEADER_PATH)

CFLAGS				+=	-g

WHITE				=	\e[00m
GREEN				=	\e[32m
RED					=	\e[91m
YELLOW				=	\e[033m
BLUE				=	\e[34m

NUMBER_OF_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

all: $(NAME)

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)


re:  fclean all

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(LIB) $(NAME) $@ $(OBJS)
	@echo "$(GREEN)LIBFT compiled succesfully$(WHITE)"

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS)  -c $< -o $@
	@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

$(OBJ_DIR):
	mkdir -p $@

git:
	git add .
	git commit -m "$(m)"
	git push

.PHONY:	all clean fclean re git test