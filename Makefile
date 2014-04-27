##
## Makefile for  in /u/all/locque_d/cu/rendu/proj/malloc
##
## Made by damien locque
## Login   <locque_d@epitech.net>
##
## Started on  Mon Jan 31 22:57:43 2011 damien locque
## Last update Sun Feb 13 23:02:34 2011 damien locque
##

NAME	= libmy_malloc.so
LINK	= libmy_malloc.so

SRCS	= malloc.c		\
	  free.c		\
	  realloc.c		\
	  heap.c		\
	  add_in_list.c		\
	  split_fusion.c	\
	  show_alloc_mem.c

OBJS	= $(SRCS:.c=.o)
CC	= gcc
RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -Werror -O2

LFLAGS	+= -shared

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(LDLIBS) -o $(NAME) $(OBJS) $(LFLAGS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re	: fclean all
