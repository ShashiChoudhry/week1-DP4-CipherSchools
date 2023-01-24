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

void sortArr(vector<int>& arr, int n)
{

    int p0 = 0, p1 = 0, p2 = n -1;

    while(p1 <= p2)
    {
        switch(arr[p1])
        {
        case 0:
            swap(arr[p1], arr[p0]);
            p1++; p0++;
            break;
        case 1:
            p1++;
            break;
        case 2:
            swap(arr[p1], arr[p2]);
            p2--;
            break;
        }
    }
}

int main()
{
    int n; cin>> n;

    vector<int> arr(n);
    inputData(arr, n);

    sortArr(arr, n);
    print(arr, n);

    return 0;
}
