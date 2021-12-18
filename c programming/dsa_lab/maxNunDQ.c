
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int dq[50];
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
    dq[r] = index;
}

int deqF()
{
    if (isempty())
        return 0;
    else if (f == r)
    {
        f = -1, r = -1;
        return dq[f];
    }
    else
        return dq[f++];
}

int deqR()
{
    if (isempty())
        return 0;
    else if (f == r)
    {
        f = -1, r = -1;
        return dq[r];
    }
    else
        return dq[r--];
}

int main()
{
    int n, j;
    printf("Enter the no. of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    printf("Give the window size:\n");
    scanf("%d", &j);
    for (int i = 0; i < n; i++)
    {
        if (!isempty() && dq[f] <= i - j)
            deqF();
        while (!isempty() && num[i] >= num[dq[r]])
            deqR();
        enqR(i);
        if (i >= j - 1)
            printf("%d ", num[dq[f]]);
    }
}
