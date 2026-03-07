class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        unordered_map<int,int> even, odd;

        for(int i=0;i<n;i++){
            if(i%2==0) even[nums[i]]++;
            else odd[nums[i]]++;
        }

        int e1=0,e2=0, e1v=0,e2v=0;
        int o1=0,o2=0, o1v=0,o2v=0;

        for(auto &p:even){
            if(p.second>e1){
                e2=e1; e2v=e1v;
                e1=p.second; e1v=p.first;
            }
            else if(p.second>e2){
                e2=p.second; e2v=p.first;
            }
        }

        for(auto &p:odd){
            if(p.second>o1){
                o2=o1; o2v=o1v;
                o1=p.second; o1v=p.first;
            }
            else if(p.second>o2){
                o2=p.second; o2v=p.first;
            }
        }

        if(e1v!=o1v)
            return n - e1 - o1;

        return min(n - e1 - o2, n - e2 - o1);
    }
};