class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
        }
        
        if(sum%2==1){
            return false;
        }
        
        int k=sum/2;
        vector<int>prev(k+1,0);
        vector<int>curr(k+1,0);

        prev[0]=true;
        if(arr[0]<=k){
            prev[arr[0]]=true;
        }

        for(int i=1;i<n;i++){
            curr[0]=true;
            for(int j=1;j<=k;j++){
                //same as memoization
                bool nottake = prev[j];
                bool take =false;

                if(j>=arr[i]){
                    take=prev[j-arr[i]];
                }

                curr[j]=(nottake || take);
            }
            prev=curr;
        }
        return prev[k];
    }
};