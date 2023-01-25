#include<bits/stdc++.h>
using namespace std;

void permute(string &str, vector<string>& result, int i = 0)
{
    if(str.size() == 0)
        return;

    if(i == str.size() -1) {
        result.push_back(str);
        return;
    }

    for(int j = i; j < str.size(); j++) {
        swap(str[i], str[j]);
        permute(str, result, i +1);
        swap(str[i], str[j]);
    }
}
int main()
{
    string str;
    cin>> str;

    vector<string> result;

    permute(str, result, 0);

    for(auto perm : result)
        cout<< perm << endl;
}
