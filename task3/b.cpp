#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i,n) for(int i=0;i<n;i++)
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    // this can be solved by sieve of Eratosthenes 

    int n;
    bool check[100001] = {0};
    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(!check[i]){
            for(int j=i*2;j<=n;j+=i){
                check[j] = 1;
            }
        }
    }
    int x = 0;
    for(int i=2;i<=n;i++){
        if(!check[i]){
            x++;
        }
    }
    cout<< x*(x+1)/2;
return 0;
}