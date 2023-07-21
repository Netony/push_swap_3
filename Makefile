# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/07/21 22:18:39 by dajeon           ###   ########.fr        #
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
		  stack/stack_utils.c \
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
		  greedy/greedy.c \
		  greedy/greedy_renew.c \
		  greedy/greedy_renew_utils.c \
		  utils/ft_toklen.c \
		  utils/ft_strcmp.c \
		  utils/math.c \
		  utils/split.c \
		  utils/etc.c

DIRS = greedy push_swap stack utils command parse

SOURCES_MANDA = main.c 
SOURCES_BONUS = main_bonus.c checker.c
			   
INCLUDES = stack.h push_swap.h data.h lib.h toklen.h

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
LIBFT := $(addprefix $(LIB_DIR)/, $(LIBFT))

ifdef WITH_BONUS
	OBJS_NEW = $(OBJS_BONUS) $(OBJS) 
else
	OBJS_NEW = $(OBJS_MANDA) $(OBJS) 
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
	$(RM) $(RMFLAGS) $(OBJS_BONUS)
	$(MAKE) $(NAME) 

bonus : 
	$(RM) $(RMFLAGS) $(OBJS_MANDA)
	$(MAKE) $(BONUS) WITH_BONUS=1

clean :
	$(RM) $(RMFLAGS) objs
	$(MAKE) -C libft clean

fclean : 
	$(RM) $(RMFLAGS) objs
	$(RM) $(RMFLAGS) $(NAME)
	$(MAKE) -C libft fclean

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re

# Dependency ***************************************************************** #

$(NAME) : $(OBJS_NEW) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL)
	$(CC) $(CFLAGS) $(OBJS_NEW) -o $@ $(LIBFLAGS)

$(BONUS) : $(OBJS_NEW) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL)
	$(CC) $(CFLAGS) $(OBJS_NEW) -o $@ $(LIBFLAGS)
$(LIBFT): 
	$(MAKE) -j3 -C $(LIB_DIR) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR) $(OBJ_DIRS)
	$(CC) $(CFLAGS) $< -c -I $(INC_DIR) -o $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIRS):
	mkdir $@
