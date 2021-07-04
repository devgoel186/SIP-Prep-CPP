#include <iostream>
using namespace std;

/* Bubble through the array every loop, which will automatically put the maximum number on the last element(ascending sort) */
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

/* Selects the smallest element, and puts at start (ascending sort)*/
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[pos])
            {
                pos = j;
            }
        }
        swap(arr[i], arr[pos]);
    }
}

void insertionSort(int *arr, int n)
{
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void takeInput(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    takeInput(arr, n);
    // bubbleSort(arr, n);
    selectionSort(arr, n);
    print(arr, n);
}