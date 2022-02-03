#include <stdio.h>
#include <time.h>
int swap = 0, compare = 0, shift = 0;
double time_taken;
clock_t t;

void bbsort(int a[], int n)
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            compare++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap++;
            }
        }
    }
}

void advbbsort(int a[], int n)
{
    int flag;
    int temp, i, j;
    for (i = 0; i <= n - 1; i++)
    {
        flag = 0;
        for (j = 0; j <= n - i - 2; j++)
        {
            compare++;
            if (a[j] > a[j + 1])
            {
                flag = 1;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap++;
            }
        }
        if (flag == 0)
            break;
    }
}

void inssort(int a[], int n)
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

void selsort(int a[], int n)
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

void main()
{
    int a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, b[20] = {19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int c[20] = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, d[20] = {14, 2, 12, 3, 5, 7, 6, 17, 19, 0, 1, 8, 4, 9, 11, 10, 15, 13, 8, 16, 18};
    int e[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, f[20] = {19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int g[20] = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, h[10] = {14, 2, 12, 3, 5, 7, 6, 17, 19, 0, 1, 8, 4, 9, 11, 10, 15, 13, 8, 16, 18};
    int i[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, j[20] = {19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int k[20] = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, l[10] = {14, 2, 12, 3, 5, 7, 6, 17, 19, 0, 1, 8, 4, 9, 11, 10, 15, 13, 8, 16, 18};
    int m[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, n[20] = {19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int o[20] = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, p[10] = {14, 2, 12, 3, 5, 7, 6, 17, 19, 0, 1, 8, 4, 9, 11, 10, 15, 13, 8, 16, 18};
    printf("10 elements in each case are considered\n");
    printf("For bubble sort\nBEST CASE\n");
    t = clock();
    bbsort(a, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("WORST CASE\n");
    t = clock();
    bbsort(b, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("ALMOST BEST CASE\n");
    t = clock();
    bbsort(c, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("RANDOM CASE\n");
    t = clock();
    bbsort(d, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("\nFor modified bubble sort:\n");
    printf("BEST CASE\n");
    t = clock();
    advbbsort(e, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("WORST CASE\n");
    t = clock();
    advbbsort(f, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("ALMOST BEST CASE\n");
    t = clock();
    advbbsort(g, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("RANDOM CASE\n");
    t = clock();
    advbbsort(h, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("\nFor selection sort:\n");
    printf("BEST CASE\n");
    t = clock();
    selsort(i, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("WORST CASE\n");
    t = clock();
    selsort(j, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("ALMOST BEST CASE\n");
    t = clock();
    selsort(k, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("RANDOM CASE\n");
    t = clock();
    selsort(l, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("\nFor insertion sort:\n");
    printf("BEST CASE\n");
    t = clock();
    inssort(m, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("WORST CASE\n");
    t = clock();
    inssort(n, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("ALMOST BEST CASE\n");
    t = clock();
    inssort(o, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;

    printf("RANDOM CASE\n");
    t = clock();
    inssort(p, 10);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("Total number of swaps: %d\nTotal number of comparisons: %d\nTotal number of shifts: %d\n", swap, compare, shift);
    printf("Total time taken: %lf seconds\n\n", time_taken);
    swap = shift = compare = 0;
}