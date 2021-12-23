#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        if(a<b) swap(a,b);
        if(a>2*b){
            cout<<"NO\n";
            continue;
        }
        long long sum = a+b;
        if((sum%3 ==0) or (a==b and a==0))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}