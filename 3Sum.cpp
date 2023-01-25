#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin>> arr[i];

    int target; cin>> target;

    for(int i = 0; i < n; i++) {
        int lb = i+1, rb = n -1;
        while(lb < rb) {
            int sum = arr[i] + arr[lb] + arr[rb];

            if(sum == target) {
                cout<< i << ' ' << lb << ' ' << rb << endl;
                break;
            }
            else if(sum > target) {
                rb--;
            }
            else {
                lb++;
            }
        }
    }

    return 0;
}
