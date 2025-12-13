class Solution {
public:

    bool isValidBusinessLine(const string& line) {
        static unordered_set<string> allowed = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };
        return allowed.count(line) > 0;
    }

    bool isValidCode(const string& code) {
        if (code.empty()) return false;

        for (char c : code) {
            if (!(isalnum(c) || c == '_')) {
                return false;
            }
        }
        return true;
    }



    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        int n = code.size();

        /* Business line priority */
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        vector<pair<int, string>> validCoupons;

        for(int i=0; i<n; i++){
            if (!isActive[i]) continue;

            if (!isValidBusinessLine(businessLine[i])) continue;

            if (!isValidCode(code[i])) continue;

            // passed all checks → keep it
            validCoupons.push_back({priority[businessLine[i]], code[i]});
        }

        sort(validCoupons.begin(), validCoupons.end());
        vector<string> result;
        for(auto &p : validCoupons){
            result.push_back(p.second);
        }

        return result;
    }
};