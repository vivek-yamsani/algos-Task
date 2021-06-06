#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
    long int n,r,x,y;
    cin>>n>>r>>x>>y;
    bool c[n],s[n];
    long tmp = r;
    /*
        if both the are 1 then add money 
        else if only conducting workshop -subtract money
    */

    // Time Complexity as far as I know is: O(n);
    for(int i=0;i<n;i++){
        cin>>c[i];    
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        if(c[i]==1){
            if(s[i]) r += x;
            else r -= y;
        }
        
    }

    if(r==tmp) cout<<"no change";
    else if(r>tmp) cout<<"promoted";
    else cout<<"demoted";
    return 0;
}