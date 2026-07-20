class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }
         vector<int> indegree(numCourses);
            for(int i =0;i<numCourses;i++){
                for(auto it:adj[i]){
                    indegree[it]++;
                }
            }

            queue<int>q;
            for(int i =0;i<numCourses;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            int cnt =0;

            while(!q.empty()){
                auto node = q.front();
                q.pop();

                for(auto & it : adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                } cnt++;
            } if(cnt==numCourses) return true;
            else return false;
    }
};