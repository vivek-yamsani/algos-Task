#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        /*
            procedure that I thought is 
            to divide that structure into 3 parts
            first one printing 1 and last line 
            and then creating the spaced structure 

            and Time Complexity as far as I know is : O(n*n);
        */
        for(int i=0;i<n;i++) cout<<"*";
        cout<<endl;
        int half = n/2;
        for(int i=half;i>0;i--){
            for(int j=0;j<i;j++) cout<<"*";
            for(int j=0;j<n-(i*2);j++) cout<<" ";
            for(int j=0;j<i;j++) cout<<"*";
            cout<<endl;
        }
        for(int i=2;i<=half;i++){
            for(int j=0;j<i;j++) cout<<"*";
            for(int j=0;j<n-(i*2);j++) cout<<" ";
            for(int j=0;j<i;j++) cout<<"*";
            cout<<endl;
        }
        for(int i=0;i<n;i++) cout<<"*";
        cout<<endl;
    }   
    return 0;
}