class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int n = startTime.size(), ans = 0;
        string temp1 = "", temp2 = "";
        int multiply = 3600;

        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 != 0) {
                temp1.push_back(startTime[i]);
                temp2.push_back(endTime[i]);
            } else {
                int num1 = stoi(temp1);
                int num2 = stoi(temp2);

                ans += multiply * (num2 - num1);

                multiply /= 60;
                temp1 = "";
                temp2 = "";
            }
        }

        int num1 = stoi(temp1);
        int num2 = stoi(temp2);
        ans += multiply * (num2 - num1);

        return ans;
    }
};