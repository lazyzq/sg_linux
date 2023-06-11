#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define NAMESIZE 40
struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
    struct list_head node;
};

int main()
{
    struct score_st *datap;
    struct list_head *cur;
    LIST_HEAD(head);

    int i;
    for(i = 0; i < 7 ; i++)
    {
        datap = malloc(sizeof(*datap));
        if(datap == NULL)
            exit(1);
        datap->id = i;
        snprintf(datap->name, NAMESIZE, "stu%d", i);
        datap->math = rand()%100;
        datap->chinese = rand()%100;
        list_add(&datap->node, &head);
    }
    list_for_each(cur, &head);
    exit(0);
}