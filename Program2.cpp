#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int arr[100];

// Linear Search
int LinearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Binary Search
int BinarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

// Interpolation Search
int InterpolationSearch(int arr[], int l, int r, int x)
{

    if (r >= l)
    {
        int mid = l + (((double)(r - l) / (arr[r] - arr[l])) * (x - arr[l]));

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return InterpolationSearch(arr, l, mid - 1, x);

        return InterpolationSearch(arr, mid + 1, r, x);
    }

    return -1;
}

// Sorting Algo
void merge(int low, int high, int mid, int arr[])
{
    int temp[100], i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        if (arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
        }
    }
    if (i <= mid)
    {
        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }
    }
    if (j <= high)
    {
        while (j <= high)
        {
            temp[k++] = arr[j++];
        }
    }
    k = 0;
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[k++];
    }
}

void mergesort(int low, int high, int arr[])
{
    int mid;
    if (high > low)
    {
        mid = (high + low) / 2;
        mergesort(low, mid, arr);
        mergesort(mid + 1, high, arr);
        merge(low, high, mid, arr);
    }
}

int main()
{
    int n, x;
    cin >> n;
    int ch;
    cin >> ch;
    clock_t start, end;
    double time_taken;
    switch (ch)
    {
    case 1:
        // Linear Search
        cout << "Linear Search\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cin >> x;
        start = clock();
        cout << LinearSearch(arr, n, x);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 2:
        // Binary Search
        cout << "Binary Search\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        mergesort(0, n - 1, arr);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cin >> x;
        start = clock();
        cout << BinarySearch(arr, 0, n - 1, x);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 3:
        // Interpolation Search
        cout << "Interpolation Search\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        mergesort(0, n - 1, arr);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cin >> x;
        start = clock();
        cout << InterpolationSearch(arr, 0, n - 1, x);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    }

    return 0;
}