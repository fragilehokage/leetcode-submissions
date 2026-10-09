class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int lc=0;
        // int rc=0;
        int sc=0;
        bool fl=false;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                lc++;
            }else{
                if(i<n-1 && s[i+1]==')'){
                    i++;
                }else{
                    sc++;
                }
                if(lc>0){
                    lc--;
                }else{
                    sc++;
                }
                
            }
            
        }
        
            return 2*lc+sc;
        
    }
};