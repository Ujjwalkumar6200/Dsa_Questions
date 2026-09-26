class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        string now = "";
        unordered_map<string,string> mpp;
        for(int i =0;i<knowledge.size();i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }


        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                i++;
                now = "";

                while (s[i] != ')') {
                    now += s[i];
                    i++;
                }
                if(mpp.find(now)!=mpp.end()) ans+=mpp[now];
                else ans+='?';

            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};