#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack Overflow");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *p;
    int x = -1;
    if (top == NULL)
        printf("Stack is empty");
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

int peek(int pos)
{
    struct Node *p;
    for (int i = 0; i < pos - 1 && p != NULL)
    {
        p = p->next;
    }
    if (p != NULL)
        return p->data;
    else
        return -1;
}

int stackTop()
{
    if (top)
        return top->data;
    else
        return -1;
}

int isEmpty()
{
    return top ? 0 : 1;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    int poped = pop();
    printf("%d\n", poped);
    display(top);
    return 0;
}