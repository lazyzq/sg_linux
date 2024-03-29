#include "nohead.h"
#include <stdio.h>
#include <stdlib.h>

int
list_insert (struct node_st **list, struct score_st *data)
{
  struct node_st *new;
  new = malloc (sizeof (*new));
  if (NULL == new)
    {
      return -1;
    }
  new->st = *data;
  new->next = *list;
  *list = new;
  return 0;
}
void
list_show (struct node_st *list)
{
  struct node_st *cur;
  for (cur = list; cur != NULL; cur = cur->next)
    {
      printf ("%d %s %d %d\n", cur->st.id, cur->st.name, cur->st.math,
              cur->st.chinese);
    }
}

int
list_delete (struct node_st **list)
{
  struct node_st *cur;
  if (*list == NULL)
    return -1;
  cur = *list;
  *list = (*list)->next;

  free (cur);
  return 0;
}

struct score_st *
list_find (struct node_st *list, int id)
{
  struct node_st *cur;
  for (cur = list; cur != NULL; cur = cur->next)
    {
      if (cur->st.id == id)
        {

          return &cur->st;
        }
    }
  return NULL;
}

void
list_destroy (struct node_st *list)
{
  struct node_st *cur;
  if(list == NULL)
  return ;
  for(cur = list; cur != NULL; cur = list)
  {
    list = cur->next;
    free(cur);
  }
}