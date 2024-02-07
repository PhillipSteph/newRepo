#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct element
{
    int val;
    struct element *next;
} element;

element *neu(int zahl, element *p)
{
    element *e = (element *) (malloc(sizeof(element)));
    e->val = zahl;
    e->next = p;

    return e;
}

int main(int argc, char const *argv[])
{

    element *head = NULL;
    element *next = head;
    for (int i = 0; i < 10; i++)
    {
        int r = rand() % 10;
        element *q = neu(r, next);
        next = q;
    }
    element *ptr = next;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    return 0;
}
