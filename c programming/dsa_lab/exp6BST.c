#include <stdio.h>
#include <stdlib.h>
#define num 20
int asscending[num];

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(int data)
{
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

struct node *
insert(struct node *root, int data)
{
    if (root == NULL)
        root = create(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void Inorder(struct node *head)
{
    if (head != NULL)
    {
        static int i = 0;
        Inorder(head->left);
        asscending[i] = head->data;
        i++;
        Inorder(head->right);
    }
}
struct node *find_LCA(struct node *head, int a, int b)
{
    if (head == NULL)
        return NULL;
    else if (head->data > a && head->data < b || head->data < a && head->data > b)
        return head;
    else if (head->data > a && head->data > b)
        return find_LCA(head->left, a, b);
    else
        return find_LCA(head->right, a, b);
}

int height(struct node *head)
{
    if (head == NULL)
        return 0;
    int lh = height(head->left);
    int rh = height(head->right);
    if (lh >= rh)
        return lh + 1;
    else
        return rh + 1;
}

int isBalanced(struct node *head)
{
    if (head == NULL)
        return 1;
    else if (isBalanced(head->left) == 0)
        return 0;
    else if (isBalanced(head->right) == 0)
        return 0;
    int lh = height(head->left);

    int rh = height(head->right);
    if (abs(lh - rh) <= 1)
        return 1;
    else
        return 0;
}

int main()
{
    int n, arr[num], k;
    struct node *head = NULL;
    printf("Enter the no. of elements to be inserted: ");
    scanf("%d", &n);

    printf("Enter elements ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        head = insert(head, arr[i]);
    }
    printf("\n");
    printf("1. Enter the elements whose LCA is to be found: ");
    int a, b;
    scanf("%d%d", &a, &b);
    struct node *temp = find_LCA(head, a, b);
    printf("The node is %d \n", temp->data);
    printf("\n2. Enter the kth element required: ");
    scanf("%d", &k);
    Inorder(head);
    printf("%dth element is %d \n", k, asscending[k - 1]);
    if (isBalanced(head))
        printf("\n3.Balanced tree\n");
    else
        printf("3.Unbalanced\n ");
    printf("\n");
    int k1, k2;
    printf("4. Enter the range k1 and k2: \n");
    scanf("%d%d", &k1, &k2);
    for (int i = 0; i < n; i++)
        if (asscending[i] >= k1 && asscending[i] <= k2)
            printf("%d ", asscending[i]);

    return 0;
}
