#include<bits/stdc++.h>
using namespace std;

vector<int> indegree;

void print(vector<int> a){
    for(auto i: a)
        cout<<i<<" ";
}
int main(){
    int n,m;
    cin>>n>>m;
    indegree.assign(n+1,0);
    vector<bool> visited(n+1,false);
    vector<int> ans;
    queue<int> result;
    unordered_map<int,vector<int>> g;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indegree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0)
            result.push(i);
    }
    while(!result.empty()){
        int curr = result.front();
        visited[curr] = true;
        ans.push_back(curr);
        result.pop();
        for(int node : g[curr]){
            indegree[node]--;
            if(indegree[node] == 0){ 
                result.push(node);
            }
        }
    }
    if(ans.size()<n)    cout<<"IMPOSSIBLE";
    else    print(ans);
}