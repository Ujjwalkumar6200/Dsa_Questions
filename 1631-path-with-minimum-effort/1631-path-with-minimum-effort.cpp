class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        distance[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] ={-1,0,1,0};
        int dc[] ={0,1,0,-1};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col =  pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();
             
             if(row==n-1 && col == m-1) return dist;

            for(int i =0;i<4;i++){
                int newr = row+dr[i];
                int newc = col+dc[i];
                if(newr>=0 && newc>=0  && newr<n && newc<m){
                    int mineffort = max(abs(heights[row][col]-heights[newr][newc]),dist);
                    if(mineffort < distance[newr][newc]){
                    distance[newr][newc] = mineffort;
                    pq.push({mineffort,{newr,newc}});
                    }
                }
            }
        } return 0;   
    }
};