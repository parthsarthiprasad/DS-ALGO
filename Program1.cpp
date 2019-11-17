#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int arr[100];
//MERGESORT
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

// RADIXSORT
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// SHELLSORT
int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

//HEAPSORT
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// QUICKSORT
int partition(int low, int high, int arr[])
{
    int i = low, pindex = high, x = low, temp;
    for (; i < (high); i++)
    {
        if (arr[i] < arr[pindex])
        {
            temp = arr[i];
            arr[i] = arr[x];
            arr[x] = temp;
            x++;
        }
    }
    temp = arr[pindex];
    arr[pindex] = arr[x];
    arr[x] = temp;
    return x;
}

void quicksort(int low, int high, int arr[])
{
    int pindex;
    if (high > low)
    {
        pindex = partition(low, high, arr);
        quicksort(low, pindex - 1, arr);
        quicksort(pindex + 1, high, arr);
    }
}

// INSERTIONSORT
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// BUBBLESORT
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// SELECTIONSORT
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int ch;
    cin >> ch;
    clock_t start, end;
    double time_taken;
    switch (ch)
    {
    case 1:
        // For Merge Sort
        cout << "Merge Sort\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        start = clock();
        mergesort(0, n - 1, arr);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 2:
        // For Quick Sort
        cout << "Quick Sort\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        start = clock();
        mergesort(0, n - 1, arr);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 3:
        // For Bubble Sort
        cout << "Bubble Sort\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        start = clock();
        mergesort(0, n - 1, arr);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 4:
        // For Selection Sort
        cout << "Selection Sort\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        start = clock();
        mergesort(0, n - 1, arr);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 5:
        // For Insertion Sort
        cout << "Insertion Sort\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        start = clock();
        mergesort(0, n - 1, arr);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 6:
        // For Radix Sort
        cout << "Radix Sort\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        start = clock();
        mergesort(0, n - 1, arr);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 7:
        // For Shell Sort
        cout << "Shell Sort\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        start = clock();
        mergesort(0, n - 1, arr);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    case 8:
        // For Heap Sort
        cout << "Heap Sort\n";
        for (int i = 0; i < n; i++)
        {
            arr[i] = ceil(rand() / 100000);
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        start = clock();
        mergesort(0, n - 1, arr);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        break;
    }

    return 0;
}
