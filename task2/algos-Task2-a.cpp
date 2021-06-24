#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int ans = 0, i = 0;
        stack<char> st;
    
        /*
            the approach is 
            when an opening bracket found push it into stack
            when closing one is encountered 
            then check if the stack is empty or not
            if it is empty 
            then ans equals to length traversed till previous element
            and break the loop 
            else
            pop top element and continue
        */
        // Time Complexity of this solution is O(n)
        // we will traverse over all charcters if all are opening brackets
        // and 
        // Space Complexity is O(n) 
        // as we are storing every element
        // if all are opening brackets
        for (; i < s.length(); i++)
        {
            if (s[i] == '<')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                    st.pop();
                else
                {
                    ans = i;
                    break;
                }
            }
        }
        if (st.empty())
            ans = i;
        cout << ans << "\n";
    }
    return 0;
}