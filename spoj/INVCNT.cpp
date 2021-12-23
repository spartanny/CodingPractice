#include<bits/stdc++.h>
using namespace std;

int inversion;
void merge(vector<int> &nums,int start,int mid,int end){
    
    int left = start,right = mid+1,i=start;
    int j = mid+1;
    for(int i=start;i<=mid;i++){
        while(j<=end and nums[i]>nums[j]){
            j++;
        }
        inversion += (j-right);
    }
    vector<int> temp;
    while(left<=mid and right<=end){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left++]);
        }else
            temp.push_back(nums[right++]);
    }
    while(left<=mid)
        temp.push_back(nums[left++]);
    while(right<=end)
        temp.push_back(nums[right++]);

    for(int i=0;i<temp.size();i++)
        nums[i+start]=temp[i];
}

void divide(vector<int> &nums,int start,int end){
    if(start>=end)
        return;
    int mid = (start+end)/2;
    divide(nums,start,mid);
    divide(nums,mid+1,end);
    merge(nums,start,mid,end);
}

int main(){
    int t;cin>>t;
    while(t--){
        inversion =0;
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        divide(a,0,n-1);
        char s;cin>>s;
        cout<<inversion<<endl;
    }
}