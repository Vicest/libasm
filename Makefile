# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/06/04 21:56:07 by vicmarti         ###   ########.fr        #
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
SRC_BNS_FILES +=		ft_strchr.s
SRC_BNS_FILES +=		ft_isspace.s
SRC_BNS_FILES +=		ft_atoi_base.s
SRC_BNS_FILES +=		ft_create_elem.s
SRC_BNS_FILES +=		ft_list_push_front.s
SRC_BNS_FILES +=		ft_list_size.s
SRC_BNS_FILES +=		ft_list_sort.s
SRC_BNS_FILES +=		ft_list_remove_if.s
OBJ_BNS_FILES := $(patsubst %.s, %.o, $(SRC_BNS_FILES))

SRC_DIR := sources/
OBJ_DIR := objects/

SRC :=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ :=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_BNS :=	$(addprefix $(SRC_DIR), $(SRC_BNS_FILES))
OBJ_BNS :=	$(addprefix $(OBJ_DIR), $(OBJ_BNS_FILES))

NAME := libasm.a

AS := ~/.brew/Cellar/nasm/2.15.05/bin/nasm
ifeq ($(shell uname), Linux)
ASFLAGS := -f elf64
else
ASFLAGS := -g -f macho64
endif

AR := ar
ARFLAGS := -rc

CC := cc
CFLAGS := -Wall -Werror -Wextra -I. -L. -lasm -g

.PHONY: all bonus re clean fclean tests
all : $(NAME)

tests : $(NAME) $(SRC_DIR)tests.c $(SRC_DIR)readtst.c
	@echo "Preparing tests."
	$(CC) $(CFLAGS) $(SRC_DIR)tests.c -o test
	$(CC) $(CFLAGS) $(SRC_DIR)readtst.c -o rwtest
	@echo "Done, run:\n ./rwtest [file] and ./test."

btest : $(NAME) bonus $(TST_BNS_FILES)
	@echo "Preparing bonus tests."
	$(CC) $(CFLAGS) $(SRC_DIR)list_tests.c -o btest
	@echo "Done, run:\n ./btest"


$(NAME) : $(OBJ)
	@echo "Building library."
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "______________________________"

bonus : $(NAME) $(OBJ_BNS)
	@echo "Including bonus into library."
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_BNS)
	@echo "______________________________"


$(OBJ_DIR)%.o : $(SRC_DIR)%.s
	@echo "Building object."
	@mkdir -vp $(OBJ_DIR)
	$(AS) $(ASFLAGS) $? -o $@
	@echo "______________________________"

clean : fclean

fclean :
	@echo "Forced cleaning."
	@rm -rfv $(OBJ_DIR) $(NAME) *.dSYM test rwtest btest read_output write_output
	@echo "______________________________"

re : fclean all
