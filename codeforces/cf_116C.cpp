#include<bits/stdc++.h>
#define MOD 1000000007;
#define pb(x) push_back(x);
typedef long long ll;
using namespace std;

// int dfs(vector<vector<int>> &tree, vector<bool> &visited, int i, ll d){
//     if(!visited[i]){
//         visited[i] = true;
//         if(tree[i].size() == 0)
//             return d;
//         else{
//             for(auto j: tree[i])
//                 return max(d,dfs(tree, visited, j, d+1));
//         }
//     }
//     return 1;
// }

int bfs(vector<vector<int>> &tree, vector<bool> &visited, int i, ll d){

    int ans = -1;
    queue<pair<int,int>> q;
    q.push(make_pair(i,d));
    while(!q.empty()){
        pair<int,int> temp = q.front();
        ans = max(ans,temp.second);
        q.pop();
        for(auto j: tree[temp.first]){
            q.push(make_pair(j,temp.second + 1));
        }
    }

    return ans;
}

int main(){
int t; cin>>t;
    vector<vector<int>> tree(t+1);
    vector<int> root;
    for(int i=1;i<=t;i++){
        int temp;cin>>temp;
        if(temp != -1){
            tree[temp].pb(i);}
        else
            root.pb(i);
    }
    vector<bool> visited(t,false);
    int maxDepth =-1;
    for(auto r: root){
        maxDepth = max(maxDepth, bfs(tree,visited,r,1));
    }
cout<< maxDepth<<endl;
}