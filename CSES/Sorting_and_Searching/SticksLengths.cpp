#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> lens(N);
    long long median,ans=0;
    for(int i=0;i<N;i++){
        cin>>lens[i];
    }
    sort(lens.begin(),lens.end());
    median = lens[N/2];
    for(auto i: lens){
        ans += abs(median-i);
    }
    cout<<ans;
}