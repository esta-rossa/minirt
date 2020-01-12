NAME = minirt
FLAGS = -Wall -Wextra -Werror
SRC_FOLDER = ./src
HEADER_FOLDER = ./header
LIBFT_FOLDER = ./libft
OBJECT_FOLDER = ./objects
LIBS = -lmlx -framework OpenGL -framework Appkit
LIBFT_LIB = libft.a
SRC_FILES = 	main.c \
				error.c \
				allocation_functions.c \
				allocation_functions_2.c \
				camera.c \
				color.c \
				here_we_go.c \
				init_light.c \
				intersect_obj.c \
				light_shitting.c \
				parsing_main.c \
				parsing_obj.c \
				parsing_obj_2.c \
				parsing_obj_3.c \
				utils.c \
				cylinder_inters.c \
				vector_op.c \
				vector_op_2.c \
				phong_shitting.c \
				shitting_math.c

OBJECT_FILES = $(SRC_FILES:.c=.o)
PATH := $(addprefix $(OBJECT_FOLDER)/, $(OBJECT_FILES))

all: $(NAME)

libft:
	make -C $(LIBFT_FOLDER)
$(NAME): $(OBJECT_FILES) libft
	gcc -I $(HEADER_FOLDER) -I $(LIBFT_FOLDER) $(PATH) $(LIBS) $(LIBFT_FOLDER)/$(LIBFT_LIB) -o $(NAME)

%o: $(SRC_FOLDER)/%c
	gcc -I $(HEADER_FOLDER) -I $(LIBFT_FOLDER) -o $(OBJECT_FOLDER)/$@ -c $<

clean:
	rm -f $(OBJECT_FILES)

fclean: clean
	rmf -f $(NAME)

re: fclean $(NAME)

.PHONY = all bonus clean fclean re