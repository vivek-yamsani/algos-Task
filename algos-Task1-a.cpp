#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<string, string> ans(string s)
{
    pair<string, string> ans = {"", ""};

    bool flag = 0;
/* the procedure is that 
    the given number is n ;
    as we should find two no's whose avg is n;
    so,n1 is n-k and n2 is n+k;
    as said diff b/w no's should be min so k should be 1
*/

    if (s[s.length() - 1] == '1')
    {   
        // if the last digit of given binary string is 1 then 
        // first string(str) is the lesser one its n-1 so, last digit of binary string is 0;
        ans.first = s;
        ans.first[s.length() - 1] = '0';
        for (int i = s.size() - 1; i >= 0; i--)
        {
            /* for the second str
                we will take an example
                if the given string is 
                     s    =  01111
                adding 1    +    1
                        ------------
                ans.second = 10000

                and the thing here is making all 1's before(traveresing from back) first 0 to 0's
                and the first zero to 1; 
             */
            if (s[i] == '0')
            {   //flag denotes that ans.second exists or not
            //  if flag == true then the string s can be decomposed as ans 
            //  else "no" 
                flag = 1;
                ans.second = s;
                ans.second[i] = '1';
                break;
            }
            else
            {
                s[i] = '0';
            }
        }
    }
    else
    {
        // here adding 1 is easier for us as it doesn't change prefix string(i.e str except last char) 
        ans.second = s;
        ans.second[s.length() - 1] = '1';
        for (int i = s.size() - 1; i >= 0; i--)
        {   /*
            here also let us take an example
                s   =    10000
            subtracting  -   1
                    -----------
                         01111
            here we are making all 0's before first 1 to 1's
        */
            if (s[i] == '0')
            {
                s[i] = '1';
            }
            else
            {
                flag = 1;
                s[i] = '0';
                ans.first = s;
                break;
            }
        }
    }

    return (flag ? ans : make_pair("-1", "-1"));
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    auto p = ans(s);
    if (p.first == "-1")
    {
        cout << "-1";
    }
    else
    {
        cout << p.first << " " << p.second;
    }

    return 0;
}