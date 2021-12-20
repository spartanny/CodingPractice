#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll n,x,y;

bool good(ll time){
    time -= min(x,y);
    return time/x + time/y >= n - 1;
}

int main(){

    cin>>n>>x>>y;
    ll l=min(x,y),r = n*max(x,y);

    while(r > l + 1){
        ll mid = (l+r)/2;
        // cout << "L : " << l << "R : " << r << endl;
        if(!good(mid))
            l = mid + 1;
        else
            r = mid;
    }

    // // cout << "L : " << l << "R : " << r << endl;

    // for(int i = l; i <= r; i++){
    //     // cout << "I : " << i << "GOOD : " << good(i) << endl;
    //     if(good(i))cout << i << endl; return 0;
    // }

    cout<<l<<"\n";
}