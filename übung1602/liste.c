#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>

struct kugel
{
    int size;
    struct kugel *next;
};
typedef struct kugel kugel;
// typedef () name

kugel *find(kugel *head, int wert, int *cnt)
{
    *cnt = 0;
    kugel *ptr = head;
    // Pointer auf ne Struktur? Wertzugriff mit -> // ptr->size gibt den wert
    while (ptr != NULL)
    {
        if (wert == ptr->size)
        {
            return ptr;
        }
        else
        {
            *cnt += 1;
            ptr = ptr->next;   
        }
    }
}

int main(int argc, char const *argv[])
{
    kugel *tail = NULL;

    kugel a = {5, tail};
    kugel b = {8, &a};
    kugel c = {18, &b};

    kugel *head = &c;
    int* kstelle = (int *) (malloc(sizeof(int)));
    kugel *k = find(head, 5, kstelle);
    if (k != NULL)
    {
        printf("%d existiert an Position %d.", k->size, *kstelle);
    }

    return 0;
}
