/*
** realloc.c for realloc in /home/locque_d//rendu/proj/malloc/backup_13_10
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 13 22:47:02 2011 damien locque
** Last update Sun Feb 13 22:47:57 2011 damien locque
*/

#include <unistd.h>
#include <string.h>
#include "malloc.h"

void			*realloc(void *ptr, size_t taille)
{
  t_chunk		*tmp;
  void			*res;

  if (taille == 0)
    {
      free(ptr);
      return (NULL);
    }
  else if (ptr == NULL)
    return (malloc(taille));
  tmp = alloc_list;
  res = malloc(taille);
  while (tmp)
    {
      if ((void *)(tmp + 1) == ptr)
	{
	  memcpy(res, ptr, tmp->size - sizeof(*tmp));
	  free(ptr);
	  return (res);
	}
      tmp = tmp->next;
    }
  return (res);
}

