#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {

    stack<char> st;
    int i = 0;
    for(auto ele: s) {
        if(st.empty()) {
            if(ele == ')' || ele == '}' || ele == ']')
                return false;
        }

        if(ele == '(' || ele == '{' || ele == '[') {
            st.push(ele);
        } else {
            if(st.empty()) return false;
            if(ele == ')' && st.top() == '(') {
                st.pop();
            }
            else if(ele == '}' && st.top() == '{') {
                st.pop();
            }
            else if(ele == ']' && st.top() == '[') {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}
int main()
{
    string str;
    cin>> str;

    bool ans = isValid(str);

    if(ans)
        cout<< "YES" << endl;
    else
        cout<< "NO" << endl;
}
