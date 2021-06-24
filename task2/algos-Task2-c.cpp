#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

vector<bool> safe(100001,1);

int ways(int n)
{
    int dp[n + 1] = {0};
    dp[0] = 1;
    if (safe[1])
        dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (safe[i - 1])
            dp[i] += dp[i - 1];
        if (safe[i - 2])
            dp[i] += dp[i - 2];
        dp[i] = dp[i] % mod;
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    /*
    the approach used is
    that no of ways to reach ith step -> dp[i]
    as he can jump two steps 
    so by assuming both the steps are safe i.e i-1,i-2
    so no of ways to reach ith step is no of ways to reach (i-1)th step + (i-2)th step
    dp[i] = dp[i-1] + dp[i-2]
    */

//    Time Complexity for this solution is O(n)
//    as we are traversing every step
    For(i, m)
    {
        int a;
        cin >> a;
        // creating bool array to 
        // to mark it as safe to step or not
        safe[a] = 0;
    }

    cout << ways(n);
    return 0;
}