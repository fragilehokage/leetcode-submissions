class Solution {
public:
void dfs(int node ,vector<int>adj[],vector<bool>&vis){
   for(auto x:adj[node]){
    if(!vis[x]){
        vis[x]=true;
        dfs(x,adj,vis);
    }
   }
}


    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(auto e:invocations){
            adj[e[0]].push_back(e[1]);
        }

        vector<bool>vis(n,false);
        vis[k]=true;
        dfs(k,adj,vis);



        bool fl=false;
        for(auto e:invocations){
            int u= e[0];
            int v=e[1];

            if(!vis[u]  && vis[v]){//bahaar se edge aa rha
                fl=true;
                break;
            }
        }

        vector<int>ans;
        if(fl==false){
            for(int i=0;i<n;i++){
                if(!vis[i])ans.push_back(i);
            }
        }else{
              for(int i=0;i<n;i++){
                ans.push_back(i);
             }
        }
        return ans;
        

       

        


    }
};