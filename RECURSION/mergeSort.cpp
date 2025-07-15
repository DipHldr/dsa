#include <iostream>
using namespace std;
int merge(int *, int, int, int);
int mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int merge(int *arr, int start, int mid, int end)
{
    int *temp = new int[end - start + 1];
    int i = start, j = mid + 1, k = 0, l = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (i = start; i != end; i++)
        arr[i] = temp[i - start];
}
int main()
{
    int arr[] = {2, 3, 1, 4, 2, 5, 3, 6, 4, 6, 8, 9, 56};
    mergeSort(arr, 0, 12);
    for (int i = 0; i < 13; i++)
        cout << arr[i] << " ";
}