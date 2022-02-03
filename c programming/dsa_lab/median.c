#include <stdio.h>
#include <stdlib.h>

float medianarr[100];
int top = -1;
void insertmedianarr(float data)
{
    medianarr[++top] = data;
}
struct node
{
    float data;
    struct node *left, *right;
};

struct node *create(float data)
{
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

struct node *insert(struct node *root, float data)
{
    if (root == NULL)
        root = create(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void MorrisTraversal(struct node *root)
{
    struct node *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {
            insertmedianarr(current->data);
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                insertmedianarr(current->data);
                current = current->right;
            }
        }
    }
}

int main()
{
    int n;
    struct node *tree = NULL;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        tree = insert(tree, arr[i]);
    }
    MorrisTraversal(tree);

    printf("\nTHE MEDIAN IS: ");
    if ((top + 1) & 1)
        printf("%0.2f", medianarr[top / 2]);
    else
        printf("%0.2f", (medianarr[top / 2] + medianarr[(top / 2) + 1]) / 2);

    return 0;
}
