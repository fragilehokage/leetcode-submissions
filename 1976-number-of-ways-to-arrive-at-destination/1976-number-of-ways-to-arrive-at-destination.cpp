class Solution {
public:
//tc :o(roads.size * log(n))
//sc: o(2*e)
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1000000007;
        vector<pair<int,int>>adj[n];
        for(auto r:roads){
            int u=r[0];
            int v=r[1];
            int w=r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long>dist(n,LLONG_MAX),ways(n,0);
        ways[0]=1;
        dist[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long dis = it.first;
            int u = it.second;

            if(dis > dist[u]) continue;
            if(u==n-1) return ways[n-1];
            for(auto itt:adj[u]){
                if(dis+ itt.second < dist[itt.first]){//if new shortest distance
                    dist[itt.first]= dis + itt.second;
                    ways[itt.first] =ways[u];
                   pq.push({dist[itt.first], itt.first});
                }else if( dis+ itt.second == dist[itt.first]){//if distance is same as shortest distance then add no. of ways
                   ways[itt.first]=( ways[itt.first]+ways[u]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};