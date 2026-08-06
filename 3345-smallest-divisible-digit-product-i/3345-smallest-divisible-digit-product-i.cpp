class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<110;i++){
            int pr=1;
            int num=i;
            while(num>0){
                int dig=num%10;
                pr*=dig;
                num/=10;
            }
            if(pr%t==0){
                return i;
            }
        }
        return 111;
    }
};