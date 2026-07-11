class Solution {
public:
    void dfs(int node, vector<int>adj[],vector<bool>& vis,vector<int>&curr){
        curr.push_back(node);
        for(int x:adj[node]){
            if(!vis[x]){
                vis[x]=true;
                dfs(x,adj,vis,curr);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        vector<vector<int>>ans;
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>curr;
                c++;
                vis[i]=true;
                dfs(i,adj,vis,curr);
                ans.push_back(curr);
            }
        }

        for(auto vec: ans){
            int sz=vec.size();
            // bool fl=false;
            for(int x:vec){
                if(adj[x].size()!=sz-1){//every n0ode is connected to an other nodes so sz-1 nodes should be present in each adjacency.
                    c--;
                    break;
                }
            }
        }
        return c;


    }
};