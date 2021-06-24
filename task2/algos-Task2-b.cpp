#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i, j, n) for (int i = j; i <= n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    ll a[n + 1] = {0};
    For(i, 1, n)
    {
        a[i] = i;
    }
    // this is brute force approach
    // and better approach using prefix sum is in 'e' part
    // Time complexity of this solution is O(n*q)
    // as in worst case every query has indices as 1 & n 
    For(i, 0, q - 1)
    {
        int l, r, v;
        cin >> l >> r >> v;
        For(j, l, r)
        {
            a[j] += v;
        }
    }
    ll mx = a[1];
    For(i, 1, n)
    {
        mx = max(mx, a[i]);
    }

    cout << mx;
    return 0;
}