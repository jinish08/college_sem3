#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void IInorder(struct Node *p)
{
    struct Stack stk;
    createStack(&stk, 100);
    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void iterativePre(struct Node *p)
{
    struct Stack stk;
    createStack(&stk, 100);
    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int count(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int height(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int countLeaf(struct Node *p)
{
    int x, y;
    if (p !NULL)
    {
        x = countLeaf(p->lchild);
        y = countLeaf(p->rchild);
        if (!p->lchild && !p->rchild)
        {
            return x + y + 1;
        }
        else
            return x + y;
    }
    return 0;
}
int countInternal(struct Node *p)
{
    int x, y;
    if (p !NULL)
    {
        x = countInternal(p->lchild);
        y = countInternal(p->rchild);
        if (p->lchild || p->rchild)
        {
            return x + y + 1;
        }
        else
            return x + y;
    }
    return 0;
}
int countDeg2(struct Node *p)
{
    int x, y;
    if (p !NULL)
    {
        x = countDeg2(p->lchild);
        y = countDeg2(p->rchild);
        if (p->lchild && p->rchild)
        {
            return x + y + 1;
        }
        else
            return x + y;
    }
    return 0;
}
int countDeg1(struct Node *p)
{
    int x, y;
    if (p !NULL)
    {
        x = countDeg1(p->lchild);
        y = countDeg1(p->rchild);
        if (p->lchild || p->rchild)
        {
            return x + y + 1;
        }
        else
            return x + y;
    }
    return 0;
}

int main()

{
    Treecreate();
    // iterativePre(root);
    // IInorder(root);
    // LevelOrder(root);
    int c = count(root);
    printf("The total number of nodes in this tree is %d", c);
    int h = height(root);
    printf("The height of this tree is %d", h);
    return 0;
}