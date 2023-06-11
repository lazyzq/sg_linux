#include "list.h"
#include <stdio.h>
#include <stdlib.h>
int
main ()
{
  list *l;
  int i;
  datatype arr[] = { 12, 9, 23, 2, 34, 6, 45 };

  l = list_creat ();
  if (l == NULL)
    exit (1);
  for (i = 0; i < sizeof (arr) / sizeof (*arr); i++)
    {
      if (list_order_insert (l, &arr[i]))
        {
          printf ("wring");
          exit (1);
        }
    }
  list_display (l);
#if 0
  int value = 12;
  list_delete(l, &value);
  list_display(l);
#endif
  int val, err;
  err = list_delete_at(l, 2, &val);
  if (err)
    exit(1);
  list_display(l);
  printf("delete: %d\n",val);

  list_destroy (l);
  return 0;
}