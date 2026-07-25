class Solution {
public:
//    //prims
//         int n=points.size();
//         int mcost=0;

//         vector<bool>vis(n,false);
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//         unordered_map<int,int>mst;
//         pq.push({0,0});
//         while(!pq.empty()){
//             auto edge=pq.top();
//             pq.pop();
//             int cost=edge.first;
//             int u=edge.second;
//             if(vis[u]){
//                 continue;
//             }
//             vis[u]=true;
//             mcost+=cost;

//             for(int v=0;v<n;v++){
//                 if(!vis[v]){
//                     int dist=abs(points[u][0]-points[v][0])+abs(points[v][1]-points[u][1]);
//                     if(mst.find(v)==mst.end() ||  dist<mst[v]){
//                         mst[v]=dist;
//                         pq.push({dist,v});
//                     }
//                 }
//             }
//         }
//         return mcost;

//kruskal

    class DSU{
            int n;
            vector<int> par, size;
        public:

            DSU(int n){
                this->n = n;
                par.resize(n+1, -1);
                size.resize(n+1, 1);
            }

            int findPar(int node){
                return par[node] == -1 ? node : par[node] = findPar(par[node]);
            }

            bool unite(int u, int v){
                u = findPar(u);
                v = findPar(v);

                if( u == v ) return 0;
                if( size[u] > size[v] ) swap(u, v);
                par[u] = v;
                size[v] += size[u];
                return 1;
            }
        };
    int mstKruskal(int n, vector<vector<int>> &es){      
        sort(es.begin(), es.end());

        int mstWt = 0;
        DSU dsu(n);

        for(auto &e : es){
            int wt = e[0], u = e[1], v = e[2];
            if( dsu.unite(u, v) ) mstWt += wt;  
        }
        return mstWt;
    }

    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size();
        auto manDist = [](vector<int> &a, vector<int> &b){
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };

        vector<vector<int>> es;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                es.push_back({manDist(ps[i], ps[j]), i, j});
            }
        }
        return mstKruskal(n, es);
    }
};