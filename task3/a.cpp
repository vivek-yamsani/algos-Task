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
    // As the input size is so large
    // we use strings
    string n;
    cin >> n;
    int sum,ans=0;
    while (n.size() > 1)
    {
        sum = 0;
        For(i, n.size())
        {
            sum += n[i] - '0';
        }
        n = to_string(sum);
        ans++;
    }

    cout<<ans;
    return 0;
}