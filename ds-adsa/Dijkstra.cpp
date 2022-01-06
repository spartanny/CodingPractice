#include <bits/stdc++.h>
using namespace std;
#define ll long long
// PROBLEM LINK
// http://codeforces.com/problemset/problem/20/C
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<long long> distance(n + 1, LONG_MAX),parent(n+1,-1);
    vector<pair<ll, ll>> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    distance[1] = 0;
    while (!pq.empty())
    {
        auto pair = pq.top(); // pair = {distance to reach this node, node's index}
        pq.pop();
        for (auto it : g[pair.second])
        { // it = {node,weight}
            if(distance[it.first] > pair.first + it.second){
                parent[it.first] = pair.second;
                distance[it.first] = pair.first + it.second;
                pq.push({distance[it.first],it.first});
            }
        }
    }
    ll node = n;
    if(parent[node] == -1){
        cout<<-1;
        return 0;
    }
    stack<ll> s;
    while(node != -1){
        s.push(node);
        node = parent[node];
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}