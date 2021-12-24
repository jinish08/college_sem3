#include <stdio.h>

int ascendingBinarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int descendingBinarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int findBitonicPoint(int arr[], int n, int l, int r)
{
    int mid;
    int bitonicPoint = 0;
    mid = (r + l) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return mid;
    else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
        bitonicPoint = findBitonicPoint(arr, n, mid, r);

    else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
        bitonicPoint = findBitonicPoint(arr, n, l, mid);
    return bitonicPoint;
}

int searchBitonic(int arr[], int n, int key, int index)
{
    if (key > arr[index])
        return -1;
    else if (key == arr[index])
        return index;
    else
    {
        int temp = ascendingBinarySearch(arr, 0, index - 1, key);
        if (temp != -1)
            return temp;
        return descendingBinarySearch(arr, index + 1, n - 1, key);
    }
}

void main()
{
    int arr[] = {-8, 1, 2, 3, 4, 5, -2, -3};
    int key = -2;
    int n, l, r;
    n = 8;
    l = 0;
    r = n - 1;
    int index;
    index = findBitonicPoint(arr, n, l, r);
    int x = searchBitonic(arr, n, key, index);
    if (x == -1)
        printf("Element Not Found");
    else
        printf("Element Found at index %d", x);
}