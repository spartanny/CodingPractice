#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// KADANE'S ALGORITHM
int main(){
    ll n;cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++)
        cin>>a[i];
    ll currSum=0,maxSum=-1e10;

    for(auto i:a){
        currSum += i;
        if(currSum>maxSum)
            maxSum = currSum;
        if(currSum<0)
            currSum = 0;
    }
    cout<<maxSum;
}