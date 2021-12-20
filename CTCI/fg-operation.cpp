#include<bits/stdc++.h>
#define MOD 1000000007;
#define pb(x) push_back(x);
typedef long long ll;
using namespace std;

int main(){
    int t; cin>>t;

    vector<vector<ll>> F(t,vector<ll>(10,0)),G(t,vector<ll>(10,0));
    vector<ll> A;
    for(int i=0;i<t;i++){
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    
    vector<int> ans(10,0);
    F[0][A[0]]++;
    G[0][A[0]]++;
    
    for(int i=1;i<t;i++){
        for(int j=0;j<10;j++){
            ll x = F[i-1][j];
            ll y = G[i-1][j];
            if(x != 0){
                ll temp = (A[i]+x)%10;
                F[i][temp]++;
                ll temp2 = (A[i]*x)%10;
                G[i][temp2]++;
            }
            if(y != 0){
                ll temp = (A[i]+y)%10;
                F[i][temp]++;
                ll temp2 = (A[i]*y)%10;
                G[i][temp2]++;
            }
        }
    }

    for(int i=0;i<10;i++){
        if(F[t-1][i] != 0) ans[t]++;
        if(G[t-1][i] != 0) ans[t]++;
    }

    for(int i=0;i<10;i++)
        cout<<ans[i]<<endl;
}