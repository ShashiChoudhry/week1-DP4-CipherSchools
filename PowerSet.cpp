#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<< arr[i] << ' ';
    cout<< endl;
}
void powerSet(vector<int> &subset, int i, vector<int> &arr)
{

    if(i == arr.size()) {
        printArr(subset);
        return;
    }

    powerSet(subset, i +1, arr);
    subset.push_back(arr[i]);

    powerSet(subset, i +1, arr);
    subset.pop_back();

}

int main()
{
    int n; cin>> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin>> arr[i];

    vector<int> hold;

    powerSet(hold, 0, arr);

}

