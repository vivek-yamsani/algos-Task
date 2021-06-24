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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 1);
    /*
        In this approach we are thinking in a way 
        which makes us not to traverse on the array for every query
        and we use prefix sum for that 
        as if we add value for first index of query
        while taking prefix sum it will be added to all elements after first
        but we should restrict it till rth index  
        so we subtract that value from (r+1)th element
    */

    // Time Complexity is O(q) + O(n)
    // traversal over array for prefix sum calculation and O(q) for operations on every query
    For(i, q)
    {
        int l, r, v;
        cin >> l >> r >> v;
        a[l] += v;
        if (r < n)
            a[r + 1] -= v;
    }

    int mx = a[1];

    for (int i = 2; i <= n; i++)
    {
        a[i] += a[i - 1];
        mx = max(mx, a[i]);
    }

    cout << mx;

    return 0;
}