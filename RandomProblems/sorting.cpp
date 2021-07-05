#include <iostream>
#include <vector>
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

/* Merge step takes O(n) */
void merge(vector<int> *arr, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    vector<int> *res = new vector<int>();
    while (i <= mid && j <= r)
    {
        if (arr->at(i) <= arr->at(j))
        {
            res->push_back(arr->at(i));
            i++;
        }
        else
        {
            res->push_back(arr->at(j));
            j++;
        }
    }

    while (i <= mid)
    {
        res->push_back(arr->at(i));
        i++;
    }

    while (j <= r)
    {
        res->push_back(arr->at(j));
        j++;
    }

    for (int i = l; i < res->size() + l; i++)
    {
        arr->at(i) = res->at(i - l);
    }

    delete res;
}

/* COMPLEXITY = O(nlogn) - Average */
void mergeSort(vector<int> *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void print(vector<int> *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr->at(i) << " ";
    }
    cout << endl;
}

void takeInput(vector<int> *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr->push_back(k);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> *arr = new vector<int>();
    takeInput(arr, n);
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    mergeSort(arr, 0, n - 1);
    print(arr, n);
}