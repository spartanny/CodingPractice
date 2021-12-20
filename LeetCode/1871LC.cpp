#include<bits/stdc++.h>
#define MOD 1000000007;
#define pb push_back;
typedef long long ll;
using namespace std;

int min(int a, int b){
    if(a<b)
        return a;
    return b;
}

int main(){
    string s = "00111010";
    int minJump = 3;
    int maxJump = 5;
    vector<bool> dp(s.size(),false);
    dp[0]  = true;
    
    for(int i=0;i<s.size();i++){
        if(s[i]!= '0')
            continue;
        
        int a = (i+minJump);
        int b = min(i+maxJump,s.length()-1); 
        if(s[a] == '0' and dp[i]== true and a<s.size())
            dp[a] = true;
        if(s[b] == '0' and dp[i]== true)
            dp[b] = true;
    }
    
    cout<<dp[s.size()-1]<<endl;
}