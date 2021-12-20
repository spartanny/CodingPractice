#include<bits/stdc++.h>
#include<set>
using namespace std;
#define ll long long

ll m,n,k;
int count = 0;
/* 2 pointers approach, see if the user can be served after getting 2 sorted lists
    if not : increment pointers according to the house size or request size
*/
void func(){
    vector<int> house(n),req(m);
    for(int i=0;i<n;i++){
        cin>>house[i];
    }
    for(int i=0;i<m;i++){
        cin>>req[i];
    }
    sort(house.begin(),house.end());
    sort(req.begin(),req.end());

    int l=0,r=0;
    while(l<n and r<m){
        if(abs(house[l] - req[r]) <= k){
            ::count++;
            l++;r++;
        }else{
            if(house[l] > req[r])
                r++;
            else if(house[l] < req[r])
                l++;
        }
    }
}
int main(){
    
    cin>>n>>m>>k;
    func();
    cout<<::count<<endl;
}