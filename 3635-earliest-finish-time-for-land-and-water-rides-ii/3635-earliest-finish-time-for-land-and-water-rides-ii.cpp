class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        long long minLandFinish = LLONG_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minLandFinish = min(
                minLandFinish,
                (long long)landStartTime[i] + landDuration[i]
            );
        }

        long long minWaterFinish = LLONG_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            minWaterFinish = min(
                minWaterFinish,
                (long long)waterStartTime[j] + waterDuration[j]
            );
        }

        long long ans = LLONG_MAX;

        // Land -> Water
        for (int j = 0; j < waterStartTime.size(); j++) {
            long long startSecond =
                (minLandFinish <= waterStartTime[j])
                    ? waterStartTime[j]
                    : minLandFinish;

            ans = min(ans, startSecond + waterDuration[j]);
        }

        // Water -> Land
        for (int i = 0; i < landStartTime.size(); i++) {
            long long startSecond =
                (minWaterFinish <= landStartTime[i])
                    ? landStartTime[i]
                    : minWaterFinish;

            ans = min(ans, startSecond + landDuration[i]);
        }

        return (int)ans;
    }
};