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

// Merge divided parts (conquer)
void conquer(vector<int>& arr, int si, int mid, int ei)
{
    vector<int> sortedArr(ei - si +1);

    int lb1 = si, lb2 = mid +1;
    int i = 0;

//  Merging Logic
    while(lb1 <= mid && lb2 <= ei)
    {
        if(arr[lb1] <= arr[lb2]) {
            sortedArr[i] = arr[lb1];
            lb1++;
        }
        else {
            sortedArr[i] = arr[lb2];
            lb2++;
        }
        i++;
    }

    while(lb1 <= mid) {
        sortedArr[i] = arr[lb1];
        i++;
        lb1++;
    }

    while(lb2 <= ei) {
        sortedArr[i] = arr[lb2];
        lb2++;
        i++;
    }

//  Copy into the original array from buffer (sortedArr)
    for(int i = 0, j = si; i < sortedArr.size(); i++, j++)
        arr[j] = sortedArr[i];
}

//  Divide the array into 2 parts (divide)
void divide(vector<int>& arr, int lb, int rb)
{

    if(lb >= rb)
        return;

    int mid = lb + (rb - lb) / 2;

    divide(arr, lb, mid);
    divide(arr, mid +1, rb);
    conquer(arr, lb, mid, rb);

}

int main()
{
    int n;
    cin>> n;

    vector<int> arr(n);
    inputData(arr, n);

    divide(arr, 0, n -1);
    print(arr, n);

}
