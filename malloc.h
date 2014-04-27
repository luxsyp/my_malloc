/*
** malloc.h for  in /home/locque_d//rendu/proj/malloc/backup_13_10
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Feb 13 23:00:39 2011 damien locque
** Last update Sun Feb 13 23:01:12 2011 damien locque
*/

#ifndef _MALLOC_H_
#define _MALLOC_H_

#define PSIZE(size, pagesize) ((((size) / (pagesize)) + 1) * (pagesize))

typedef unsigned int size_t;

typedef struct		s_chunk
{
  size_t		size;
  struct s_chunk	*prev;
  struct s_chunk	*next;
} t_chunk;

t_chunk			*alloc_list;
t_chunk			*free_list;

t_chunk			*end_alloc;
t_chunk			*end_free;

void			*malloc(size_t taille);
void			*realloc(void *ptr, size_t taille);
void			free(void *ptr);

void			split(t_chunk *chunk, size_t size);
void			fusion(t_chunk *chunk);

void			*extend_heap(size_t size);
void			reduce_heap(void);

void			add_by_address_list(t_chunk *chunk,
					    t_chunk **list, t_chunk **tail);

void			show_alloc_mem(void);

#endif  /* !_MALLOC_H_ */
