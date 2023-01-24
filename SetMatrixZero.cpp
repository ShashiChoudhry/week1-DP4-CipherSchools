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

void print(vector<vector<int>> &matrix, int m, int n)
{
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<< matrix[i][j] << ' ';
        } cout<< endl;
    }cout<<endl;
}

void setZeroes(vector<vector<int>> &matrix, int m, int n)
{

    vector<bool> row(m), col(n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == true || col[j] == true) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{

    int m, n;
    cin>> m >> n;

    vector<vector<int>> matrix;
    takeInput(matrix, m, n);

    setZeroes(matrix, m, n);
    cout<< endl;

    print(matrix, m, n);
}

