#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll prefiSum = 0,count =0;
    unordered_map<ll,ll> hash;
    hash[0]++;  
    for(ll i=0;i<n;i++){
        prefiSum += a[i];
        prefiSum = (prefiSum%n +n)%n;   // Accomodates the modulo for negative numbers as well
        count += (hash[prefiSum]);
        hash[prefiSum]++;
        // cout<<"prefsum "<<prefiSum<<"hash "<<hash[prefiSum]<<endl;
    }
    cout<<count;
}