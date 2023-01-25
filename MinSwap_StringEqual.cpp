#include<bits/stdc++.h>
using namespace std;

int minSwap(string &str)
{
    stack<char> st;
    int n = str.size();

    for(int i = 0; i < n; i++) {
        if(str[i] == '[') {
            st.push('[');
        }
        else {
            if(!st.empty() && st.top() == '[' && str[i] == ']') {
                st.pop();
            }
            else {
                st.push(str[i]);
            }
        }
    }

    int open = st.size() / 2;

    return (open +1) / 2;
}

int main()
{
    string str;
    cin>> str;

    cout<< minSwap(str);
}
