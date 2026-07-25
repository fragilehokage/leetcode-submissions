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

            void unionBysize(int u,int v,int& extra){
                int pu=findpar(u);//ultimate parents
                int pv=findpar(v);
                if(pu==pv){
                    extra++;
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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;//atleast n-1 connections chahiye na
        dsu ds(n);
        int extra=0;
        for(auto c:connections){
            ds.unionBysize(c[0],c[1],extra);
        }
        // if(extra>n-1){
            return extra-(connections.size()-(n)+1);
        // }
        cout<<extra<<endl;
        return extra;
    }
};