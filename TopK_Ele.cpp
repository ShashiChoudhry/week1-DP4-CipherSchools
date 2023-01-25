#include<bits/stdc++.h>
using namespace std;

static int comp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second> b.second;
}

vector<int> topKFreq(vector<int>& arr, int k)
{
    int n = arr.size();

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    vector<pair<int, int>> v(mp.begin(), mp.end());
    vector<int> result;
    sort(v.begin(), v.end(), comp);

    for(auto i: v)
    {
        result.push_back(i.first);
        k--;
        if(k == 0)
            break;
    }

    return result;
}

int main()
{
    int n, k;
    cin>> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin>> arr[i];


    vector<int>ans = topKFreq(arr, k);

    for(int i = 0; i < ans.size(); i++) {
        cout<< ans[i] << ' ';
    }

}
