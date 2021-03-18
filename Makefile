# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/03/10 14:10:05 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := $(shell uname)

SRC_FILES :=
SRC_FILES +=		main.c
SRC_FILES +=		error.c
SRC_FILES +=		validations.c
SRC_FILES +=		inside_check.c
SRC_FILES +=		plane.c
SRC_FILES +=		triangle.c
SRC_FILES +=		sphere.c
SRC_FILES +=		square.c
SRC_FILES +=		cylinder.c
SRC_FILES +=		colour_utils.c
SRC_FILES +=		math_utils.c
SRC_FILES +=		vectors.c
SRC_FILES +=		vectors_2.c
SRC_FILES +=		rotations.c
SRC_FILES +=		interactions.c
SRC_FILES +=		camera_list.c
SRC_FILES +=		light_stack.c
SRC_FILES +=		ray_tracer.c
SRC_FILES +=		config_reader.c
SRC_FILES +=		save_functions.c
SRC_FILES +=		save_functions_2.c
SRC_FILES +=		bmpstore.c
SRC_FILES +=		get_next_line.c
SRC_FILES +=		get_next_line_utils.c
OBJ_FILES := $(patsubst %.c, %.o, $(SRC_FILES))

SRC_DIR := sources/
OBJ_DIR := objects/
INC_DIR := includes/

SRC :=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ :=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT := libft.a
MLX := libmlx.a

NAME = miniRT

CC := cc
CFLAGS := -g -Wall -Werror -Wextra -I$(INC_DIR) #-fsanitize=address
LFLAGS := -L. -lft -lmlx -lm
ifeq ($(OS), Linux)
	LFLAGS += -lXext -lX11
else
	LFLAGS += -framework OpenGL -framework AppKit
endif
AR := ar
ARFLAGS := -rc

.PHONY: all re clean fclean pft
all : $(NAME)

$(MLX) :
	@echo "Building libmlx."
	@make -C minilibx/ all 2> /dev/null
	@cp -v minilibx/$(MLX) $(MLX)
	@echo "______________________________"

$(LIBFT) :
	@echo "Building libft."
	@make -C libft/ all clean
	@cp -v libft/$(LIBFT) $(LIBFT)
	@echo "______________________________"

$(NAME) : $(MLX) $(LIBFT) $(OBJ)
	@echo "Building executable."
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "______________________________"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@echo "Building object."
	@mkdir -vp $(OBJ_DIR)
	$(CC) $(CFLAGS) $? -c -o $@
	@echo "______________________________"

clean :
	@echo "Removing objects."
	@rm -rfv $(OBJ)
	@echo "______________________________"

depclean :
	@echo "Removing dependencies."
	@rm -fv $(LIBFT) $(MLX)
	@echo "______________________________"

fclean :
	@echo "Removing lib."
	@rm -fv $(NAME)
	@echo "______________________________"

re : fclean clean depclean all
