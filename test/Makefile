NAME	= rt_test

HEADER	= $(shell ls . unity | grep .h$)

SRCS	= $(shell ls . unity test_ | grep .c$)

LIBFT_PATH	= ../libs/libft
LIBFT 	= $(LIBFT_PATH)/libft.a

MINILIBX_PATH		=	libs/minilibx-linux/
MINILIBX			=	(MINILIBX_PATH)/mlx.h

MINIRT_PATH = ../
MINIRT = $(MINIRT_PATH)/miniRT.a

MINIRT_OBJS = $(shell find ../obj -type f | grep .o$ | grep -v main)

OBJ_DIR	= ./obj
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(MINIRT_OBJS)

CFLAGS	= -Wall -Wextra -g3
IFLAGS	= -I. -Iunity -I../include -I../libft -Iincludes
VPATH	=  unity 
VPATH	+= test_
LDFLAGS	= -L$(LIBFT_PATH) -lft -lm -L$(MINILIBX_PATH) -lmlx -lXext -lX11

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -f error.log

re:  fclean all

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MINIRT):
	make -C $(MINIRT_PATH)

$(NAME): $(LIBFT) $(MINIRT) $(OBJS) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJS) $(LDFLAGS) -lreadline

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: all
	./$(NAME) 2> error.log

val: all
	valgrind --leak-check=full --show-leak-kinds=all \
	./$(NAME) 2> error.log

debug: all
	gdb --tui ./$(NAME)

.PHONY:	all clean fclean re run