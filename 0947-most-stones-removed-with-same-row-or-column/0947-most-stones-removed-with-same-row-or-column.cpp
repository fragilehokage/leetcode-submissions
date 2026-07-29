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
    
    int removeStones(vector<vector<int>>& stn) {

        
       
        // dsu ds(n);//treating row and column as a node i.e i,0 & 0,i elements all are present are treated as a node
        // for(int i=0;i<n;i++){//0(n*n)
        //     for(int j=i+1;j<n;j++){
        //         if(stn[i][0]==stn[j][0]  || stn[i][1]==stn[j][1] ){
        //             ds.unionBysize(i,j);
        //         }
        //     }
        // }

        // int numofconnectedcomp=0;
        // for(int i=0;i<n;i++){
        //     if(ds.findpar(i)==i){
        //          numofconnectedcomp++;
        //     }
        // }
        // return n- numofconnectedcomp;



        //2nd sol 
        //tc:0(stones.size)
        //sc:0(m+n) m:col n:row
        int n=stn.size();
        int maxr=0;//to which row must be calculated for last sone
        int maxc=0;
        for(auto st:stn){
            maxr=max(maxr,st[0]);
            maxc=max(maxc,st[1]);
        }
        dsu ds(maxr+maxc+1);//size of dsu 
        unordered_map<int,int>stones;//for checking rows and cols that it contains stone or not
        for(auto st:stn){
            int noder=st[0];
            int nodec=st[1]+maxr+1;//formula for assigning col a no. after all rows
            ds.unionBysize(noder,nodec);
            stones[noder]=1;
            stones[nodec]=1;
        }
        int nc=0;
        for(auto stone:stones){
            if(ds.findpar(stone.first)==stone.first){
                nc++;//no. of connected components
            }
        }

        return n-nc;//final answer 

    }
};