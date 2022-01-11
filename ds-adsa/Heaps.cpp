#include <bits/stdc++.h>
using namespace std;

// This code demonstrates the heap functionality 
// using max heap here for reference 
// code can be easily converted for min heap

// Vector container h for heaps, a for array
vector<int> h,a;

void heapify(int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int greater = i;
    cout<<"Left and right "<<left<<" "<<right<<" "<<greater<<endl;
    if(left < h.size() and a[left] >= a[greater])
        greater = left;
    if(right < h.size() and a[right] >= a[greater])
        greater = right;
    
    if(i != greater){
        swap(h[i],h[greater]);
        heapify(greater);
    }
}
void moveup(int i){
    while(i>0){
        int parent = i/2;
        if(h[i] >= h[parent]){
            swap(h[i],h[parent]);
            i/=2;
        }else{
            break;
        }
    }
}
void insert(int val){
    h.push_back(val);
    int n = h.size();
    moveup(n-1);
}
void remove(){
    swap(h[0],h[h.size()-1]);
    h.pop_back();
    heapify(0);    
}
int main() {
    a = {3,4,6,1,2,4,5,6,8};
    for(auto i : a)
        insert(i);
    for(auto i : h)
        cout<<i<<" ";
    cout<<endl;
    remove();
    for(auto i : h)
        cout<<i<<" ";
}
