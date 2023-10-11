NAME			= 	cub3D
SOURCE_FOLDER	=	src/
OBJECT_FOLDER	=	obj/
INCLUDES_FOLDER	=	includes/
MATH_LIB		= 	-lm
LIB_PATH		=	src/libft-plus
LIBFT 			= 	$(LIB_PATH)/libft.a
PRINTF			=	$(LIB_PATH)/printf.a 
GNL				=	$(LIB_PATH)/gnl.a 
CC				=	cc $(FLAGS)
RM				=	rm -f	
FLAGS			= 	-Wall -Wextra -Werror -Iincludes -Isrc/minilibx -I$(LIB_PATH)/libft -I$(LIB_PATH)/printf -I$(LIB_PATH)/get-next-line
GREEN			= 	\033[0;32m
BIG				= 	\033[0;1m
RESET			= 	\033[0m

INCLUDES		=	cube3d.h

SOURCES			=	main.c 					\
					$(addprefix parsing/,	\
					map_open.c 				\
					map_verif.c 			\
					parse_color.c 			\
					parse_image.c 			\
					parse_input.c 			\
					parse_map.c 			\
					parse_map2.c 			\
					parsing.c 				\
					utils.c 				\
					)						\
					$(addprefix execution/,	\
					execution.c 			\
					raycasting.c 			\
					raycasting_init.c 		\
					draw.c 					\
					move.c 					\
					input.c 				\
					load_image.c 			\
					)						\
					free/exit_program.c		\

OBJETS			=	$(addprefix $(OBJECT_FOLDER), $(SOURCES:.c=.o))


all:	lib $(NAME)
	@echo "$(GREEN)Bien compilé ! Plus qu'a executer ./$(NAME) !$(RESET)"

$(OBJECT_FOLDER)%.o: $(SOURCE_FOLDER)%.c $(addprefix $(INCLUDES_FOLDER), $(INCLUDES))
	@mkdir -p $(@D)
	@echo "Creation du .o $@"
	@$(CC) -Wall -Wextra -Werror -I/usr/include -O3 -c $< -o $@

$(NAME):	$(OBJETS)
	@echo "\nCréation de l'executable cub3D\n"
	@$(CC) $(OBJETS) -Lsrc/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) $(MATH_LIB) $(GNL) $(PRINTF) $(LIBFT)

lib	: 
	@echo "Je déclenche le Makefile de Libft-plus\n"
	@$(MAKE) --no-print-directory -C $(LIB_PATH) all
	@echo "Je sors du Makefile de Libft-plus"
	@echo "Je déclenche le Makefile de minilibx\n"
	@$(MAKE) --no-print-directory -C src/minilibx all
	@echo "\nJe sors du Makefile de minilibx\n"


clean	:
	@$(RM) -r $(OBJECT_FOLDER)


fclean	:	clean
	@echo "Suppression de $(NAME)"
	@$(RM) $(NAME)
	@echo "Suppression de a.out au cas ou"
	@$(RM) a.out
	@echo "Je rentre dans la librairie libft-plus"
	@$(MAKE) --no-print-directory -C $(LIB_PATH) fclean
	@echo "Je sors de la librairie libft-plus"
	@echo "Je rentre dans la librairie minilibx"
	@$(MAKE) --no-print-directory -C src/minilibx clean
	@echo "Je sors de la librairie minilibx"
	@echo "\n$(GREEN)Tout les fichiers ont bien été effacés$(RESET)\n"
	@echo "Suppression de tout les fichiers ajoutés par l'utilisateur\n"


re		:	fclean all
