#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

int findMin(int arr[], int n)
{
    /*
        the Approach is to divide the array into 
        two sets such that the diff between the 
        sum of the elements in each set is min
        which makes the minimum of both sums maximum 
    */
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    // dp table stores the boolean values such 
    // dp[i][j] --> true when 
    // the sum->'j' can be achieved by including/excluding elements till ith element->[1,n]
    bool dp[n + 1][sum + 1];

    // sum -> 0 can be obtained by not including any of the elements
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // by including/excluding none elements we can't obtain sum != 0
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {   
            // 1st case if ith element is greater than j(sum of set1) 
            // as we can't take the element into set 
            // we will take ans from previous no of element
            dp[i][j] = dp[i - 1][j];
            
            // else we should consider both cases including and excluding
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }

    // finding maximum of possible minimum set
    int diff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[n][j] == true)
        {
            return j;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, i, k, sum = 0;
    cin >> k;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum = sum + arr[i];
    }
    if (k == 1)
    {
        cout << sum << '\n';
        return 0;
    }
    cout << (sum - findMin(arr, n)) << '\n';
    return 0;
}