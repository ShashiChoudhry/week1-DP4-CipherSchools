#include<iostream>
#include<vector>
using namespace std;

void inputData(vector<int> &arr, int n)
{
    for(int i = 0; i < n; i++)
        cin>> arr[i];
}

void print(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<< arr[i] << ' ';
    cout<< endl;
}

int waterTrapping(vector<int> &arr, int n)
{
    if(n <= 2)
        return 0;

    int waterStored = 0;

    int lb = 0, rb =  n -1;
    int lBoundary = INT_MIN, rBoundary = INT_MIN;

    while(lb <= rb)
    {
        if(arr[lb] <= arr[rb]) {
            lBoundary = max(lBoundary, arr[lb]);
            waterStored += (lBoundary - arr[lb]);
            lb++;
        }
        else {
            rBoundary = max(rBoundary, arr[rb]);
            waterStored += (rBoundary - arr[rb]);
            rb--;
        }
    }

    return waterStored;
}

int main()
{
    int n; cin>> n;

    vector<int> arr(n);
    inputData(arr, n);

    cout<<waterTrapping(arr, n);

}
