#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}

void display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
}

int Length(struct Node *h)
{
    int len = 0;
    do
    {
        len++;
        h = h->next;
    } while (h != head);
    return len;
}

void insert(struct Node *p, int pos, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (pos < 0 || pos > Length(p))
    {
        printf("Range out of bound");
    }
    if (pos == 0)
    {
        if (p == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(int pos)
{
    int x = 0;
    if (pos < 0 || pos > Length(head))
    {
        printf("Range out of bound");
        return -1;
    }
    if (pos == 0)
    {
        struct Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        if (p == head)
        {
            free(head);
            head = NULL;
            return -1;
        }
        else
        {
            p->next = head->next;
            x = head->data;
            free(head);
            head = p->next;
        }
    }
    else
    {
        struct Node *p, *q;
        p = head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    insert(head, 1, 6);
    insert(head, 0, 0);
    printf("The deleted number is: %d \n", Delete(0));
    printf("The deleted number is: %d \n", Delete(2));
    display(head);
    return 0;
}