class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> emptyServer;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        vector<int> cnt(k, 0);
        vector<int> ans;
        
        for(int i=0; i<k; i++) emptyServer.insert(i);
        int i=0;
        while(i < n){
            
            while(!busy.empty() && busy.top().first <= arrival[i]){
                emptyServer.insert(busy.top().second);
                busy.pop();
            }
            if(emptyServer.empty()){
                i++;
                continue;
            }
            int assignServer = i % k;
            auto it = emptyServer.lower_bound(assignServer);
            if(it == emptyServer.end()) it = emptyServer.begin();
            int toAssign = *it;
            cnt[toAssign]++;
            busy.push({arrival[i]+load[i], toAssign});
            emptyServer.erase(it);
            i++;
        }
        int maxUse = *max_element(cnt.begin(), cnt.end());

        for(int i = 0; i < k; i++) {
            if(cnt[i] == maxUse) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};