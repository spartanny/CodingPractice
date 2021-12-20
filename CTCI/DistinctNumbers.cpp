#include<bits/stdc++.h>
#define MOD 1000000007;
#define pb push_back;
#define len length;
#define s size;
typedef long long ll;
using namespace std;

int main(){
    int t; cin>>t;
    map<int,bool> visited;
    for(int i=0;i<t;i++){
        ll temp; cin>>temp;
        if(visited.find(temp) == visited.end()){
            visited[temp] = true;
        }
    }
    cout<<visited.size();    
}