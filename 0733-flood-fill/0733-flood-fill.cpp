class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int original = image[sr][sc];
        if(original == color)
            return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]= color;
        int dr[]={+1,0,-1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            image[r][c]= color;

            for(int i =0;i<4;i++){
                int newr = r+dr[i];
                int newc = c+dc[i];

                if(newr>=0 && newc>=0 && newr<n && newc<m &&  image[newr][newc] == original){
                   image[newr][newc] == original;
                   q.push({newr,newc});
                }
            }
        } return image;
    }
};