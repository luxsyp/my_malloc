/*
** heap.c for  in /home/locque_d//rendu/proj/malloc/backup_13_10
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 13 22:36:08 2011 damien locque
** Last update Fri Feb 18 12:08:54 2011 damien locque
*/

#include <unistd.h>
#include "malloc.h"

void		*extend_heap(size_t size)
{
  t_chunk	*new;
  int		page_size;
  size_t	size_allocate;

  new = sbrk(0);
  if ((page_size = sysconf(_SC_PAGESIZE)) == -1)
    return (NULL);
  size_allocate = PSIZE((size + sizeof(*alloc_list)), page_size);
  if (sbrk(size_allocate) == (void *)-1)
    return (NULL);
  new->next = NULL;
  new->prev = NULL;
  new->size = size_allocate;
  split(new, size);
  add_by_address_list(new, &alloc_list, &end_alloc);
  return (new + 1);
}

void		reduce_heap(void)
{
  size_t	size_to_free;

  size_to_free = 0;
  if (free_list && end_free &&
      (!end_alloc || ((char *)end_alloc + end_alloc->size)
       < (char *)end_free + end_free->size) && end_free->prev)
    {
      size_to_free = end_free->size;
      end_free = end_free->prev;
      if (end_free)
	end_free->next = NULL;
      else
	free_list = NULL;
      sbrk(-(size_to_free));
    }
}
