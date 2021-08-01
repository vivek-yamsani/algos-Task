#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

bool check(int a[], ll mid, int k, int n)
{
    int noOfSubarrays = 0;
    ll sum = 0;
    For(i, n)
    {
        if (a[i] > mid)
            return 0;

        sum += a[i];

        if (sum > mid)
        {
            noOfSubarrays++;
            sum = a[i];
        }
    }
    noOfSubarrays++;

    if (noOfSubarrays <= k)
        return 1;

    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> k >> n;
    int a[n];
    ll sum = 0, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mx = mx > a[i] ? mx : a[i];
    }
    /*
        Here Approach is to check for values of maximum subarray sum 
        that the array can be divided into  k subarrays 
        or not
        and find the min of maxSubArrSums 
    */

    ll ans = 0;
    while (mx <= sum)
    {
        ll mid = (mx + sum) / 2;

        if (check(a, mid, k, n))
        {
            ans = mid;
            sum = mid - 1;
        }
        else
            mx = mid + 1;
    }

    cout << ans << "\n";
    return 0;
}