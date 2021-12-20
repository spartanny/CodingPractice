#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n<=3){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    int count = 0,i=1;
    vector<int> a(n,0);
    while(count != n){
        if(a[(i)%n] == 0){
            a[(i)%n] = 1;
            count++;
            cout<<(i)%n+1<<" ";
        }
        if(n%2 == 0 and count == n/2)
            i+=1;
        else    
            i+=2;
    }
    return 0;
}