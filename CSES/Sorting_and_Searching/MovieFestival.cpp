#include<bits/stdc++.h>
using namespace std;
struct movie{
    int start,end;
    movie(int a, int b){
        start = a, end = b;
    }
    bool operator<(const movie& b) const {return b.end>end;}
};

int main(){
    int N;
    cin>>N;
    multiset<movie> movies;
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        movies.insert(movie(a,b));
    }
    int count =0;
    int end=-1;
    for(auto i: movies){
        if(i.start>=end){
            count++;
            end = i.end;
        }
    }
    cout<<count << endl;
}