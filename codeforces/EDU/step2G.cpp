#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll k,n; 
vector<ll> groups;

bool good(ll x){
    ll sum = 0; // parameter x is the number of councils
    for(auto i: groups){
        sum += min(i,x);
    }
    return k*x <= sum;
}
int main(){
    ios_base::sync_with_stdio(false);   
    cin>>k>>n;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        groups.push_back(x);
    }
    ll l=0,r=1e17;

    while(l+1<r){
        ll mid = (l+r)/2;
        if(good(mid))
            l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}