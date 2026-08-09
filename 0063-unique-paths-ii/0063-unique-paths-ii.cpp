class Solution {
public:

    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }
        if(  i<0 || j<0  ||dp[i][j]==-2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=f(i-1,j,dp);
        int up=f(i,j-1,dp);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m =og.size();
        int n=og[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(og[i][j]==1){
                    dp[i][j]=-2;
                }
            }
        }
        if(og[0][0] == 1){
            return 0;
        }
        return f(m-1,n-1,dp);
      
    }
};