class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;

        double diff = abs(minuteAngle - hourAngle);

        double result = min(diff, 360-diff);

        return result;
    }
};