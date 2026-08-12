class Solution {
public:
        int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
                if(i<0 || j<0 || j>=grid[0].size()){//base cases
                    return INT_MAX;
                }
                if(i==0){//1st row is reached
                    return grid[i][j];
                }
                
                if(dp[i][j]!=INT_MIN){//already calculated
                    return dp[i][j];
                }
                //given in question
                int up=f(i-1,j,grid,dp);
                int diagleft=f(i-1,j-1,grid,dp);
                int diagright=f(i-1,j+1,grid,dp);
                return dp[i][j] =grid[i][j]+min(diagleft,min(up,diagright));
        }

        int minFallingPathSum(vector<vector<int>>& grid) {
            int m =grid.size();
            int n=grid[0].size();
            vector<vector<int>>dp(m,vector<int>(n,INT_MIN));//contains negative entries too therefore using int_min instead of -1
            int mini=INT_MAX;
            for(int i=0;i<n;i++){
                mini=min(mini,f(m-1,i,grid,dp));//to check min of all last row indices
            }
            return mini;
            
        }
};