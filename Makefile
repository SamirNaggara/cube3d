NAME			= 	cub3D
SOURCE_FOLDER	=	src
MATH_LIB		= 	-lm
LIB_PATH		=	libft-plus
LIBFT 			= 	$(LIB_PATH)/libft.a
PRINTF			=	$(LIB_PATH)/printf.a 
GNL				=	$(LIB_PATH)/gnl.a 
CC				=	cc $(FLAGS)
RM				=	rm -f	
FLAGS			= 	-Wall -Wextra -Werror -g3
GREEN			= 	\033[0;32m
BIG				= 	\033[0;1m
RESET			= 	\033[0m



SOURCES	=	./main.c \
			./$(SOURCE_FOLDER)/parsing/parsing.c \
			./$(SOURCE_FOLDER)/execution/execution.c \
			./$(SOURCE_FOLDER)/execution/input.c \
			./$(SOURCE_FOLDER)/execution/load_image.c \

OBJETS	=	$(SOURCES:.c=.o)			


all		: lib $(NAME)
	@echo "$(GREEN)Bien compilé ! Plus qu'a executer ./$(NAME) !$(RESET)"

%.o: %.c
	@echo "Creation du .o $@"
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx -O3 -c $< -o $@

$(NAME): $(OBJETS)
	@echo "\nCréation de l'executable cub3D\n"
	@$(CC) $(OBJETS) -Lminilibx -lmlx -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz -o $(NAME) $(MATH_LIB) $(GNL) $(PRINTF) $(LIBFT)

lib	: 
	@echo "Je déclenche le Makefile de Libft-plus\n"
	@$(MAKE) --no-print-directory -C $(LIB_PATH) all
	@echo "Je sors du Makefile de Libft-plus"


clean	:
	@$(RM) $(OBJETS)


fclean	:	clean
	@echo "Suppression de $(NAME)"
	@$(RM) $(NAME)
	@echo "Suppression de a.out au cas ou"
	@$(RM) a.out
	@echo "Je rentre dans la librairie libft-plus"
	@$(MAKE) --no-print-directory -C $(LIB_PATH) fclean
	@echo "Je sors de la librairie libft-plus"
	@echo "\n$(GREEN)Tout les fichiers ont bien été effacés$(RESET)\n"
	@echo "Suppression de tout les fichiers ajoutés par l'utilisateur\n"


re		:	fclean all
