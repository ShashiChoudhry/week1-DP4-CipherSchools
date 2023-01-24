#include<bits/stdc++.h>
using namespace std;

void inputData(vector<int> &arr, int n)
{
    for(int i = 0; i < n; i++)
        cin>> arr[i];
}

int searchSorted(vector<int>& nums, int target)
{
    int n = nums.size();
    int lb = 0, rb = n -1;

    while(lb <= rb)
    {
        int mid = lb + (rb - lb) / 2;

        if(nums[mid] == target) {
            return mid;
        }

        if(nums[lb] <= nums[mid]) {
            if(nums[lb] <= target && target <= nums[mid])
                rb = mid -1;
            else
                lb = mid +1;
        } else {
            if(nums[mid] <= target && target <= nums[rb])
                lb = mid +1;
            else
                rb = mid -1;
        }
    }

    return -1;
}

int main()
{
    int n, target;
    cin>> n >> target;

    vector<int> arr(n);
    inputData(arr, n);

    cout<< searchSorted(arr, target);

    return 0;
}

