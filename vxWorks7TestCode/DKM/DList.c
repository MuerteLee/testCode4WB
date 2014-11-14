/* includes */

#include "vxWorks.h"
#include <stdlib.h>
#include <stdio.h>
#include <lstLib.h>
#include <time.h>
typedef struct _Queue
{
 NODE * next;
 NODE * prev;
 int age;
 char name[255];

} QUEUE;

LIST list;

void TestList()
{
    QUEUE *p;
    int i;

    lstLibInit();
    lstInit(&list);
    for(i = 0; i < 300; i++)
    {
        p = malloc(sizeof(QUEUE));
        if(p) 
        {
            p->age = i * 5;
            sprintf(p->name, "person %d", i);
            lstAdd(&list, (NODE*)p);
        }

    }

    for(i = 0; i < 300; i++)
    {
        p = (QUEUE*)lstGet(&list);
        if(p)
        {
            printf("name = %s, age = %d\n", p->name, p->age);
            free(p);
            sleep(1);
        }
    }

    lstFree(&list);
}
