#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(string &str, vector<string>& result, int open, int close)
{
    if(open > close || open < 0 || close < 0)
        return;

    if(open == 0 && close == 0) {
        result.push_back(str);
        return;
    }

    str.push_back('(');
    generateParenthesis(str, result, open -1, close);
    str.pop_back();

    str.push_back(')');
    generateParenthesis(str, result, open, close -1);
    str.pop_back();

}

int main()
{
    int n; cin>> n;
    vector<string> result;
    string str = "";

    int open = n, close = n;

    generateParenthesis(str, result, open, close);

    for(auto st : result)
        cout<< st << endl;
}
