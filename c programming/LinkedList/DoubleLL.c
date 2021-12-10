#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct Node *p)
{
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void insert(struct Node *p, int x, int pos)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (pos < 0 || pos > Length(p))
    {
        printf("Position out of bound");
    }
    if (pos == 0)
    {
        if (p == NULL)
        {
            t->next = NULL;
            t->prev = NULL;
            first = t;
        }
        else
        {
            t->prev = NULL;
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
        t->prev = p;
    }
}

int delete (struct Node *p, int pos)
{
    if (pos < 0 || pos > Length(p))
    {
        printf("Position out of bound");
    }
    if (pos == 0)
    {
        first = first->next;
        int x = p->data;
        free(p);
        if (first)
            first->prev = NULL;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next != NULL)
            p->next->prev = p->prev;
        int x = p->data;
        free(p);
    }
}

void Reverse(struct Node *p)
{
    struct Node *temp;

    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev; //critical condition
        if (p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);

    insert(first, 6, 4);
    insert(first, 0, 0);

    delete (first, 0);
    delete (first, 4);

    Reverse(first);
    display(first);

    return 0;
}