class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

       
        vector<int> suff(m + 1, n);
        int j = m - 1;
        for(int i = n - 1; i >= 0 && j >= 0; i--){
            if(word1[i] == word2[j]){
                suff[j] = i;
                j--;
            }
        }

        vector<int> res;
        j = 0;
        bool changed = false;

        for(int i = 0; i < n && j < m; i++){
          
            if(word1[i] == word2[j]){
                res.push_back(i);
                j++;
            }
            else if(!changed){
                if(j + 1 == m || (suff[j + 1] != n && suff[j + 1] > i)){
                    res.push_back(i);
                    j++;
                    changed = true;
                }
            }
        }

        if(res.size() == m)
            return res;
        
        return {};
    }
};