#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    vector<vector<int>> result;
    int start = intervals[0][0], end = intervals[0][1];

    for(int i = 1; i < n; i++) {
        if(intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        }
        else {
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    result.push_back({start, end});

    return result;
}

int main()
{
    int n; cin>> n;
    vector<vector<int>> intervals(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            cin>> intervals[i][j];
        }
    }


    vector<vector<int>> ans = mergeIntervals(intervals);

    for(int i = 0; i < ans.size(); i++) {
        cout<< ans[i][0] << ' ' << ans[i][1] << endl;
    }
}
