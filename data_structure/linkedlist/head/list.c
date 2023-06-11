#include "list.h"

#include <stdio.h>
#include <stdlib.h>

list *
list_creat ()
{
  list *me;
  me = malloc (sizeof (*me));
  if (me == NULL)
    return NULL;
  me->next = NULL;
  return me;
}
int
list_insert_at (list *me, int i, datatype *data)
{
  int j = 0;
  list *node = me, *newnode;
  if (i < 0)
    return -1;
  while (j < i && node != NULL)
    {
      node = node->next;
      j++;
    }
  if (node)
    {
      newnode = malloc (sizeof (*newnode));
      if (newnode == NULL)
        return -2;
      newnode->data = *data;
      newnode->next = node->next;
      node->next = newnode;
    }
  else
    return -3;
  return 0;
}

int
list_order_insert (list *me, datatype *data)
{

  list *p = me, *q;
  while (p->next && p->next->data < *data)
    {
      p = p->next;
    }
  q = malloc (sizeof (*q));
  if (q == NULL)
    return -1;
  q->data = *data;
  q->next = p->next;
  p->next = q;
  return 0;
}
int
list_delete_at (list *me, int i, datatype *data)
{
  if (i < 0)
    return -1;
  int j = 0;
  list *p = me, *q;
  *data = -1;
  while (j < i && p)
    {
      j++;
      p = p->next;
    }
  if (p)
    {
      q = p->next;
      p->next = q->next;
      *data = q->data;
      free (q);
      q = NULL;
      return 0;
    }
  else
    {
      return -2;
    }
}
int
list_delete (list *me, datatype *data)
{
  list *p = me, *q;
  while (p->next && p->next->data != *data)
    p = p->next;
  if (p->next == NULL)
    {
      return -1;
    }
  else
    {
      q = p->next;
      p->next = q->next;
      free (q);
      q = NULL;
    }
}
int
list_isempty (list *me)
{
  if (me->next == NULL)
    {
      return 0;
    }
  return 1;
}
void
list_display (list *me)
{
  list *node = me->next;
  if (list_isempty (me) == 0)
    {
      return;
    }
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
  return;
}
void
list_destroy (list *me)
{
  list *node, *next;
  for (node = me->next; node != NULL; node = next)
    {
      next = node->next;
      free (node);
    }
  free (me);
  return;
}