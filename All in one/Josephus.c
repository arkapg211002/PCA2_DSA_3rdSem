#include <stdio.h>
#include <stdlib.h>

typedef struct person {
    int position;
    struct person *next;
}person;
int findWinner(int n,int k);
int main() {
    int w = findWinner(5, 3);
    printf("Winner: %d", w);
    w = findWinner(10, 3);
    printf("\nWinner: %d", w);
    w = findWinner(5, 2);
    printf("\nWinner: %d", w);
    w = findWinner(7, 3);
    printf("\nWinner: %d", w);

    return 0;
}

int findWinner(int n, int k) 
{
    int i, counter;
    person *p, *q, *r;

    p = (person*) malloc(sizeof(person));
    p->position = 1;
    p->next = p;
    q = p;

    for(i=2; i<=n; i++) {
        r = (person*) malloc(sizeof(person));
        r->position = i;
        r->next = p;
        q->next = r;
        q = r;
    }

    while(p->next != p) {
        q = p;
        r = q;
        for(counter = 1; counter<k; counter++) {
            r = q;
            q = q->next;
        }
        r->next = q->next;
        p = r->next;
        q->next = NULL;
        free(q);
        q = NULL;
    }

    return p->position;
}
