 #include<bits/stdc++.h>
#define MOD 1000000007;
#define pb push_back;
typedef long long ll;
using namespace std;

void printSet(long long n){
    long long sum = (n*(n+1))/4;
    vector<ll> a;
    string b="";
    for(ll i=n;i>=1;i--){
        // cout<<sum<<endl;
        if(sum>=i){
            a.push_back(i);
            sum-=i;
        }else{
            b+=to_string(i)+" ";
        }
    }
    cout<<a.size()<<endl;
    for(auto i:a){
        cout<<i<<" ";
    }cout<<endl<<n-a.size()<<endl<<b;
}

int main(){
    ll t; cin>>t;
    ll sum = (t)*(t+1)/2;
    if(sum %2 == 0){
        cout<<"YES\n";
        printSet(t);
    }
    else    cout<<"NO";  
}