class Solution {
public:
    //memoisation  soln : tc:o(n)  sc:o(n)+o(n) //recursion stack space and dp array
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
        // vector<int>dp(n+1,-1);
        // return f(n-1,dp,nums);


    //tabulation : tc and sc both :o(n)
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int pick=nums[i];
        //     if(i>1){
        //          pick=nums[i]+dp[i-2];
        //     }
        //     int notpick=dp[i-1];
        //     dp[i]=max(pick,notpick);
        // }
        // //  return dp[n-1];

        //space optimization
        int prev=nums[0];
        int prev1=0;
        for(int i=1;i<n;i++){
              int pick=nums[i];
            if(i>1){
                 pick=nums[i]+prev1;
            }
            int notpick=prev;
            int curr=max(pick,notpick);
            prev1=prev;
            prev=curr;
        }
        return prev;

       
    }
};