#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s; 
    /*
    the procedure is to first check first two halves
    if they are same then 
    ans++ and check for two halves of first half
    else break and print ans;

    */
    int ans=0,tmp=n;
    while(tmp>1){
        int mid = tmp/2;
        string s1="",s2="";
        /*
         Eg:    s = abababab
                        |   |
                       mid tmp
        */

    //    Time Complexity as far as I know is: O(n*logn)

        for(int i=0;i<mid;i++){
            s1 += s[i];
        }
        for(int i=mid;i<tmp;i++){
            s2 += s[i];
        }
        if(s1==s2) ans++;
        else break;
        
        tmp = tmp/2;
    }
    cout<<ans;
    return 0;
}