class Solution {
public:
   int count(int n,vector<int>&dp){
    if(n<=2){
        return n;
    }
        if(dp[n])return dp[n];
        return dp[n]=count(n-1,dp)+count(n-2,dp);
    
   }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        // if(n<=2){
        //     return n;
        // }
        return count(n,dp);
        
    }
};