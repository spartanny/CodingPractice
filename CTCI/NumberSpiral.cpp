#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        long long mx = max(x,y);
        bool flag = mx%2;
        x-=1;y-=1;
        long long end = mx*mx;
        long long start = (mx-1)*(mx-1)+1;
        // cout<<"start is "<<start<<" End "<<end<<" ";
        if(x<mx){
            if(flag) cout<<end-x;
            else cout<<start+x;
        }
        else if(y<mx){
            if(flag) cout<<start+y;
            else cout<<end-y;
        }
        else cout<<(start+end)/2;
        cout<<endl;
    }
}