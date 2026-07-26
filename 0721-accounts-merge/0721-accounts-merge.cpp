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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // vector<vector<string>>ans;
        int n=accounts.size();
        map<string,int>m;
        dsu ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }else{
                    ds.unionBysize(i,m[accounts[i][j]]);
                }
            }
        }
        vector<string>mails[n];
        for(auto it:m){
            string mail=it.first;
            int pu=ds.findpar(it.second);
            mails[pu].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0)continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(string s:mails[i]){
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};