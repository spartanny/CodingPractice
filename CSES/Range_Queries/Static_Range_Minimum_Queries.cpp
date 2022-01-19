#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Basic implementation of segment tree without update queries
vector<ll> tree;

ll func(int node,int node_l,int node_h,int query_low,int query_high){
    // if query range is in between node range of seg tree
    if(query_low <= node_l and node_h <= query_high)
        return tree[node];
    // if query range is out of bounds for node range of seg tree
    if(node_l > query_high or node_h < query_low)
        return INT_MAX;
    int mid = (node_l + node_h) >> 1;
    return min(func(2*node,node_l,mid,query_low,query_high),
            func(2*node+1,mid+1,node_h,query_low,query_high));
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // padding arr with dummy values (0) to make it of size 2^n
    while(__builtin_popcount(n) != 1){
        arr.push_back(0);
        n++;
    }

    // Build Tree (Segment Tree)
    tree.resize(2*n);
    for(int i=0;i<n;i++)
        tree[n+i] = arr[i];
    for(int i= n-1;i>=1;i--)
        tree[i] = min(tree[2*i],tree[2*i+1]);

    for(int i=0;i<q;i++){
        int l,h;
        cin>>l>>h;
        --l,--h;
        cout<<func(1,0,n-1,l,h)<<"\n";
    }
}