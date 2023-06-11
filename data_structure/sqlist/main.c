#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"
int main() {
  sqlist *list = NULL;
  sqlist *list2 = NULL;
  datatype arr[] = {12, 23, 34, 45, 56, 100, 19, 22};
  datatype arr2[] = {12, 33, 44, 55};
  int i;
  int err;
  list = sqlist_create();
  if (list == NULL) {
    fprintf(stderr, "sqlist_create() failed!\n");
    exit(1);
  }
  list2 = sqlist_create();
  if (list2 == NULL) {
    fprintf(stderr, "sqlist_create() failed!\n");
    exit(1);
  }
  // insert arr to list
  for (i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
    if ((err = sqlist_insert(list, 0, &arr[i])) != 0) {
      if (err == -1) {
        fprintf(stderr, "the arr is full.\n");
      } else if (err == -2) {
        fprintf(stderr, "the pos you want to insert is wrong.\n");
      } else {
        fprintf(stderr, "Error!\n");
      }
      exit(1);
    }
  }
  // insert arr to list2
  for (i = 0; i < sizeof(arr2) / sizeof(*arr2); i++) {
    if ((err = sqlist_insert(list2, 0, &arr2[i])) != 0) {
      if (err == -1) {
        fprintf(stderr, "the arr is full.\n");
      } else if (err == -2) {
        fprintf(stderr, "the pos you want to insert is wrong.\n");
      } else {
        fprintf(stderr, "Error!\n");
      }
      exit(1);
    }
  }
  sqlist_display(list);
  sqlist_delete(list, 2);
  sqlist_display(list);
  printf("the number of list is:%d\n", sqlist_getnum(list));
  int num = 12;
  printf("the positon of 12 is:%d\n", sqlist_find(list, &num));
  printf("display list2\n");
  sqlist_display(list2);
  sqlist_union(list, list2);
  printf("show list after insert list2:\n");
  sqlist_display(list);
  sqlist_destroy(list);
  sqlist_destroy(list2);

  exit(0);
}