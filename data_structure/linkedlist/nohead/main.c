#include "nohead.h"
#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  struct node_st *list = NULL;
  struct score_st tmp;
  int ret;
  for (size_t i = 0; i < 7; i++)
    {
      tmp.id = i;
      snprintf (tmp.name, NAMESIZE, "stu%ld", i);
      tmp.math = rand () % 100;
      tmp.chinese = rand () % 100;
      ret = list_insert (&list, &tmp);
      if (ret != 0)
        exit (1);
    }

  list_show (list);
  list_delete (&list);
  // printf("==========\n");
  // list_show(list);
  int id = 33;
  struct score_st *s1;
  s1 = list_find (list, id);
  if (s1)
    {
      printf ("%d\n", s1->id);
    }
  else
    {
      printf ("canot find\n");
    }
  list_destroy(list);
  exit (0);
}
