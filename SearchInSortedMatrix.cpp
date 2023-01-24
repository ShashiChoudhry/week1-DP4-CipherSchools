#include<iostream>
#include<vector>
using namespace std;

void takeInput(vector<vector<int>> &matrix, int m, int n)
{

    for(int i = 0; i < m; i++) {
        vector<int> row(n);
        for(int j = 0; j < n; j++) {
           cin>> row[j];
        }
        matrix.push_back(row);
    }
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    if(m < 0) return false;

    int c = n -1, r = 0;

    while(r < n && c >= 0)
    {
        if(target == matrix[r][c]) {
            return true;
        }
        else if(target > matrix[r][c]) {
            r++;
        }
        else {
            c--;
        }
    }
    return false;
}

int main()
{

    int m, n, target;
    cin>> m >> n ;

    vector<vector<int>> matrix;
    takeInput(matrix, m, n);

    cin>> target;

    bool found = searchMatrix(matrix, target);

    if(found)
        cout<< "YES" << endl;
    else
        cout<< "NO" << endl;

}


