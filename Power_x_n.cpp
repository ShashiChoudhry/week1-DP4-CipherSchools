#include<bits/stdc++.h>
#define ll long long
using namespace std;

double findPower(double n, ll x)
{

    if(x == 0)
        return 1;

    if(n == 0)
        return 0;

    double ans = findPower(n, x / 2);
    ans = ans*ans;

    if(x % 2 == 1)
        ans = ans*n;

    return ans;
}

double power(double n, ll x)
{

    if(x >= 0)
        return findPower(n, x);

    return (double) 1 / findPower(n, abs(x));
}

int main()
{
    double n; int x;
    cin>> n >> x;

    cout<<power(n, x);
}
