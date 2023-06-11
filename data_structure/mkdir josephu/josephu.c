#include <stdio.h>
#include <stdlib.h>
#define JOSE_NR 8
struct node_st
{
  int data;
  struct node_st *next;
};
struct node_st *
jose_create (int n)
{
  struct node_st *me;
  struct node_st *newnode;
  struct node_st *cur;
  int i = 1;
  me = malloc (sizeof (*me));
  if (me == NULL)
    {
      return NULL;
    }
  me->data = i;
  me->next = me;
  i++;
  cur = me;
  for (; i <= n; i++)
    {
      newnode = malloc (sizeof (*newnode));
      if (newnode == NULL)
        {
          return NULL;
        }
      newnode->data = i;
      newnode->next = me;
      cur->next = newnode;
      cur = newnode;
    }
  return me;
}
void
jose_show (struct node_st *me)
{
  struct node_st *list;
  for (list = me; list->next != me; list = list->next)
    {
      printf ("%d ", list->data);
    }
  printf ("%d\n", list->data);
}
#if 0
struct node_st *
jose_kill (struct node_st *me, int n)
{
  struct node_st *cur = me, *node;
  int i = 1;
  while (cur->next != cur)
    {
      while (i < n)
        {
          node = cur;
          cur = cur->next;
          i++;
        }
      printf ("%d ", cur->data);
      node->next = cur->next;
      free (cur);
      cur = node->next;
      i = 1;
    }
    printf("\n");
    return cur;
}
#endif
void
jose_kill (struct node_st **me, int n)
{
  struct node_st *cur = *me, *node;
  int i = 1;
  while (cur->next != cur)
    {
      while (i < n)
        {
          node = cur;
          cur = cur->next;
          i++;
        }
      printf ("%d ", cur->data);
      node->next = cur->next;
      free (cur);
      cur = node->next;
      i = 1;
    }
    printf("\n");
    *me = cur;
}
int
main ()
{
  struct node_st *list, *cur;
  int n = 3;
  list = jose_create (JOSE_NR);
  jose_show (list);
#if 0
  cur = jose_kill (list, n);
#endif
  jose_kill (&list, n);
  jose_show (list);
  return 0;
}