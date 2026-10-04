class Solution {
public:
    bool checkValidString(string s) {
        int minm=0,maxm=0;
        for(auto it:s){
            if(it=='('){maxm++;minm++;}
            else if(it==')'){
                maxm--;
                if(maxm<0)return 0;
                minm=max(minm-1,0);
            }
            else{
                maxm+=1;
                minm=max(0,minm-1);
            }
        }
        if(minm==0)return 1;
        return 0;
    }
};