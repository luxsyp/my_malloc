/*
** free.c for free in /home/locque_d//rendu/proj/malloc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Tue Feb  1 15:31:48 2011 damien locque
** Last update Fri Feb 18 12:03:05 2011 damien locque
*/

#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

static void	move_chunk(t_chunk *tmp)
{
  if (tmp->next && tmp->prev)
    {
      (tmp->next)->prev = tmp->prev;
      (tmp->prev)->next = tmp->next;
    }
  else
    {
      if (!tmp->prev && !tmp->next)
	{
	  alloc_list = NULL;
	  end_alloc = NULL;
	}
      else if (!tmp->prev && tmp->next)
	{
	  alloc_list = tmp->next;
	  alloc_list->prev = NULL;
	}
      else
	{
	  end_alloc = tmp->prev;
	  if (tmp->prev)
	    (tmp->prev)->next = NULL;
	}
    }
}

void		free(void *ptr)
{
  t_chunk	*tmp;
  int		flag;

  tmp = ((ptr - ((void *)alloc_list)) > ((void *)end_alloc) - ptr)
    ? end_alloc : alloc_list;
  flag = ((ptr - ((void *)alloc_list)) > ((void *)end_alloc) - ptr)
    ? 1 : 0;
  while (tmp)
    {
      if ((tmp + 1) == ptr)
	{
	  move_chunk(tmp);
	  tmp->next = NULL;
	  tmp->prev = NULL;
	  add_by_address_list(tmp, &free_list, &end_free);
	  fusion(tmp);
	  reduce_heap();
	  //show_alloc_mem();
	  break;
	}
      tmp = (!flag) ? tmp->next : tmp->prev;
    }
}
