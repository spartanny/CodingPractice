#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string k = to_string(n);
        if((k[k.length()-1]-'0')%2 == 0){
            cout<<0<<endl;
            continue;
        }
        if((k[0]-'0')%2 == 0){
            cout<<1<<endl;
            continue;
        }
        bool flag = false;

        for(int i=0;i<k.size();i++){
            if((k[i] -'0')%2 == 0){
                flag = true;
            }
        }
        cout<<((!flag) ? -1 : 2)<<"\n";
    }
}   