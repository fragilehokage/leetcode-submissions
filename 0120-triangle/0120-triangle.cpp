class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& tri){
        if(i==0){
            return tri[0][0];
        }
        if(j>i ||j<0){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up= f(i-1,j,dp,tri);
        int upleft=INT_MAX;
        if(j>0){
             upleft=f(i-1,j-1,dp,tri);
        }
        return dp[i][j]=tri[i][j]+min(up,upleft);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        int m=tri[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mini=INT_MAX;
        for(int j=0;j<m;j++){
            mini=min(mini,f(n-1,j,dp,tri));
        }
        return mini;
    }
};