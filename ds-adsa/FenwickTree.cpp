#include<bits/stdc++.h>
using namespace std;

vector<int> fen;

void update(int idx,int val){
    while(idx < fen.size()){
        // cout<<idx<<endl;
        fen[idx] += val;
        idx += (idx&(-idx));
    }
}
int sum(int idx){
    // idx represents prefix sum of first idx elements
    int s=0;
    while(idx>0){
        s += fen[idx];
        idx -= (idx&(-idx));
    }
    return s;
}
int main(){
    int n = 8;
    fen = vector<int>(n+1,0);
    vector<int> arr = {1,4,2,3,5,6,7,9};
    for(int i=0;i<n;i++){
        update(i+1,arr[i]);
    }
    cout<<sum(2)<<endl;
}