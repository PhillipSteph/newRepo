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
    element *e = (element *)(malloc(sizeof(element)));
    e->val = zahl;
    e->next = p;

    return e;
}

int main(int argc, char const *argv[])
{

    element *head = NULL;
    element *tail;
    tail->next=head;

    element *prv = tail;
    element *next = tail;

    //for (int i = 0; i < 10; i++)
    {
        int r = rand() % 10;
        element *q = neu(r, NULL);

        while(next!=NULL){
            next = next->next;
            if(next == head){
                q->next = next;
                prv->next = q;
                break;
            }

            
        }
    }
    element *ptr = tail;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    return 0;
}
