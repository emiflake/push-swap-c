# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 20:11:18 by nmartins       #+#    #+#                 #
#    Updated: 2019/07/01 00:08:35 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#############
# variables #
#############

# configure
CHECKER=		checker
PUSH_SWAP=		push_swap


OBJECT_NAMES=	\
				instruction \
				instruction_push \
				instruction_rotate \
				instruction_swap \
				stack \
				stack_parser \
				stack_reverse \
				stack_sorter \
				machine \
				error \
				


# dependencies
#
# MINILIBX, LIBFT, LIBGFX

LIBFT=./libft

# do not configure
CC=gcc
INCLUDES=-I./inc -I./libft
SRC=./src
OBJ=./.obj
EXTRA=
CFLAGS=-Werror -Wall -Wextra $(EXTRA)
LFLAGS=-L$(LIBFT) -lft $(INCLUDES)
OBJECTS=$(patsubst %, $(OBJ)/%.o, $(MAIN) $(OBJECT_NAMES))
SOURCES=$(patsubst %, $(SRC)/%.c, $(MAIN) $(OBJECT_NAMES))

# colors feel free to add more as you need them
OK_COLOR=\x1b[32;01m
RESET=\x1b[0m
UNDERLINE=\x1b[4m
BLUE=\x1b[36m
RED=\x1b[31m

#########
# rules #
#########
all: $(CHECKER) $(PUSH_SWAP)

$(LIBFT)/libft.a:
	@echo ">>= Making libft"
	@$(MAKE) -C $(LIBFT)
	@echo ">>= Done making libft"

libft_clean:
	@$(MAKE) -C $(LIBFT) clean

libft_fclean:
	@$(MAKE) -C $(LIBFT) fclean

$(PUSH_SWAP): $(LIBFT)/libft.a $(OBJECTS) $(SRC)/$(PUSH_SWAP).c
	@printf " λ Linking $(UNDERLINE)$(BLUE)$@$(RESET)\n"
	@$(CC) -o $@ $(SRC)/$(PUSH_SWAP).c $(OBJECTS) $(LFLAGS)

$(CHECKER): $(LIBFT)/libft.a $(OBJECTS) $(SRC)/$(CHECKER).c
	@printf " λ Linking $(UNDERLINE)$(BLUE)$@$(RESET)\n"
	@$(CC) -o $@ $(SRC)/$(CHECKER).c $(OBJECTS) $(LFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	@printf " λ Making object $(UNDERLINE)$(BLUE)$^$(RESET)\n"
	@$(CC) -c -o $@ $^ $(CFLAGS) $(INCLUDES)

clean: libft_clean 
	@echo "$(RED)Cleaning objects$(RESET)"
	@rm -rf $(OBJ)

fclean: libft_fclean clean
	@echo "$(RED)Cleaning $(CHECKER) and $(PUSH_SWAP)$(RESET)"
	@rm -rf $(CHECKER)
	@rm -rf $(PUSH_SWAP)

re:
	$(MAKE) fclean
	$(MAKE) all

quickre:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@$(MAKE) -C .

superfast:
	@$(MAKE) EXTRA=-O2 re -C .

.SECONDARY: $(OBJECTS)
.PHONY: all debug libft clean fclean re
