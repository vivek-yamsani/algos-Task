#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    For(i, n - 1) cin >> a[i];
    vector<int> v(n);
    v[0] = a[0];
    /*
        solution is 
        traverse over all ans vector 
        check ans[i] > b[i](given in question)
        if yes
        then 
        ans[i]&ans[i+1] = b[i]

        else 
        ans[i+1] = b[i] 

    */ 

    // Time Complexity is O(n)
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > a[i])
        {
            v[i] = a[i];
            v[i + 1] = a[i];
        }
        else
        {
            v[i + 1] = a[i];
        }
    }

    ll sum = 0;

    For(i, n)
    {
        sum += v[i];
    }
    cout << sum;

    return 0;
}