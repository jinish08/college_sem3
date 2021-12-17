
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int arr[50];
int r = -1;
int f = -1;

int isempty()
{
    if (f == -1 && r == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if (r == 49)
        return 1;
    else
        return 0;
}

void enqR(int index)
{
    if (isfull())
        return;
    else if (isempty())
        f = 0, r = 0;
    else
        r = r + 1;
    arr[r] = index;
}

int deqF()
{
    if (isempty())
        return 0;
    else if (f == r)
    {
        f = -1, r = -1;
        return arr[f];
    }
    else
        return arr[f++];
}

int deqR()
{
    if (isempty())
        return 0;
    else if (f == r)
    {
        f = -1, r = -1;
        return arr[r];
    }
    else
        return arr[r--];
}

int main()
{
    int n, j;
    printf("Enter the no. of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    printf("Give the window size:\n");
    scanf("%d", &j);
    enqR(0);
    for (int i = 0; i < j; i++)
    {
        if (num[i] >= num[i - 1])
        {
            deqR();
            enqR(i);
        }
    }
    printf("%d ", num[arr[0]]);
    for (int i = j; i < n; i++)
    {
        while (f != -1 && arr[f] <= i - j)
        {
            deqF();
        }
        while (r != -1 && num[i] >= num[arr[r]])
        {
            deqR();
        }
        enqR(i);
        printf("%d ", num[arr[f]]);
    }
}
