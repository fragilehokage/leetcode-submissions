class Solution {
public:

    int f(int idx, vector<int>&dp,vector<int>&nums){
        if(idx==0)return nums[0];
        if(idx<0)return 0;

        if(dp[idx]!=-1) return dp[idx];
        int pick =nums[idx]+f(idx-2,dp,nums);
        int notpick= 0+ f(idx-1,dp,nums);

        return dp[idx]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(n-1,dp,nums);
    }
};