class Solution {
public:
   int timer=1;

    void dfs(int node,int parent,vector<int> adj[],vector<int>&ti ,vector<int>&lowi ,vector<bool>&vis ,vector<vector<int>>&ans){
        vis[node]=true;
        ti[node]=lowi[node]=timer;
        timer++;
        for(int y:adj[node]){
            if(y==parent)continue;
            if(!vis[y]){
                dfs(y,node,adj,ti,lowi,vis,ans);
                lowi[node]=min(lowi[node],lowi[y]);
                if(lowi[y] > ti[node]){
                    ans.push_back({node,y});
                }
            }else{
                 lowi[node]=min(lowi[node],ti[y]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<bool>vis(n,false);
        vector<int>timeins(n,0);
        vector<int>lowins(n,0);
        // for(int i=0;i<n;i++){
        //     timeins[i]=lowins[i]=i;
        // }
        vector<vector<int>>ans;
        dfs(0,-1,adj,timeins,lowins,vis,ans);
        return ans;
    }
};