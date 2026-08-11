class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& tri){
        if(i==0){
            return tri[0][0];
        }
        if(j>i ||j<0){//for elements index to be not out of bound
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
        // for(int j=0;j<m;j++){
        //     mini=min(mini,f(n-1,j,dp,tri));
        // }

        if(n==1)return tri[n-1][0];
        dp[0][0]=tri[0][0];
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<=i;j++){
                if(j>i )continue;
                int upleft=INT_MAX;
                int up=INT_MAX;
                if(j>0){
                    upleft=dp[i-1][j-1];
                }
                if(j<i){
                    up=dp[i-1][j];
                }
                
                dp[i][j]=tri[i][j]+min(up,upleft);
                if(i==n-1){
                    mini=min(dp[i][j],mini);
                }
            }
        }
        return mini;
    }
};