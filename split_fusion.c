/*
** split_fusion.c for  in /home/locque_d//rendu/proj/malloc/backup_13_10
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 13 22:43:27 2011 damien locque
** Last update Sun Feb 13 22:44:40 2011 damien locque
*/

#include <unistd.h>
#include "malloc.h"

void		split(t_chunk *chunk, size_t size)
{
  t_chunk	*new;
  size_t	storage_size;

  storage_size = size + sizeof(*chunk);
  if (((chunk->size - storage_size)) > sizeof(*chunk))
    {
      new = (t_chunk *)((char *)chunk + storage_size);
      new->next = NULL;
      new->prev = NULL;
      new->size = chunk->size - (size + sizeof(*chunk));
      add_by_address_list(new, &free_list, &end_free);
      chunk->size = size + sizeof(*chunk);
    }
}

void		fusion(t_chunk *chunk)
{
  if (chunk && chunk->next &&
      ((t_chunk *)((char *)chunk + chunk->size)) == chunk->next)
    {
      chunk->size += chunk->next->size;
      chunk->next = chunk->next->next;
      if (chunk->next)
	chunk->next->prev = chunk;
      else
	end_free = chunk;
      fusion(chunk);
    }
  if (chunk && chunk->prev &&
      ((t_chunk *)((char *)chunk->prev + chunk->prev->size)) == chunk)
    {
      chunk->prev->size += chunk->size;
      chunk->prev->next = chunk->next;
      if (chunk->next)
	chunk->next->prev = chunk->prev;
      else
	end_free = chunk->prev;
      fusion(chunk->prev);
    }
}

