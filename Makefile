NAME = minirt
FLAGS = -Wall -Wextra -Werror
SRC_FOLDER = ./src
HEADER_FOLDER = ./header
LIBFT_FOLDER = ./libft
OBJECT_FOLDER = ./objects
LIBS = -lmlx -framework OpenGL -framework Appkit
LIBFT_LIB = libft.a
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m
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
				shitting_math.c \
				shadows.c \
				triangle_inters.c \
				save_bmp.c \
				hooks.c \
				squar_inters.c

OBJECT_FILES = $(SRC_FILES:.c=.o)
OBJECT_FILES := $(addprefix $(OBJECT_FOLDER)/, $(OBJECT_FILES))
SRC_FILES := $(addprefix $(SRC_PATH)/,$(SRC_NAME))
LIBFT_FILE := $(LIBFT_FOLDER)/$(LIBFT_LIB)

.PHONY = all bonus clean fclean re credit

all: credit $(NAME)

$(LIBFT_FILE):

	@make -C $(LIBFT_FOLDER)/
	@echo  "libft compiled successfully $(GREEN){OK}$(RESET)"


credit:
	@echo "					$(RED)_minirt made by:_$(RESET)"
	@echo "███████╗ ██████╗████████╗ █████╗ ██████╗  █████╗  ██████╗ ██████╗ █████╗"
	@echo "██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗"
	@echo "█████╗  ╚█████╗    ██║   ███████║██████╔╝██║  ██║╚█████╗ ╚█████╗ ███████║"
	@echo "██╔══╝   ╚═══██╗   ██║   ██╔══██║██╔══██╗██║  ██║ ╚═══██╗ ╚═══██╗██╔══██║"
	@echo "███████╗██████╔╝   ██║   ██║  ██║██║  ██║╚█████╔╝██████╔╝██████╔╝██║  ██║"
	@echo "╚══════╝╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝"

$(NAME): $(LIBFT_FILE) $(OBJECT_FILES)
	@gcc -g -I $(HEADER_FOLDER) -I $(LIBFT_FOLDER) $(OBJECT_FILES) $(LIBFT_FOLDER)/$(LIBFT_LIB) $(LIBS) -o $@
	@echo
	@echo $(NAME)" created $(GREEN) successfully$(RESET)"


$(OBJECT_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@(mkdir $(OBJECT_FOLDER) 2> /dev/null && echo "creating "$(OBJECT_FOLDER)" folder $(GREEN){OK}$(RESET)") || true
	@gcc $(FLAGS) -g -I $(HEADER_FOLDER) -I $(LIBFT_FOLDER) -o $@ -c $<
	@echo  "creating" $< "object $(GREEN){OK}$(RESET)"

clean:
	@(rm $(OBJECT_FILES) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FILES)) || true
	@(rm -r $(OBJECT_FOLDER) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FOLDER)) || true
	@make -C  $(LIBFT_FOLDER)/ clean

fclean: clean
	@(rm $(NAME) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(NAME)) || true
	@(rm $(LIBFT_FOLDER)/$(LIBFT_LIB) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(LIBFT_LIB)) || true


re: fclean $(NAME)
