class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=f(i-1,j,grid,dp);
        int up=f(i,j-1,grid,dp);
        return dp[i][j] =grid[i][j]+min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m =grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        int ans=f(m-1,n-1,grid,dp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};