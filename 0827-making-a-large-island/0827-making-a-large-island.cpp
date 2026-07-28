class Solution {
public:
        class dsu{
            public:
            vector<int>rank,size,parent;
            dsu(int n){//initialisation for constructor
                rank.resize(n+1,0);
                size.resize(n+1,0);
                parent.resize(n+1);//for 1 as well as 0 based indexing
                for(int i=0;i<=n;i++){
                    parent[i]=i;
                    size[i]=1;
                }
            }
            int findpar(int node){
                if(node ==parent[node]){//ulimate parent
                    return node;
                }
                // return findpar(parent[node]);//logn
                return parent[node]=findpar(parent[node]);//path compression by storing ultimate parent
            }

            void unionBysize(int u,int v){
                int pu=findpar(u);//ultimate parents
                int pv=findpar(v);
                if(pu==pv){
                    return;
                }
                if(size[pu]<size[pv]){
                    parent[pu]=pv;
                    size[pv]+=size[pu];
                }else{//same case of rank or greater as it doesn't matter
                    parent[pv]=pu;
                    size[pu]+=size[pv];
                

                }
            }
            void unionByRank(int u,int v){
                int pu=findpar(u);//ultimate parents
                int pv=findpar(v);
                if(pu==pv){
                    return;
                }
                if(rank[pu]<rank[pv]){
                    parent[pu]=pv;
                }else if(rank[pu]>rank[pv]){
                    parent[pv]=pu;
                }else{//same case of rank
                    parent[pv]=pu;
                    rank[pu]++;//rank increased

                }
            }

        };

    int largestIsland(vector<vector<int>>& grid) {
        //tc:o(n*n)
        //sc:o(n*n)
        int n=grid.size();
        int c0=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    c0++;
                }
            }
        }
        if(c0==0){//all are 1s...so max is already formed
            return n*n;
        }else if(c0==n*n){//there are all 0s so maximum 1 size 1 group can be formed
            return 1;
        }
        dsu ds(n*n);
        vector<int>delr={-1,0,1,0};
        vector<int>delc={0,-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nr=i+delr[k];
                        int nc=j+delc[k];

                        if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                            ds.unionBysize(i*n+j,nr*n+nc);//forming components of 1s group
                        }
                    }
                }
            }
        }
        int maxs=0;
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){//0->1 check and around its four direction..checking size of island if 0 is convertred to 1 and set is used for checking that the 1 are of differeent components if are surrounding  a 0 i.e. no extra components should be added.
                    int sum=0;
                     for(int k=0;k<4;k++){
                        int nr=i+delr[k];
                        int nc=j+delc[k];

                        if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                            int x=ds.findpar(nr*n+nc);
                            if(s.find(x)==s.end()){
                                sum+=ds.size[x];
                                s.insert(x);
                            }
                             
                        }
                    }
                    maxs=max(sum+1,maxs);
                    s.clear();
                }
            }
        }
        return maxs;

    }
};