class Solution {
public:
//can use dijkstra too it will give better complexity :n*e*log n
//csn use bellman ford too compleity same n*n*n
//for both above you have to run n times a\for n sources
//can use floyd warshall too(multi source)

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto e:edges){
            int u= e[0];
            int v=e[1];
            int w=e[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }

        for(int via=0;via<n;via++){//doing via all nodes one by one
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] != INT_MAX && dist[via][j]!=INT_MAX){//important check
                        dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                    }
                    
                }
            }
        }
        vector<int>count(n,0);
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]<=distanceThreshold && i!=j){//checking threshold
                        count[i]++;
                    }
                }
        }
        // for(int y:count){
        //     cout<<y<<" ";
        // }
        int minc=*min_element(count.begin(),count.end());
        int x=0;
        for(int i=0;i<n;i++){
            if(minc==count[i]){//last index of min city
                x=i;
            }
        }
        return x;
        
    }
};