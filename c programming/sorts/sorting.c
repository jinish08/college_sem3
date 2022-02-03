#include <stdio.h>
#include <time.h>
int swap = 0, compare = 0, shift = 0;
double time_taken;
clock_t t;

//Bubble sort
void bubbleSort(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            compare++;
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swap++;
            }
        }
    }
}

void modified_bubbleSort(int array[], int n)
{
    for (int step = 0; step < n - 1; ++step)
    {
        int flag = 0;

        for (int i = 0; i < n - step - 1; ++i)
        {
            compare++;
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                flag = 1;
                swap++;
            }
        }
        if (flag == 0)
            break;
    }
}

void selection(int a[], int n)
{
    int temp, i, j, k;
    for (i = 0; i <= n - 2; i++)
    {
        k = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            compare++;
            if (a[j] < a[k])
                k = j;
        }
        if (k != i)
        {
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
            swap++;
        }
    }
}

void insertion(int a[], int n)
{
    int temp, i, j;
    for (i = 1; i <= n - 1; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            compare++;
            if (a[j] < temp)
                break;
            shift++;
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

void print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n, choice;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    int data[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("\nThe array is: \n");
    print(data, n);

    printf("Enter your choice:\n1.Bubble sort\n2.Modified Bubble sort\n3.Selection sort\n4.Insertion sort\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        //Bubble sort
        t = clock();
        bubbleSort(data, n);
        t = clock() - t;
        time_taken = ((double)t) / CLOCKS_PER_SEC;
        printf("\nAfter Bubble sort: \n");
        print(data, n);
        printf("No. of comparisons: %d\n", compare);
        printf("No. of shifts: %d\n", shift);
        printf("No. of swaps: %d\n", swap);
        printf("bubbleSort() took %f seconds to execute \n", time_taken);
        break;

    case 2:
        //Modified Bubble sort
        t = clock();
        modified_bubbleSort(data, n);
        t = clock() - t;
        time_taken = ((double)t) / CLOCKS_PER_SEC;
        printf("\nAfter Modified Bubble sort: \n");
        print(data, n);
        printf("No. of comparisons: %d\n", compare);
        printf("No. of shifts: %d\n", shift);
        printf("No. of swaps: %d\n", swap);
        printf("modified_bubbleSort() took %f seconds to execute \n", time_taken);
        break;

    case 3:
        //Selection sort
        t = clock();
        selection(data, n);
        t = clock() - t;
        time_taken = ((double)t) / CLOCKS_PER_SEC;
        printf("\nAfter Selection sort: \n");
        print(data, n);
        printf("No. of comparisons: %d\n", compare);
        printf("No. of shifts: %d\n", shift);
        printf("No. of swaps: %d\n", swap);
        printf("selection() took %f seconds to execute \n", time_taken);
        break;

    case 4:
        //Insertion sort
        t = clock();
        insertion(data, n);
        t = clock() - t;
        time_taken = ((double)t) / CLOCKS_PER_SEC;
        printf("\nAfter Selection sort: \n");
        print(data, n);
        printf("No. of comparisons: %d\n", compare);
        printf("No. of shifts: %d\n", shift);
        printf("No. of swaps: %d\n", swap);
        printf("insertion() took %f seconds to execute \n", time_taken);
        break;
    }
    return 0;
}
