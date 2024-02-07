#include <stdlib.h>
#include <stdio.h>

struct kugel
{
    int size;
    struct kugel *next;
};
typedef struct kugel kugel;

kugel *neu(int wert, kugel *ptr)
{

    kugel *e = (kugel *)(malloc(sizeof(kugel))); 
    e->size = wert;
    e->next = ptr;

    return e;
}

int main(int argc, char const *argv[])
{
    kugel *head = NULL;
    kugel *hptr = head;

    for(int i=0;i<20;i++){
       hptr = neu(i, hptr);
    }

    kugel *tail = hptr;

    kugel *p = tail;
    while (p)
    {
        printf("%d ", p->size);
        p = p->next;
    }
    return 0;
}
