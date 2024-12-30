int findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int,int>mp;
        for(auto it : a) mp[it]++;
        for(auto it : b) mp[it]++;
        
        return mp.size();
    }
