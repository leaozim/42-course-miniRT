NAME				=	miniRT

LIBFT_PATH			=	libs/libft/
LIBFT				=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH		=	libs/minilibx-linux/
MINILIBX			=	(MINILIBX_PATH)/mlx.h

OBJ_DIR				=	./obj
OBJS				=	$(SRC:%.c=$(OBJ_DIR)/%.o)

HEADER_PATH			=	./includes
HEADER_FILES		=	minirt.h

SRC					=	main.c \
						$(UTILS) $(PARSER) $(TUPLA) $(CANVAS) $(COLOR) \
						$(MATRIX) $(RAY) $(SHAPES) $(LIGHT_AND_SHADING) \
						$(WORLD)

UTILS				=	error.c \
						check_arguments.c destroy_minirt.c

PARSER				=	parser.c parser_camera.c check.c parser_sphere.c \
						parser_cylinder.c create_parameter.c check_file.c \
						parser_light.c parser_plane.c parser_ambient.c

TUPLA				=	create_tuple.c operations_tuple.c operations_tuple2.c

CANVAS				= 	create_canvas.c

COLOR				=	color.c operations_color.c

MATRIX				=	matrix_builder.c matrix_operations.c matrix_checkers.c \
						matrix_utils.c matrix_transformations.c matrix_rotations.c

RAY					=	ray_builder.c ray_operations.c ray_intersect.c ray_hit.c \
						ray_transform.c

SHAPES				=	sphere.c create_shape.c

LIGHT_AND_SHADING	=	normal_sphere.c reflect.c lighting.c light_builder.c \
						is_shadowed.c light_destroy.c

WORLD				= 	create_world.c intersect_world.c destroy_world.c computations_world.c

DIRS				=	. srcs utils parser tupla color canvas matrix ray shapes \
						 light_and_shading world
IFLAGS				=	-I $(HEADER_PATH)
LDFLAGS				=	-L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm
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
	make clean -C $(LIBFT_PATH)
	make clean -C test

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C test

re:  fclean all

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) -g $(CFLAGS) $(IFLAGS) -o $@ $(OBJS) $(LDFLAGS)
#@echo "$(GREEN)MINIRT compiled succesfully$(WHITE)"

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
#@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
#$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))


$(OBJ_DIR):
	mkdir -p $@

git:
	git add .
	git commit -m "$(m)"
	git push

test:	all
	make run -C test

test_vall:	all
	make val -C test

test_debug: all
	make debug -C test

val: all
	valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./miniRT scenes/test.rt

debug: all
	gdb --tui --args ./$(NAME) scenes/test.rt

mc:	all
	clear
	./minirt

norm:
	@norminette ${SRC} ${LIBFT_PATH} 

.PHONY:	all clean fclean re git test