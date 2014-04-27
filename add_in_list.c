/*
** add_in_list.c for add in /home/locque_d//rendu/proj/malloc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sat Feb  5 10:45:54 2011 damien locque
** Last update Sun Feb 13 22:56:05 2011 damien locque
*/

#include <unistd.h>
#include "malloc.h"

static void	add_tail_list(t_chunk *chunk, t_chunk **list, t_chunk **tail)
{
  if (!(*list))
    {
      chunk->next = NULL;
      chunk->prev = NULL;
      (*list) = chunk;
      (*tail) = chunk;
    }
  else
    {
      if (*tail)
	{
	  (*tail)->next = chunk;
	  chunk->prev = (*tail);
	}
      else
	chunk->prev = NULL;
      chunk->next = NULL;
      (*tail) = chunk;
    }
}

void		add_by_address_list(t_chunk *chunk, t_chunk **list, t_chunk **tail)
{
  t_chunk	*tmp;
  int		flag;

  tmp = ((chunk - (*list)) > ((*tail) - chunk)) ? (*tail) : (*list);
  flag = ((chunk - (*list)) > ((*tail) - chunk)) ? 1 : 0;
  if (!tmp || (*tail) < chunk)
      return (add_tail_list(chunk, list, tail));
  while (tmp)
    {
      if (chunk < tmp
	  && (!tmp->prev || (tmp->prev) < chunk))
	{
	  chunk->next = tmp;
	  chunk->prev = tmp->prev;
	  if (tmp->prev)
	    (tmp->prev)->next = chunk;
	  tmp->prev = chunk;
	  if (!chunk->prev)
	      (*list) = chunk;
	  return;
	}
      tmp = (!flag) ? tmp->next : tmp->prev;
    }
  return (add_tail_list(chunk, list, tail));
}
