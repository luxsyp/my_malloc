/*
** malloc.c for malloc in /u/all/locque_d/cu/rendu/proj/malloc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Mon Jan 31 14:47:38 2011 damien locque
** Last update Fri Feb 18 12:02:30 2011 damien locque
*/

#include <unistd.h>
#include "malloc.h"

static void	move_chunk(t_chunk *tmp)
{
  if (tmp->prev && tmp->next)
    {
      (tmp->prev)->next = tmp->next;
      (tmp->next)->prev = tmp->prev;
    }
  else
    {
      if (!tmp->prev && !tmp->next)
	{
	  free_list = NULL;
	  end_free = NULL;
	}
      else if (tmp->prev && !tmp->next)
	{
	  end_free = tmp->prev;
	  if (end_free)
	    end_free->next = NULL;
	}
      else
	{
	  free_list = tmp->next;
	  if (free_list)
	    free_list->prev = NULL;
	}
    }
}

void		*find_chunk(size_t size)
{
  t_chunk	*tmp;

  tmp = free_list;
  while (tmp)
    {
      if (tmp->size >= (size + sizeof(*tmp)))
	{
	  move_chunk(tmp);
	  tmp->next = NULL;
	  tmp->prev = NULL;
	  split(tmp, size);
	  add_by_address_list(tmp, &alloc_list, &end_alloc);
	  return (tmp + 1);
	}
      tmp = tmp->next;
    }
  return (extend_heap(size));
}

void		*malloc(size_t size)
{
  if (!size || (size + sizeof(*alloc_list)) < size)
    return (NULL);
  return (find_chunk(size));
}
