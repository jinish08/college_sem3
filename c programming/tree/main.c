#include <stdio.h>
#include "Queue.h"

struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d ", p->data);
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

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
    printf("\n");
}
void inorder(struct Node *p)
{
    if (p)
    {
        preorder(p->lchild);
        printf("%d", p->data);
        preorder(p->rchild);
    }
    printf("\n");
}
void postorder(struct Node *p)
{
    if (p)
    {
        preorder(p->lchild);
        preorder(p->rchild);
        printf("%d", p->data);
    }
    printf("\n");
}

int main()
{
    Treecreate();
    preorder(root);
    inorder(root);
    postorder(root);
    return 0;
}