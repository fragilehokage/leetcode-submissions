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

    int f2(int idx, vector<int>&dp,vector<int>&nums){
        if(idx==1)return nums[1];
        if(idx<1)return 0;

        if(dp[idx]!=-1) return dp[idx];
        int pick =nums[idx]+f2(idx-2,dp,nums);
        int notpick= 0+ f2(idx-1,dp,nums);

        return dp[idx]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n+1,-1);

        int withfirst= f(n-2,dp,nums);
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }

        int withoutfirst=f2(n-1,dp,nums);

        return max(withfirst,withoutfirst);
    }
};