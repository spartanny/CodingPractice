#include<bits/stdc++.h>

#define pb push_back;
#define f first;
#define s size;
#define REP(i,a,b) for(ll i=0;i<a;i++);
using namespace std;

int dfs(int index,vector<vector<int>> graph,vector<bool>& visited, int count){
    if(!visited[index]){
        visited[index] = true;
        for(auto j: graph[index]){
            if(!visited[j]){
                dfs(j,graph,visited,count+1);
            }
        }
    }
    return count;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int> (m));
    vector<vector<int>> g(n*m);
    vector<bool> visited(n*m+1,false);
    vector<int> rooms;int count = 0;
    for(int i= 0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;cin>>temp;
            arr[i][j] = temp;
            if(temp &(1<<1) == 0 ){
                g[count].push_back(count-1);
                cout<<count<<" : "<<count-1;
            }
            if(temp &(1<<2) == 0 ){
                g[count].push_back(count + m);
                cout<<count<<" : "<<count+m;
            }
            if(temp &(1<<3) == 0 ){
                g[count].push_back(count + 1);
                cout<<count<<" : "<<count+1;
            }
            if(temp &(1<<4) == 0 ){
                g[count].push_back(count - m);
                cout<<count<<" : "<<count-m;
            }
            count++;
        }
    }
    
    for(int i = 0;i<n*m; i++){
        if(!visited[i]){
            rooms.push_back(dfs(i,g,visited,1));
        }
    }
    sort(rooms.begin(),rooms.end());

return 0;
}