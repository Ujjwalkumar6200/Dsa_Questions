class RandomizedSet {
public:

    vector<int>v;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(v.size()==0){
            v.push_back(val);
            return true;
        }

        for(int i =0;i<v.size();i++){
            if(v[i]== val) return false;
        } v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(v.size()==0) return false;
        for(int i =0;i<v.size();i++){
            if(v[i]==val){
                 v.erase(v.begin()+i);
                return true;
            }
        }
        return false;
        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */