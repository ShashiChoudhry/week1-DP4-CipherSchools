#include<bits/stdc++.h>
using namespace std;

vector<string> dialPad = { "", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinations(string &digits, string &str, vector<string>& result, int start)
{
    if(str.size() == digits.size()) {
        result.push_back(str);
        return;
    }

    char pressedNum = digits[start];
    string possComb = dialPad[pressedNum - '0'];

    for(int i = 0; i < possComb.size(); i++) {
        str.push_back(possComb[i]);
        letterCombinations(digits, str, result, start +1);
        str.pop_back();
    }
}

int main()
{
    string digits;
    cin>> digits;

    vector<string> result;
    string str = "";

    letterCombinations(digits, str, result, 0);

    for(auto st : result)
        cout<< st << endl;
}

