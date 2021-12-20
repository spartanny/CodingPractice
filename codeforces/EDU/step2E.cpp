#include<bits/stdc++.h>
using namespace std;

double c;
bool good(double m){
    return (pow(m,2) + sqrt(m)) >= c;
}

int main(){
    cin>>c;
    double l =0,r = 1e6;

    for(int i=0;i<100;i++){
        double mid = (l+r)/2;
        if(good(mid))
            r = mid;
        else
            l = mid;
    }
    cout<<setprecision(20)<<r<<"\n";
}