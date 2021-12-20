#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> ropes;
ll n,k;

bool func(double x){
    double sum = 0;
    for(auto i: ropes){
        sum += floor(i/x);
    }
    return (sum>=k);
}

int main(){

    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        ropes.push_back(x);
    }
    double l = 0;
    double r = 1e8;
    for(int i=0;i<100;i++){
        double m = (l+r)/2;
        if(func(m))
            l = m;
        else
            r = m;
    }
    cout<<setprecision(20)<<l<<"\n";
}