# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 11:25:58 by obelange          #+#    #+#              #
#    Updated: 2016/10/22 17:26:22 by obelange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

S_PATH = src/
B_PATH = build/
H_PATH = include/
LIBFT_PATH = libft

FILES = ft_flows

FILES += ft_ls_error

FILES += ft_tfilelist_helpers ft_tnode_helpers

FILES += 

FILES += 

FILES += 

FILES += 

OBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(FILES)))

LIB_COMP = -L$(LIBFT_PATH) -lft -I$(LIBFT_PATH)

FLAGS = -Wall -Werror -Wextra
DEVF = $(FLAGS) -fsanitize=address
LEAKF = $(FLAGS) $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl

ifdef ALLOCWRAP
	C_FLAGS += $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl
endif 

.PHONY: all fclean clean libft.a run leak

all : $(NAME)

$(NAME) : build $(OBJ) libft.a
	@echo ""
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP)

run : fclean build $(OBJ) libft.a 
	@echo "\x1b[31mrun is turned on\x1b[36m"
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP) && printf "\x1b[37m" && ./$(NAME)

dev : fclean build $(OBJ) libft.a
	gcc $(DEVF) -o $(NAME) $(OBJ) $(LIB_COMP)

leak : fclean build $(OBJ) libft.a 
	@echo "\x1b[31malloc wrap is turned on\x1b[36m"
	gcc $(LEAKF) -o $(NAME) $(OBJ) $(LIB_COMP)

libft.a : 
	@printf "\x1b[32m \ncompiling library.... \x1b[36m"
	@$(MAKE) -C $(LIBFT_PATH) all

build :
	@printf "\x1b[32m \nbuilding objects.....\n\x1b[33m"
	@mkdir build

$(B_PATH)%.o : $(S_PATH)%.c
	gcc -c $< -o $@ -I ./$(LIBFT_PATH)/$(H_PATH) -I ./$(H_PATH)
	
clean : 
	@rm -rf build
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all

