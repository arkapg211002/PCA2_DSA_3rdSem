// Double Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;

Node *addatbeg(Node *start,int data);
Node *addatend(Node *start,int data);
Node *addatpos(Node *start,int data,int pos);
void display(Node *start);
Node *del(Node *start,int data);
Node *reverse(Node *start);
Node *create(Node *start,int data);

void main()
{
    Node *start = NULL;
    int ch, data, item, pos;
    while (1)
    {
        printf("\n1.Create List 2.Display 3.Add at begining 4.Add at end 5.Add at pos 6.Delete 7.reverse 8.exit");
        printf("\nEnter your choice:");
        fflush(stdin);
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            printf("\nEnter data:");
            fflush(stdin);
            scanf("%d", &data);
            fflush(stdin);
            start = create(start, data);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("\nEnter data:");
            fflush(stdin);
            scanf("%d", &data);
            fflush(stdin);
            start = addatbeg(start, data);
            break;
        case 4:
            printf("\nEnter data:");
            fflush(stdin);
            scanf("%d", &data);
            fflush(stdin);
            start = addatend(start, data);
            break;
        case 5:
            printf("\nEnter data:");
            fflush(stdin);
            scanf("%d", &data);
            fflush(stdin);
            printf("\nEnter position:");
            fflush(stdin);
            scanf("%d", &pos);
            fflush(stdin);
            start = addatpos(start, data, pos);
            break;
        case 6:
            printf("\nEnter data:");
            fflush(stdin);
            scanf("%d", &data);
            fflush(stdin);
            start = del(start, data);
            break;
        case 7:
            start = reverse(start);
            break;
        case 8:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}

Node *create(Node *start,int data)
{
    Node *tmp,*p;
    tmp=(Node *)malloc(sizeof(Node));
    tmp->data=data;
    tmp->next=NULL;
    tmp->prev=NULL;
    start=tmp;
    return start;
}

Node *addatbeg(Node *start,int data)
{
    Node *tmp,*p;
    tmp=(Node *)malloc(sizeof(Node));
    tmp->data=data;
    tmp->next=start;
    tmp->prev=NULL;
    start->prev=tmp;
    start=tmp;
    return start;


}

Node *addatend(Node *start,int data)
{
    Node *tmp,*p;
    tmp=(Node *)malloc(sizeof(Node));
    tmp->data=data;
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=tmp;
    tmp->prev=p;
    tmp->next=NULL;
    return start;
}

Node *addatpos(Node *start,int data,int pos)
{
    Node *tmp,*p;
    int i;
    tmp=(Node *)malloc(sizeof(Node));
    tmp->data=data;
    p=start;
    for(i=1;i<pos-1 && p!=NULL;i++)
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("\nThere are less than %d elements",pos);
    }
    else
    {
        tmp->next=p->next;
        tmp->prev=p;
        if(p->next!=NULL)
        {
            p->next->prev=tmp;
        }
        p->next=tmp;
    }
    return start;
}

Node *del(Node *start,int data)
{
    Node *tmp,*p;
    
    p=start;
    while(p->next!=NULL)
    {
        if(p->data==data)
        {
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("\nElement %d not found",data);
    }
    else if(p==start)
    {
        start=start->next;
        start->prev=NULL;
        free(p);
    }
    else
    {
        p->prev->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=p->prev;
        }
        free(p);
    }
    return start;

}

Node *reverse(Node *start)
{
    Node *p1,*p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;

    }
    start=p1;
    printf("\nList reversed ");
    return start;
}

void display(Node *start)
{
    Node *p;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    p=start;
    printf("\nList is:");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

