class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char,int> b)
    {
        return a.second > b.second;
    }

    string frequencySort(string s) {
       unordered_map<char, int> mp;
        for(auto it : s){
            mp[it]++;
        }

        vector<pair<char, int>> v;
        for(auto x : mp){
            v.push_back(x);
        }

        sort(v.begin(), v.end(), cmp);

        string ans = "";
        for(auto it : v){
            ans += string(it.second, it.first);
        }

        return ans;
    }
};