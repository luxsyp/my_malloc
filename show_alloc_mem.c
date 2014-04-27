/*
** show_alloc_mem.c for  in /home/locque_d//rendu/proj/malloc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Thu Feb  3 15:43:56 2011 damien locque
** Last update Fri Feb 18 11:10:47 2011 damien locque
*/

#include <stdio.h>
#include <unistd.h>
#include "malloc.h"

void		show_alloc_mem(void)
{
  t_chunk	*tmp;

  tmp = alloc_list;
  printf("break : %p\n", sbrk(0));
  while (tmp)
    {
      printf("%p - %p : %u octects\n", tmp,
	     ((char *)tmp + tmp->size), tmp->size);
      tmp = tmp->next;
    }
  printf("------------ FREE --------------\n");
  tmp = free_list;
  printf("break : %p\n", sbrk(0));
  while (tmp)
    {
      printf("%p - %p : %u octects\n", tmp,
	     ((char *)tmp + tmp->size), tmp->size);
      tmp = tmp->next;
    }
}
