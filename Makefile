NAME = minirt
FLAGS = -Wall -Wextra -Werror
SRC_FOLDER = ./src
BONUS_SRC_FOLDER = ./bonus_src
HEADER_FOLDER = ./header
LIBFT_HEADER = ./libft/header
LIBFT_FOLDER = ./libft
OBJECT_FOLDER = ./objects
BONUS_OBJECT_FOLDER = ./bonus_objects
LIBS = -lmlx -framework OpenGL -framework Appkit
LIBFT_LIB = libft.a
RED = \033[0;31m
GREEN = \033[0;32m
GOLD = \033[0;33m
RESET = \033[0m
BONUS_HEADER_FOLDER = ./bonus_header
SRC_FILES = 			main.c \
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
						squar_inters.c \
						rotation_pars.c \
						rotation.c \
						translation.c \

BONUS_SRC_FILES =		main_b.c \
						error_b.c \
						allocation_functions_b.c \
						allocation_functions_2_b.c \
						camera_b.c \
						color_b.c \
						here_we_go_b.c \
						init_light_b.c \
						intersect_obj_b.c \
						light_shitting_b.c \
						parsing_main_b.c \
						parsing_obj_b.c \
						parsing_obj_2_b.c \
						parsing_obj_3_b.c \
						utils_b.c \
						cylinder_inters_b.c \
						vector_op_b.c \
						vector_op_2_b.c \
						phong_shitting_b.c \
						shitting_math_b.c \
						shadows_b.c \
						triangle_inters_b.c \
						save_bmp_b.c \
						hooks_b.c \
						squar_inters_b.c \
						rotation_pars_b.c \
						rotation_b.c \
						translation_b.c \
						put_cap_b.c \
						cube_parsing_b.c \
						pyramid_pars_b.c \
						thread.c \
						anti_aliasing_b.c \
						camera_mov_b.c \
						objects_mov.c \
						hardcode_object_rotation.c \
						hardcode_object_translation.c \

OBJECT_FILES = $(SRC_FILES:.c=.o)
OBJECT_FILES := $(addprefix $(OBJECT_FOLDER)/, $(OBJECT_FILES))
BONUS_OBJECT_FILES = $(BONUS_SRC_FILES:.c=.o)
BONUS_OBJECT_FILES := $(addprefix $(BONUS_OBJECT_FOLDER)/, $(BONUS_OBJECT_FILES))
LIBFT_FILE := $(LIBFT_FOLDER)/$(LIBFT_LIB)

.PHONY = all bonus clean fclean re credit

all: credit $(NAME)

LIBFT_RULE:
	@make -C $(LIBFT_FOLDER)/

bonus: credit LIBFT_RULE $(BONUS_OBJECT_FILES)
	@gcc -g -I $(BONUS_HEADER_FOLDER) -I $(LIBFT_FOLDER) $(BONUS_OBJECT_FILES) $(LIBFT_FOLDER)/$(LIBFT_LIB) $(LIBS) -o $(NAME)_bonus
	@echo
	@echo $(NAME)"_bonus created $(GOLD)successfully$(RESET)"

$(BONUS_OBJECT_FOLDER)/%.o: $(BONUS_SRC_FOLDER)/%.c
	@(mkdir $(BONUS_OBJECT_FOLDER) 2> /dev/null && echo "creating "$(BONUS_OBJECT_FOLDER)" folder $(GOLD){OK}$(RESET)") || true
	@gcc $(FLAGS) -g -I $(BONUS_HEADER_FOLDER) -I $(LIBFT_HEADER) -o $@ -c $< && echo  "creating" $< "object $(GOLD){OK}$(RESET)"

$(NAME): LIBFT_RULE $(OBJECT_FILES)
	@gcc -g -I $(HEADER_FOLDER) -I $(LIBFT_FOLDER) $(OBJECT_FILES) $(LIBFT_FOLDER)/$(LIBFT_LIB) $(LIBS) -o $@
	@echo
	@echo $(NAME)" created $(GREEN)successfully$(RESET)"

$(OBJECT_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@(mkdir $(OBJECT_FOLDER) 2> /dev/null && echo "creating "$(OBJECT_FOLDER)" folder $(GREEN){OK}$(RESET)") || true
	@gcc $(FLAGS) -g -I $(HEADER_FOLDER) -I $(LIBFT_HEADER) -o $@ -c $< && echo "creating" $< "object $(GREEN){OK}$(RESET)"

clean:
	@(rm $(OBJECT_FILES) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FILES)) || true
	@(rm -r $(OBJECT_FOLDER) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FOLDER)) || true
	@(rm $(BONUS_OBJECT_FILES) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(BONUS_OBJECT_FILES)) || true
	@(rm -r $(BONUS_OBJECT_FOLDER) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(BONUS_OBJECT_FOLDER)) || true
	@make -C  $(LIBFT_FOLDER)/ clean

fclean: clean
	@(rm $(NAME) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(NAME)) || true
	@(rm $(NAME)_bonus 2> /dev/null && echo "$(RED)deleting$(RESET): " $(NAME)_bonus) || true
	@(rm $(LIBFT_FOLDER)/$(LIBFT_LIB) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(LIBFT_LIB)) || true


re: fclean $(NAME)

credit:
	@printf "					$(RED)_minirt made by:_$(RESET)\n"
	@echo "███████╗ ██████╗████████╗ █████╗ ██████╗  █████╗  ██████╗ ██████╗ █████╗"
	@echo "██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗"
	@echo "█████╗  ╚█████╗    ██║   ███████║██████╔╝██║  ██║╚█████╗ ╚█████╗ ███████║"
	@echo "██╔══╝   ╚═══██╗   ██║   ██╔══██║██╔══██╗██║  ██║ ╚═══██╗ ╚═══██╗██╔══██║"
	@echo "███████╗██████╔╝   ██║   ██║  ██║██║  ██║╚█████╔╝██████╔╝██████╔╝██║  ██║"
	@echo "╚══════╝╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝"
