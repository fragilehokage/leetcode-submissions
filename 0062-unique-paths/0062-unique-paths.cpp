class Solution {
public:
//memoization solution 
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0||j==0){//only one straight path remains
            return 1;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        //no.of ways from up:right is treated as left from down i.e. mirror
        int left=f(i-1,j,dp);//no.of ways from left
        int up=f(i,j-1,dp);//no. of ways from up

        return dp[i][j]=left+up;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // // return f(m-1,n-1,dp);

        // //tabulation soln
        // //base cases
        // for(int i=0;i<m;i++){
        //     dp[i][0]=1;
        // }
        // for(int j=1;j<n;j++){
        //     dp[0][j]=1;
        // }
        // //doing the moves required to move from up to down
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         dp[i][j]=dp[i-1][j]+dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];


        //space optimisation
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if (i == 0 && j == 0) {
                    temp.push_back(1);
                    continue;
                }
                int step=0;
                if(j==0){
                    step+=prev[0];
                }else{
                    step+=prev[j]+temp.back();
                }
                temp.push_back(step);
            }
            prev=temp;
        }
        return prev[n-1];
    }
};