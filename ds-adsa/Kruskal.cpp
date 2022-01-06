#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

void makeset(int N,vector<int> &rank,vector<int> &parent){
    for(int i=0;i<N;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findPar(int node,vector<int> &parent){
    if(parent[node] == node)
        return node;
    return parent[node] = findPar(parent[node],parent);
}
void unionn(int u,int v,vector<int> &rank,vector<int> &parent){
    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else{
        parent[u] = v;
        rank[v]++;
    }
}
bool comp(vector<int> a,vector<int> b){
    return a[2]<b[2];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(),edges.end(),comp);
    vector<int> parent(n),rank(n);
    makeset(n,rank,parent);
    int mstWeight = 0;
    for(auto i: edges)
    {
        int u = i[0],v=i[1],w =i[2];
        if(findPar(u,parent) != findPar(v,parent)){
            unionn(u,v,rank,parent);
            mstWeight += w;
        }
    }
    cout<<mstWeight;
}