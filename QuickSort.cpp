#include<bits/stdc++.h>
using namespace std;

// Take the inputs of array
void inputData(vector<int> &arr, int n)
{
    for(int i = 0; i < n; i++)
        cin>> arr[i];
}

// Print the output of array
void print(vector<int> &arr, int n)
{
    for(int i = 0; i < n; i++)
        cout<< arr[i] << ' ';
}

int partition(vector<int>& arr, int low, int high)
{
    int pi = high;
    int i = low -1;

    for(int j = low; j < high; j++) {
        if(arr[j] < arr[pi]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[pi]);

    return i;
}
void quickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi -1);
        quickSort(arr, pi +1, high);
    }
}

int main()
{
    int n;
    cin>> n;

    vector<int> arr(n);
    inputData(arr, n);

    quickSort(arr, 0, n -1);
    print(arr, n);

    return 0;
}

