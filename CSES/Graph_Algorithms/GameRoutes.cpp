#include<bits/stdc++.h>
using namespace std;

int M = 1e9+7;

int main(){

    int n,m;
    long long ans=0;
    cin>>n>>m;
    unordered_map<int,vector<int>> g;
    unordered_map<int,int> dist;
    vector<int> visited(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(visited[curr]>0 or curr == n){
            visited[curr]++;
            continue;
            }
        for(int node : g[curr]){
            q.push(node);
        }
    }
    cout<<visited[n]%M;
}