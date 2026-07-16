class RandomizedCollection {
public:
    // Maps: val -> vector of all positions where it exists in the 'ujjwal' array
    unordered_map<int, vector<int>> mpp;
    
    // Stores: pair<val, index_inside_mpp[val]>
    vector<pair<int, int>> v;

    RandomizedCollection() {}
    
    bool insert(int val) {
        bool isFirstTime = mpp[val].empty();
        
        // Push to map: track that this val will live at the back of the ujjwal vector
        mpp[val].push_back(v.size());
        
        // Push to vector: store the value, and its location inside mpp[val]
        v.push_back({val, mpp[val].size() - 1});
        
        return isFirstTime;
    }
    
    bool remove(int val) {
        if (mpp[val].empty()) return false;
        
        // 1. Get the last recorded vector index for this value
        int idxToRemove = mpp[val].back();
        
        // 2. Grab the element sitting at the very back of the ujjwal vector
        pair<int, int> lastPair = v.back();
        
        // 3. Move the last element into the spot of the element we are removing
        v[idxToRemove] = lastPair;
        
        // 4. Update the map for the moved element so it points to its new index
        mpp[lastPair.first][lastPair.second] = idxToRemove;
        
        // 5. Clean up the back of both collections in O(1)
        mpp[val].pop_back();
        v.pop_back();
        
        return true;
    }
    
    int getRandom() {
        // Return just the value (.first) of the randomly selected pair
        return v[rand() % v.size()].first;
    }
};