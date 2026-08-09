class Solution {
public:
    //memoizatiion soln
    //tc:o(m*n*4)
    //sc: recursion stack +dp array
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
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(og[i][j]==1){
        //             dp[i][j]=-2;//marking them as they can't be included in the path
        //         }
        //     }
        // }
        // if(og[0][0] == 1){//if starting idx is the obstacle
        //     return 0;
        // }
        // return f(m-1,n-1,dp);


        //tabulation
        // dp[0][0]=1;
        // if(og[0][0] == 1){//if starting idx is the obstacle
        //     return 0;
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0)continue;
        //         if(og[i][j]==1){
        //             dp[i][j]=0;
        //         }else{
        //              if(i==0){
        //                 dp[0][j]=dp[0][j-1];
        //             }else if(j==0){
        //                 dp[i][j]=dp[i-1][j];
        //             }
        //             else{
        //                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
                
        //             }
               
        //         }

        //     }
        // }
        // return dp[m-1][n-1];

        //space optimisation like previous part

         if(og[0][0] == 1){//if starting idx is the obstacle
            return 0;
        }
        
        vector<int>prev(n,0);
        // prev[0]=1;


        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }
                if(og[i][j]==1){
                    temp[j]=0;
                }else{
                    if(j==0){
                        temp[j]=prev[j];
                    }
                    else{
                        temp[j]=prev[j]+temp[j-1];
                
                    }
               
                }

            }
            prev=temp;
        }
        return prev[n-1];
        




    

      
    }
};