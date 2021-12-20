#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
Completely mathematical question 
permute 2 knights on the board, find their attack regions
subtract total permutations and attack regions 
*/
ll calculate(ll n){
    if(n<=1) return 0;
    ll p1 = n*n;
    ll p2 = p1-1;
    ll total = (p1*p2)/2;
    ll attack = 4*(n-1)*(n-2);

    return total-attack;
}

int main(){
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)
        cout<<calculate(i)<<endl;
    return 0;
}