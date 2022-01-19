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
        return 0;
    int mid = (node_l + node_h) >> 1;
    return func(2*node,node_l,mid,query_low,query_high) 
        + func(2*node+1,mid+1,node_h,query_low,query_high);
}

void update(int k, int u,vector<int> &arr){
    // update the index k with value u
    int n = arr.size();
    arr[k] = u;
    tree[n+k] = u;
    int index = (n+k)>>1;
    while(index > 0){
        tree[index] = tree[2*index] + tree[2*index + 1];
        index /= 2;
    }
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
        tree[i] = tree[2*i] + tree[2*i+1];

    for(int i=0;i<q;i++){
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            int k,u;
            cin>>k>>u;
            update(k-1,u,arr);
            break;
        
        case 2:
            int a,b;
            cin>>a>>b;
            cout<<func(1,0,n-1,a-1,b-1);
            printf("\n");   
            break;
        }
    }
}