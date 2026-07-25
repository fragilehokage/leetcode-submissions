class Solution {
public:
   

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int mcost=0;

        vector<bool>vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mst;
        pq.push({0,0});
        while(!pq.empty()){
            auto edge=pq.top();
            pq.pop();
            int cost=edge.first;
            int u=edge.second;
            if(vis[u]){
                continue;
            }
            vis[u]=true;
            mcost+=cost;

            for(int v=0;v<n;v++){
                if(!vis[v]){
                    int dist=abs(points[u][0]-points[v][0])+abs(points[v][1]-points[u][1]);
                    if(mst.find(v)==mst.end() ||  dist<mst[v]){
                        mst[v]=dist;
                        pq.push({dist,v});
                    }
                }
            }
        }
        return mcost;
    }
};