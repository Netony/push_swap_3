# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/07/22 16:40:38 by dajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

SOURCES = stack/stack_new.c \
		  stack/stack_push.c \
		  stack/stack_data.c \
		  stack/stack_pop.c \
		  stack/stack_operation.c \
		  stack/stack_check.c \
		  stack/stack_index.c \
		  command/cmd.c \
		  command/cmd_utils.c \
		  push_swap/push_swap.c \
		  push_swap/push_swap_base.c \
		  push_swap/push_swap_base_oper_1.c \
		  push_swap/push_swap_base_oper_2.c \
		  push_swap/push_swap_base_oper_3.c \
		  push_swap/push_swap_big.c \
		  push_swap/push_swap_small.c \
		  parse/parse.c \
		  parse/parse_check.c \
		  parse/parse_check_integer.c \
		  greedy/greedy.c \
		  greedy/greedy_renew.c \
		  greedy/greedy_utils.c \
		  utils/ft_toklen.c \
		  utils/ft_strcmp.c \
		  utils/math.c \
		  utils/split.c \
		  utils/etc.c

DIRS = greedy push_swap stack utils command parse bonus

SOURCES_MANDA = main.c 
SOURCES_BONUS = main_bonus.c \
				bonus/checker_bonus.c \
				bonus/checker_base_bonus.c \
				bonus/checker_utils_bonus.c
			   
INCLUDES = stack.h push_swap.h data.h lib.h toklen.h
INCLUDES_BONUS = checker_bonus.h

LIBFT = libft.a
LIB = ft 

# **************************************************************************** #

LIB_DIR = libft
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incs

SRCS := $(addprefix $(SRC_DIR)/, $(SOURCES))
SRCS_MANDA := $(addprefix $(SRC_DIR)/, $(SOURCES_MANDA))
SRCS_BONUS := $(addprefix $(SRC_DIR)/, $(SOURCES_BONUS))

OBJ_DIRS = $(addprefix $(OBJ_DIR)/, $(DIRS))

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
OBJS_MANDA = $(addprefix $(OBJ_DIR)/, $(SOURCES_MANDA:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SOURCES_BONUS:.c=.o))

INCS := $(addprefix $(INC_DIR)/, $(INCLUDES))
INCS_BONUS := $(addprefix $(INC_DIR)/, $(INCLUDES_BONUS))
LIBFT := $(addprefix $(LIB_DIR)/, $(LIBFT))

ifdef WITH_BONUS
	OBJS_NEW = $(OBJS_BONUS) $(OBJS) 
	INCS_NEW = $(INCS) $(INCS_BONUS)
else
	OBJS_NEW = $(OBJS_MANDA) $(OBJS) 
	INCS_NEW = $(INCS)
endif

# **************************************************************************** #

MAKE = make
CC = gcc
AR = ar
RM = rm

CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -l$(LIB) -L$(LIB_DIR)

ARFLAGS = crus
RMFLAGS = -rf

# Commands ******************************************************************* #

all : 
	$(MAKE) $(NAME) 

bonus : 
	$(MAKE) $(BONUS) WITH_BONUS=1

clean :
	$(RM) $(RMFLAGS) objs
	$(MAKE) -C libft clean

fclean : 
	$(RM) $(RMFLAGS) objs
	$(RM) $(RMFLAGS) $(NAME) $(BONUS)
	$(MAKE) -C libft fclean

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re

# Dependency ***************************************************************** #

$(NAME) $(BONUS) : $(OBJS_NEW) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL)
	$(CC) $(CFLAGS) $(OBJS_NEW) -o $@ $(LIBFLAGS)

$(LIBFT): 
	$(MAKE) -j3 -C $(LIB_DIR) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS_NEW) | $(OBJ_DIR) $(OBJ_DIRS)
	$(CC) $(CFLAGS) $< -c -I $(INC_DIR) -o $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIRS):
	mkdir $@
