#include<bits/stdc++.h>
using namespace std;

class Solution {
    ofstream outdata;
    vector<int> topDown;
public:
    Solution(int N){
        outdata.open("debugOutput.txt");
        topDown = vector<int>(N+1,-1);
        topDown[0] = 1;
    }
    int topDownDP(vector<int> nums,int currSum, int target){
        if(topDown[currSum] != -1)   return topDown[currSum];
        int res = 0;
        for(auto num : nums){
            if(num <= currSum)
                res += topDownDP(nums,currSum-num,target);
        }
        return topDown[currSum] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1,0);
        dp[0] =1;
        
        for(int i=0;i<=target;i++){
            this->outdata<<i<<" : ";
            for(int j=0;j< nums.size();j++){
                if(i >= nums[j]){
                    outdata<<dp[i]<<" ";
                    dp[i] += dp[i-nums[j]];
                }
            }
            outdata<<endl;
        }
        outdata.close();
        return dp[target];
        // Bottom-up solution for each possible sum we iterate over 
        // all the elements for our array and add the result if any previous result
        // is reachable from that sum i and is precomputed with us
    }
};

int main(){
    vector<int> arr = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    int target = 999;
    Solution s(target);
    int bottomUp = s.combinationSum4(arr,target);
    int topDown = s.topDownDP(arr,target,target);
    cout<<topDown<<" "<<bottomUp;
    return 0;
}