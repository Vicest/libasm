# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/03/20 20:11:13 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES :=
SRC_FILES +=		ft_strlen.s
SRC_FILES +=		ft_strcpy.s
SRC_FILES +=		ft_strcmp.s
SRC_FILES +=		ft_strdup.s
SRC_FILES +=		ft_write.s
SRC_FILES +=		ft_read.s
OBJ_FILES := $(patsubst %.s, %.o, $(SRC_FILES))

SRC_BNS_FILES :=
SRC_BNS_FILES +=		ft_atoi_base.s
SRC_BNS_FILES +=		ft_list_push_front.s
SRC_BNS_FILES +=		ft_list_size.s
SRC_BNS_FILES +=		ft_list_size.s
SRC_BNS_FILES +=		ft_list_remove_if.s
OBJ_BNS_FILES := $(patsubst %.s, %.o, $(SRC_BNS_FILES))

SRC_DIR := sources/
OBJ_DIR := objects/

TST_FILES :=
TST_FILES +=		tester.c

SRC :=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ :=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_BNS :=	$(addprefix $(SRC_DIR), $(SRC_BNS_FILES))
OBJ_BNS :=	$(addprefix $(OBJ_DIR), $(OBJ_BNS_FILES))

NAME := libasm.a

AS := ~/.brew/Cellar/nasm/2.15.05/bin/nasm
ifeq ($(shell uname), Linux)
ASFLAGS := -f elf64 -g
else
ASFLAGS := -f macho64 -g
endif

AR := ar
ARFLAGS := -rc

CC := cc
CFLAGS := -g -Wall -Werror -Wextra -I.

.PHONY: all re clean fclean
all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Building library."
	$(AR) $(ARFLAGS) $(SRC)
	@echo "______________________________"

$(OBJ_DIR)%.o : $(SRC_DIR)%.s
	@echo "Building object."
	@mkdir -vp $(OBJ_DIR)
	$(AS) $(ASFLAGS) $? -o $@
	@echo "______________________________"

clean :
	@echo "Cleaning."
	@rm -rv $(OBJ) $(NAME)
	@echo "______________________________"

fclean :
	@echo "Forced cleaning."
	@rm -rfv $(OBJ) $(NAME)
	@echo "______________________________"

re : fclean clean all
