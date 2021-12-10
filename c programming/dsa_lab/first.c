#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{ // Traversal / Printing  ...
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        printf(" %d \n ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("count is : %d \n", count);
    //return count;
}

struct node *create(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

struct node *insert(struct node *head, int data)
{
    struct node *newnode = create(data);
    struct node *temp;
    if (head == NULL)
    {
        head = newnode;
        temp = head;
    }
    else
    {
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}

int count(struct Node *head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}

void insertAtPos(struct node *head, int data, int pos)
{
    // if (pos == 1)
    // {
    //     //printf("At 1 ");
    //     newnode->next = head;
    //     head = newnode;
    // }
    // else if (pos == count)
    // {
    //     struct node *temp = head;
    //     while (temp != NULL)
    //     {
    //         temp = temp->next;
    //     }
    //     temp->next = newnode;
    // }
    // else
    // {
    //     printf("\nNOt done yet \n");
    // }
    if (pos < 0 || pos > count(head))
    {
        // print out of bound
    }
    struct node *newnode = create(data);
    struct node *temp;
    if (pos == 0)
    {
        //logic
    }
    else
    {
        // logic
    }
}

int main()
{
    int n, data, choice, pos, count;
    struct node *head = NULL;
    printf("Creation : \n\n");
    printf("Enter Number Of Elements : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data : ");
        scanf("%d", &data);
        head = insert(head, data);
    }
    printf("\nLinked List Before Insertion : \n");
    display(head);
    printf("\nDo You Wanna Insert (0,1) ? ");
    scanf("%d", &choice);
    while (choice)
    {
        printf("Enter The ELEMENT And The POSITION : ");
        scanf("%d %d", &data, &pos);
        insertAtPos(head, pos, data);
        printf("\nDo You Wanna Insert More (0,1) ? ");
        scanf("%d", &choice);
    }
    printf("Linked List After Insertion : ");
    display(head);
    return 0;
}