#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int a[], int n)
{
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = a[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
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
}

void recursiveDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
}

void reverseDisplay(struct Node *p)
{
    if (p != NULL)
    {
        reverseDisplay(p->next);
        printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int recusrsiveCount(struct Node *p)
{
    if (p == 0)
        return 0;
    return 1 + recusrsiveCount(p->next);
}

int add(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int recursiveAdd(struct Node *p)
{
    if (p == 0)
        return 0;
    return (p->data + recursiveAdd(p->next));
}

int maxi(struct Node *p)
{
    int m = -32000;
    while (p != 0)
    {
        m = max(m, p->data);
        p = p->next;
    }
    return m;
}

int recursiveMax(struct Node *p)
{
    if (p == 0)
        return -32000;
    return max(p->data, recursiveMax(p->next));
}

struct Node *search(struct Node *p, int key)
{
    while (p != 0)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node *recursiveSearch(struct Node *p, int key)
{
    if (p == 0)
        return NULL;
    if (p->data == key)
        return p;
    return recursiveSearch(p->next, key);
}

struct Node *moveToFrontSearch(struct Node *p, int key)
{
    //similar to search but we add a functionality of moving the node to the front to get in easily in the next turn
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insert(struct Node *p, int pos, int x)
{
    struct Node *t;
    if (pos < 0 || pos > count(p))
    {
        printf("Position out of bound :(\n");
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (pos == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void insert_end(int x)
{
    struct Node *t;
    struct Node *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void insertSorted(struct Node *p, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (p == NULL)
        first = t;
    else if (x < p->data)
    {
        t->next = first;
        first = t;
    }
    else
    {
        while ((p) && (p->next->data <= x))
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int Delete(int pos)
{
    if (pos < 0 || pos > count(first))
        return -1;
    if (pos == 1)
    {
        struct Node *p;
        p = first;
        first = first->next;
        int x = p->data;
        free(p);
        return x;
    }
    else
    {
        struct Node *p, *q;
        q = NULL;
        p = first;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = q->next->next;
        int x = p->data;
        free(p);
        return x;
    }
}

bool isSorted(struct Node *p)
{
    int x = -32000;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

void removeDuplicates(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
    display(first);
}

void reverseLL(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void recursiveReverse(struct Node *p, struct Node *q)
{
    if (p != NULL)
    {
        recursiveReverse(p->next, p);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Concat(struct Node *f, struct Node *s)
{
    third = f;
    while (f->next != NULL)
    {
        f = f->next;
    }
    f->next = s;
}

struct Node *merge(struct Node *f, struct Node *s)
{
    // first is f
    // second is s
    // third is t
    // last is l
    struct Node *t = NULL, *l = NULL;
    if (f->data > s->data)
    {
        t = s;
        l = s;
        s = s->next;
        l->next = NULL;
    }
    else
    {
        t = f;
        l = f;
        f = f->next;
        l->next = NULL;
    }
    while (f != NULL && s != NULL)
    {
        if (f->data > s->data)
        {
            l->next = s;
            l = s;
            s = s->next;
            l->next = NULL;
        }
        else
        {
            l->next = f;
            l = f;
            f = f->next;
            l->next = NULL;
        }
    }
    if (f != NULL)
    {
        l->next = f;
    }
    if (s != NULL)
    {
        l->next = s;
    }
    return t;
}

bool isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = f;
    q = f;
    while (q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
        if (q == p)
            return true;
    }
    return false;
}

int main()
{
    int a[] = {1, 3, 5, 7, 9, 11};
    create(a, 6);
    int b[] = {2, 4, 6, 8};
    create2(b, 4);
    // recursiveDisplay(first);
    // reverseDisplay(first);
    // printf("%d ", count(first));
    // printf("%d ", recusrsiveCount(first));
    // printf("%d ", add(first));
    // printf("%d ", recursiveAdd(first));
    // printf("%d ", maxi(first));
    // printf("%d ", recursiveMax(first));

    // struct Node *temp = search(first, 6);
    // if (temp)
    //     printf("Key is found %d", temp->data);
    // else
    //     printf("Key is not found");

    // struct Node *temp = moveToFrontSearch(first, 3);
    // if (temp)
    //     printf("Key is found %d ", temp->data);
    // else
    //     printf("Key is not found");
    // display(first);
    // insert(first, 2, 7);
    // insert_end(5);
    // printf("The delete element is %d \n", Delete(2));
    // display(first);
    // bool ans = isSorted(first);
    // printf("%d", ans);
    // removeDuplicates(first);
    // recursiveReverse(first, NULL);
    // display(first);
    // display(second);
    // Concat(first, second);
    // display(third);
    // display(merge(first, second));

    // struct Node *t1, *t2;
    // t1 = first->next->next;
    // t2 = first->next->next->next->next; //to create a loop
    // t2->next = t1;
    // if (isLoop(first))
    //     printf("It is a loop");
    // else
    //     printf("It is not a loop");

        return 0;
}