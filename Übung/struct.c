#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct kugel
{

    int size;
    struct kugel *next;

} kugel;
// typedef struct kugel kugel

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    struct kugel *head = NULL;

    kugel *q = head;
    kugel *p;
    for (int i = 0; i < atoi(argv[1]); i++)
    {
    p->size = rand()%10;
    p->next = q;
    q = p;
    }

    while (p != head)
    {
        printf("%d, ", p->size);
        p = p->next;
    }
    return 0;
}
