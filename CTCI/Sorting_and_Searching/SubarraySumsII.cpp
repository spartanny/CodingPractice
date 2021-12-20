#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    long long n,x;
    long long prefixSum=0,count=0;
    cin>>n>>x;
    vector<long long> a(n);
    map<ll ,ll> hash;
    hash[0]++;
    for(ll i=0;i<n;i++)
        cin>>a[i];

    for(ll i=0;i<n;i++){
        prefixSum += a[i];
        count += hash[prefixSum-x];
        hash[prefixSum]++;
    }
    cout<<count<<endl;
}