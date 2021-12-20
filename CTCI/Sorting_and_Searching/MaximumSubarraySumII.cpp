#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];

    ll sum =0,maxSum=-1e15;
    
    for(ll i=a-1;i<b;i++){
        sum+=arr[i];
        maxSum = max(sum,maxSum);
    }
    cout<<maxSum;
}